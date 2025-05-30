#include "CX/EventHandler/EventHandler.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>

namespace cx
{
   // Constructors

   EventHandler::EventHandler(sf::RenderWindow& window)
      : window(window) {}

   // Update functions

   void EventHandler::update()
   {
      dt = dt_clock.restart().asSeconds();

      keys_released.reset();
      keys_pressed.reset();
      mouse_released.reset();
      mouse_pressed.reset();
      controller_released.reset();
      controller_pressed.reset();

      typed_char = {};
      scroll_dt = 0.f;
      controller_connected = controller_disconnected = false;

      // Get mouse delta
      mouse_delta = get_mouse_pos() - last_mouse_pos;

      // Apply mouse mode
      if (mouse_mode == MouseMode::locked)
         sf::Mouse::setPosition(cx::Vec2f(window.getSize()) * .5f, window);

      window.setMouseCursorVisible(mouse_mode != MouseMode::locked);
      window.setMouseCursorGrabbed(mouse_mode != MouseMode::free);

      last_mouse_pos = get_mouse_pos();
      sf::Event temp_event;

      while (window.pollEvent(temp_event))
      {
         // Handle keyboard inputs
         size_t key {static_cast<size_t>(temp_event.key.code)};

         if (key > static_cast<size_t>(Key::total))
            key = static_cast<size_t>(Key::unknown);

         if (temp_event.type == sf::Event::KeyPressed && !keys_down.test(key) && can_input_be_registered())
         {
            keys_pressed.set(key);
            keys_down.set(key);
         }

         if (temp_event.type == sf::Event::KeyReleased)
         {
            if (can_input_be_registered())
               keys_released.set(key);
            keys_down.reset(key);
         }

         // Handle mouse inputs
         size_t mouse {static_cast<size_t>(temp_event.mouseButton.button)};

         if (mouse > static_cast<size_t>(Mouse::total))
            mouse = static_cast<size_t>(Mouse::unknown);

         if (temp_event.type == sf::Event::MouseButtonPressed && !mouse_down.test(mouse) && can_input_be_registered())
         {
            mouse_pressed.set(mouse);
            mouse_down.set(mouse);
         }

         if (temp_event.type == sf::Event::MouseButtonReleased)
         {
            if (can_input_be_registered())
               mouse_released.set(mouse);
            mouse_down.reset(mouse);
         }

         if (temp_event.type == sf::Event::MouseWheelScrolled && can_input_be_registered())
            scroll_dt = temp_event.mouseWheelScroll.delta;
         else if (!can_input_be_registered())
            scroll_dt = 0.f;

         // Handle controller input
         size_t controller {static_cast<size_t>(temp_event.joystickButton.button)};

         if (controller > static_cast<size_t>(Controller::total))
            controller = static_cast<size_t>(Controller::unknown);

         if (temp_event.type == sf::Event::JoystickButtonPressed && !controller_down.test(controller) && can_input_be_registered())
         {
            controller_pressed.set(controller);
            controller_down.set(controller);
         }

         if (temp_event.type == sf::Event::JoystickButtonReleased)
         {
            if (can_input_be_registered())
               controller_released.set(controller);
            controller_down.reset(controller);
         }

         if (temp_event.type == sf::Event::JoystickMoved && can_input_be_registered())
         {
            if (temp_event.joystickMove.axis == sf::Joystick::Axis::R || temp_event.joystickMove.axis == sf::Joystick::Z)
               controller_axis[static_cast<ControllerAxis>(temp_event.joystickMove.axis)] = (temp_event.joystickMove.position * 0.01f + 1.f) / 2.f;
            else
               controller_axis[static_cast<ControllerAxis>(temp_event.joystickMove.axis)] = temp_event.joystickMove.position * 0.01f;
         }
         else if (!can_input_be_registered())
            controller_axis[static_cast<ControllerAxis>(temp_event.joystickMove.axis)] = 0.f;

         if (temp_event.type == sf::Event::JoystickConnected)
            controller_connected = true;

         if (temp_event.type == sf::Event::JoystickDisconnected)
            controller_disconnected = true;

         if (temp_event.type == sf::Event::TextEntered)
            typed_char = temp_event.text.unicode;

         // Close the window
         if (temp_event.type == sf::Event::Closed)
            window.close();
      }

      // Handle Dpad controller keys
      if (!sf::Joystick::isConnected(0))
         return;

      const float xAxis {controller_axis[ControllerAxis::dpad_x]};
      const float yAxis {controller_axis[ControllerAxis::dpad_y]};

      static constexpr size_t left {static_cast<size_t>(Controller::left)};
      static constexpr size_t right{static_cast<size_t>(Controller::right)};
      static constexpr size_t up   {static_cast<size_t>(Controller::up)};
      static constexpr size_t down {static_cast<size_t>(Controller::down)};

      if (xAxis < -controller_dead_zone)
      {
         if (!controller_down.test(left))
         {
            controller_pressed.set(left);
            controller_down.set(left);
         }
      }
      else if (controller_down.test(left))
      {
         controller_released.set(left);
         controller_down.reset(left);
      }

      if (xAxis > controller_dead_zone)
      {
         if (!controller_down.test(right))
         {
            controller_pressed.set(right);
            controller_down.set(right);
         }
      }
      else if (controller_down.test(right))
      {
         controller_released.set(right);
         controller_down.reset(right);
      }

      if (yAxis < -controller_dead_zone)
      {
         if (!controller_down.test(up))
         {
            controller_pressed.set(up);
            controller_down.set(up);
         }
      }
      else if (controller_down.test(up))
      {
         controller_released.set(up);
         controller_down.reset(up);
      }

      if (yAxis > controller_dead_zone)
      {
         if (!controller_down.test(down))
         {
            controller_pressed.set(down);
            controller_down.set(down);
         }
      }
      else if (controller_down.test(down))
      {
         controller_released.set(down);
         controller_down.reset(down);
      }
   }

   float EventHandler::get_dt() const
   {
      return dt;
   }

   // Window functions

   void EventHandler::set_top_left(const Vec2f& position)
   {
      window.setPosition(position);
   }

   void EventHandler::set_top_left(float left, float top)
   {
      window.setPosition(sf::Vector2i(left, top));
   }

   void EventHandler::set_top_left(float position)
   {
      window.setPosition(sf::Vector2i(position, position));
   }

   void EventHandler::set_bottom_right(const Vec2f& position)
   {
      window.setPosition(position - window.getSize());
   }

   void EventHandler::set_bottom_right(float right, float bottom)
   {
      window.setPosition(Vec2f(right, bottom) - window.getSize());
   }

   void EventHandler::set_bottom_right(float position)
   {
      window.setPosition(Vec2f(position, position) - window.getSize());
   }

   void EventHandler::set_size(const Vec2f& size)
   {
      window.setSize(size);
   }

   void EventHandler::set_size(float width, float height)
   {
      window.setSize(sf::Vector2u(width, height));
   }

   void EventHandler::set_size(float size)
   {
      window.setSize(sf::Vector2u(size, size));
   }

   Vec4f EventHandler::get_bounds() const
   {
      return Vec4f(sf::Vector2u(), window.getSize());
   }

   Vec2f EventHandler::get_top_left() const
   {
      return window.getPosition();
   }

   Vec2f EventHandler::get_bottom_right() const
   {
      return window.getPosition() + sf::Vector2i(window.getSize());
   }

   float EventHandler::get_left() const
   {
      return window.getPosition().x;
   } 

   float EventHandler::get_top() const
   {
      return window.getPosition().y;
   }

   float EventHandler::get_right() const
   {
      return window.getPosition().x + window.getSize().x;
   } 

   float EventHandler::get_bottom() const
   {
      return window.getPosition().y + window.getSize().y;
   }

   Vec2f EventHandler::get_size() const
   {
      return window.getSize();
   }

   float EventHandler::get_width() const
   {
      return window.getSize().x;
   }

   float EventHandler::get_height() const
   {
      return window.getSize().y;
   }

   Vec2f EventHandler::get_center() const
   {
      return window.getSize() / 2u;
   }

   float EventHandler::get_center_x() const
   {
      return window.getSize().x / 2.f;
   }

   float EventHandler::get_center_y() const
   {
      return window.getSize().y / 2.f;
   }

   // Property functions

   bool EventHandler::can_input_be_registered() const
   {
      return !window_focus_for_input || (window_focus_for_input && window.hasFocus());
   }

   void EventHandler::set_window_focus_for_input(bool focus)
   {
      window_focus_for_input = focus;
   }

   bool EventHandler::should_window_focus_for_input() const
   {
      return window_focus_for_input;
   }

   char EventHandler::get_typed_char() const
   {
      return typed_char;
   }

   bool EventHandler::is_typing() const
   {
      return typed_char != char{};
   }

   void EventHandler::set_mouse_mode(MouseMode mode)
   {
      mouse_mode = mode;
   }

   MouseMode EventHandler::get_mouse_mode() const
   {
      return mouse_mode;
   }

   Vec2f EventHandler::get_mouse_pos() const
   {
      return sf::Mouse::getPosition(window);
   }

   void EventHandler::set_mouse_pos(const Vec2f& position)
   {
      sf::Mouse::setPosition(position, window);
   }

   float EventHandler::get_scroll_delta() const
   {
      return scroll_dt;
   }

   const cx::Vec2f& EventHandler::get_mouse_delta() const
   {
      return mouse_delta;
   }

   void EventHandler::set_dead_zone(float dead_zone)
   {
      controller_dead_zone = dead_zone;
   }

   float EventHandler::get_dead_zone() const
   {
      return controller_dead_zone;
   }

   bool EventHandler::is_controller_connected() const
   {
      return sf::Joystick::isConnected(0u);
   }

   bool EventHandler::did_controller_just_connect() const
   {
      return controller_connected;
   }

   bool EventHandler::did_controller_just_disconnect() const
   {
      return controller_disconnected;
   }

   // Input pressed functions

   bool EventHandler::is_pressed(Key key) const
   {
      return keys_pressed.test(static_cast<size_t>(key));
   }

   bool EventHandler::is_pressed(const Keybind& keybind) const
   {
      for (const auto& key : keybind.hold_keys)
         if (!is_down(key))
            return false;
      return is_pressed(keybind.key);
   }

   bool EventHandler::is_pressed(Mouse button) const
   {
      return mouse_pressed.test(static_cast<size_t>(button));
   }

   bool EventHandler::is_pressed(Controller key) const
   {
      return controller_pressed.test(static_cast<size_t>(key));
   }

   bool EventHandler::is_pressed(Key key1, Controller key2) const
   {
      return is_pressed(key1) || is_pressed(key2);
   }

   // Input released functions

   bool EventHandler::is_released(Key key) const
   {
      return keys_released.test(static_cast<size_t>(key));
   }

   bool EventHandler::is_released(const Keybind& keybind) const
   {
      for (const auto& key : keybind.hold_keys)
         if (!is_down(key))
            return false;
      return is_released(keybind.key);
   }

   bool EventHandler::is_released(Mouse button) const
   {
      return mouse_released.test(static_cast<size_t>(button));
   }

   bool EventHandler::is_released(Controller key) const
   {
      return controller_released.test(static_cast<size_t>(key));
   }

   bool EventHandler::is_released(Key key1, Controller key2) const
   {
      return is_released(key1) || is_released(key2);
   }

   // Input down functions

   bool EventHandler::is_down(Key key) const
   {
      return keys_down.test(static_cast<size_t>(key));
   }

   bool EventHandler::is_down(Key key1, Key key2) const
   {
      return is_down(key1) || is_down(key2);
   }

   bool EventHandler::is_down(Key key1, Key key2, Key key3, Key key4) const
   {
      return is_down(key1, key2) || is_down(key3, key4);
   }

   bool EventHandler::is_down(const Keybind& keybind) const
   {
      for (const auto& key : keybind.hold_keys)
         if (!is_down(key))
            return false;
      return is_down(keybind.key);
   }

   bool EventHandler::is_down(Mouse button) const
   {
      return mouse_down.test(static_cast<size_t>(button));
   }

   bool EventHandler::is_down(Controller key) const
   {
      return controller_down.test(static_cast<size_t>(key));
   }

   bool EventHandler::is_down(Controller key1, Controller key2) const
   {
      return is_down(key1) || is_down(key2);
   }

   bool EventHandler::is_down(ControllerAxis axis) const
   {
      return controller_axis.contains(axis) && std::abs(controller_axis.at(axis)) > controller_dead_zone;
   }

   bool EventHandler::is_down(Controller key1,
                             Controller key2,
                             Controller key3,
                             Controller key4) const
   {
      return is_down(key1, key2) || is_down(key3, key4);
   }

   bool EventHandler::is_down(ControllerAxis axis1, ControllerAxis axis2) const
   {
      return is_down(axis1) || is_down(axis2);
   }

   bool EventHandler::is_down(ControllerVector vector) const
   {
      switch (vector)
      {
      case ControllerVector::dpad:
         return is_down(ControllerAxis::dpad_x, ControllerAxis::dpad_y);
      case ControllerVector::ls:
         return is_down(ControllerAxis::ls_x, ControllerAxis::ls_y);
      case ControllerVector::rs:
         return is_down(ControllerAxis::rs_x, ControllerAxis::rs_y);
      case ControllerVector::triggers:
         return is_down(ControllerAxis::lt, ControllerAxis::rt);
      default:
         return false;
      }
   }

   bool EventHandler::is_down(Key key1, Controller key2) const
   {
      return is_down(key1) || is_down(key2);
   }

   bool EventHandler::is_down(Key key, ControllerAxis axis) const
   {
      return is_down(key) || is_down(axis);
   }

   bool EventHandler::is_down(Key key, ControllerVector vector) const
   {
      return is_down(key) || is_down(vector);
   }

   // Axis functions

   float EventHandler::get_axis(Key key1, Key key2) const
   {
      return is_down(key1) - is_down(key2);
   }

   float EventHandler::get_axis(Controller key1, Controller key2) const
   {
      return is_down(key1) - is_down(key2);
   }

   float EventHandler::get_axis(ControllerAxis axis) const
   {
      return (controller_axis.contains(axis) && std::abs(controller_axis.at(axis))
         > controller_dead_zone ? controller_axis.at(axis) : 0.f);
   }

   float EventHandler::get_axis(Key key1, Key key2, ControllerAxis axis) const
   {
      const auto axis1 = get_axis(key1, key2);
      return (axis1 == 0.f ? get_axis(axis) : axis1);
   }

   float EventHandler::get_axis(Key key1, Key key2, Controller key3, Controller key4) const
   {
      const auto axis1 = get_axis(key1, key2);
      return (axis1 == 0.f ? get_axis(key3, key4) : axis1);
   }

   // Vector functions

   Vec2f EventHandler::get_vector(Key key1, Key key2, Key key3, Key key4) const
   {
      return {get_axis(key1, key2), get_axis(key3, key4)};
   }

   Vec2f EventHandler::get_vector(Controller key1,
                                 Controller key2,
                                 Controller key3,
                                 Controller key4) const
   {
      return {get_axis(key1, key2), get_axis(key3, key4)};
   }

   Vec2f EventHandler::get_vector(ControllerAxis axis1, ControllerAxis axis2) const
   {
      return {get_axis(axis1), get_axis(axis2)};
   }

   Vec2f EventHandler::get_vector(ControllerVector vector) const
   {
      switch (vector)
      {
      case ControllerVector::dpad:
         return {get_axis(ControllerAxis::dpad_x), get_axis(ControllerAxis::dpad_y)};
      case ControllerVector::ls:
         return {get_axis(ControllerAxis::ls_x), get_axis(ControllerAxis::ls_y)};
      case ControllerVector::rs:
         return {get_axis(ControllerAxis::rs_x), get_axis(ControllerAxis::rs_y)};
      case ControllerVector::triggers:
         return {get_axis(ControllerAxis::lt), get_axis(ControllerAxis::rt)};
      default:
         return 0.f;
      }
   }

   Vec2f EventHandler::get_vector(Key key1, Key key2, Key key3, Key key4, ControllerVector vector) const
   {
      const auto vector1 = get_vector(key1, key2, key3, key4);
      return (vector1.empty() ? get_vector(vector) : vector1);
   }

   Vec2f EventHandler::get_vector(Key key1,
                                  Key key2,
                                  Key key3,
                                  Key key4,
                                  Controller key5,
                                  Controller key6,
                                  Controller key7,
                                  Controller key8) const
   {
      const auto vector1 = get_vector(key1, key2, key3, key4);
      return (vector1.empty() ? get_vector(key5, key6, key7, key8) : vector1);
   }

   // State functions

   KeyState EventHandler::get_key_state(Key key) const
   {
      return {key, is_pressed(key), is_released(key), is_down(key)};
   }

   MouseState EventHandler::get_mouse_state(Mouse button) const
   {
      return {button, get_mouse_pos(), is_pressed(button), is_released(button), is_down(button)};
   }

   ControllerState EventHandler::get_controller_state(Controller key) const
   {
      return {key, is_pressed(key), is_released(key), is_down(key)};
   }
} // namespace cx
