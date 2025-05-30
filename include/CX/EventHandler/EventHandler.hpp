#ifndef CX_EVENTHANDLER_EVENTHANDLER_HPP
#define CX_EVENTHANDLER_EVENTHANDLER_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include "CX/EventHandler/Controller.hpp"
#include "CX/EventHandler/Keybind.hpp"
#include "CX/EventHandler/Mouse.hpp"
#include "CX/Vector/Vec4.hpp"
#include <bitset>
#include <unordered_map>

namespace cx
{
   /// @brief Manage inputs and events.
   class EventHandler
   {
   public:
      // Constructors

      /// @brief Creates a default event handler.
      /// @param window Window.
      EventHandler(sf::RenderWindow& window);
      ~EventHandler() = default;

      // Update functions

      /// @brief Update event handler.
      void update();

      /// @brief Get delta time.
      /// @return Delta time.
      float get_dt() const;

      // Window functions

      /// @brief Set window top-left position.
      /// @param position New position.
      void set_top_left(const Vec2f& position);

      /// @brief Set window top-left position.
      /// @param left New X position.
      /// @param top New Y position.
      void set_top_left(float left, float top);

      /// @brief Set window top-left position.
      /// @param position New position.
      void set_top_left(float position);

      /// @brief Set window bottom-right position.
      /// @param position New position.
      void set_bottom_right(const Vec2f& position);

      /// @brief Set window bottom-right position.
      /// @param right New right position.
      /// @param bottom New bottom position.
      void set_bottom_right(float right, float bottom);

      /// @brief Set window bottom-right position.
      /// @param position New position.
      void set_bottom_right(float position);

      /// @brief Set window size.
      /// @param size New size.
      void set_size(const Vec2f& size);

      /// @brief Set window size.
      /// @param width New X size.
      /// @param height New Y size.
      void set_size(float width, float height);

      /// @brief Set window size.
      /// @param size New size.
      void set_size(float size);

      /// @brief Get window boundaries.
      /// @return Boundaries.
      Vec4f get_bounds() const;

      /// @brief Get window top-left position.
      /// @return Position.
      Vec2f get_top_left() const;

      /// @brief Get window bottom-right position.
      /// @return Position.
      Vec2f get_bottom_right() const;

      /// @brief Get window left position.
      /// @return X position.
      float get_left() const;

      /// @brief Get window top position.
      /// @return Y position.
      float get_top() const;

      /// @brief Get window right position.
      /// @return Right position.
      float get_right() const;

      /// @brief Get window bottom position.
      /// @return Bottom position.
      float get_bottom() const;

      /// @brief Get window size.
      /// @return Window size.
      Vec2f get_size() const;

      /// @brief Get window width.
      /// @return Window width.
      float get_width() const;

      /// @brief Get window height.
      /// @return Window height.
      float get_height() const;

      /// @brief Get window size center.
      /// @return Size center.
      Vec2f get_center() const;

      /// @brief Get window size center X.
      /// @return Size center X.
      float get_center_x() const;

      /// @brief Get window size center Y.
      /// @return Size center Y.
      float get_center_y() const;

      // Property functions

      /// @brief Check if input can be registered based on window focus for
      /// input property.
      /// @return True if input can be registered.
      bool can_input_be_registered() const;

      /// @brief Set window focus for input property.
      /// @param focus Should window be focused to register input. 
      void set_window_focus_for_input(bool focus);

      /// @brief Get window focus for input property.
      /// @return True if window should be focused to register input.
      bool should_window_focus_for_input() const;

      /// @brief Get character typed by the user.
      /// @return Character typed by user.
      char get_typed_char() const;

      /// @brief Check if user is typing.
      /// @return True if typing.
      bool is_typing() const;

      /// @brief Set mode of the mouse.
      /// @param mode Mode.
      void set_mouse_mode(MouseMode mode);

      /// @brief Get mode of the mouse.
      /// @return Mode.
      MouseMode get_mouse_mode() const;

      /// @brief Get mouse position relative to window.
      /// @return Mouse position.
      Vec2f get_mouse_pos() const;

      /// @brief Set mouse position relative to window.
      /// @param position New position..
      void set_mouse_pos(const Vec2f& position);

      /// @brief Get scroll delta of the mouse.
      /// @return Scroll delta.
      float get_scroll_delta() const;

      /// @brief Get the distance mouse has moved.
      /// @return Mouse delta.
      const Vec2f& get_mouse_delta() const;

      /// @brief Set dead zone of controller.
      /// @param dead_zone Dead zone.
      void set_dead_zone(float dead_zone);

      /// @brief Get dead zone of controller.
      /// @return Dead zone.
      float get_dead_zone() const;

      /// @brief Check if controller is connected.
      /// @return True if connected.
      bool is_controller_connected() const;

      /// @brief Check if controller connected this frame.
      /// @return True if just connected.
      bool did_controller_just_connect() const;

      /// @brief Check if controller disconnected this frame.
      /// @return True if just disconnected.
      bool did_controller_just_disconnect() const;

      // Input pressed functions

      /// @brief Check if key has been pressed.
      /// @param key Key.
      /// @return True if key has been pressed.
      bool is_pressed(Key key) const;

      /// @brief Check if keybind has been pressed.
      /// @param keybind Keybind.
      /// @return True if keybind has been pressed.
      bool is_pressed(const Keybind& keybind) const;

      /// @brief Check if mouse button has been pressed.
      /// @param button Button.
      /// @return True if mouse has been released.
      bool is_pressed(Mouse button) const;

      /// @brief Check if controller key has been pressed.
      /// @param key Controller key.
      /// @return True if key has been pressed.
      bool is_pressed(Controller key) const;

      /// @brief Check if input has been pressed.
      /// @param key1 Keyboard key.
      /// @param key2 Controller key.
      /// @return True if either one has been pressed.
      bool is_pressed(Key key1, Controller key2) const; 

      // Input released functions

      /// @brief Check if key has been released.
      /// @param key Key.
      /// @return True if key has been released.
      bool is_released(Key key) const;

      /// @brief Check if keybind has been released.
      /// @param keybind Keybind.
      /// @return True if keybind has been released.
      bool is_released(const Keybind& keybind) const;

      /// @brief Check if mouse button has been released.
      /// @param button Button.
      /// @return True if mouse has been released.
      bool is_released(Mouse button) const;

      /// @brief Check if controller key has been released.
      /// @param key Controller key.
      /// @return True if key has been released.
      bool is_released(Controller key) const;

      /// @brief Check if input has been released.
      /// @param key1 Keyboard key.
      /// @param key2 Controller key.
      /// @return True if either one has been released.
      bool is_released(Key key1, Controller key2) const; 

      // Input down functions

      /// @brief Check if key is down.
      /// @param key Key.
      /// @return True if key is down.
      bool is_down(Key key) const;

      /// @brief Check if key axis is down.
      /// @param key1 Negative key.
      /// @param key2 Positive key.
      /// @return True if one is down.
      bool is_down(Key key1, Key key2) const;

      /// @brief Check if key vector is down.
      /// @param key1 X negative key.
      /// @param key2 X positive key.
      /// @param key3 Y negative key.
      /// @param key4 Y positive key.
      /// @return True if one is down.
      bool is_down(Key key1, Key key2, Key key3, Key key4) const;

      /// @brief Check if keybind is down.
      /// @param keybind Keybind.
      /// @return True if keybind is down.
      bool is_down(const Keybind& keybind) const;

      /// @brief Check if mouse button is down.
      /// @param button Button.
      /// @return True if mouse button is down.
      bool is_down(Mouse button) const;

      /// @brief Check if controller key is down.
      /// @param key Controller key.
      /// @return True if controller key is down.
      bool is_down(Controller key) const;

      /// @brief Check if controller axis is down.
      /// @param key1 Negative key.
      /// @param key2 Positive key.
      /// @return True if controller axis is down.
      bool is_down(Controller key1, Controller key2) const;

      /// @brief Check if controller axis is down.
      /// @param axis Controller axis.
      /// @return True if controller axis is down.
      bool is_down(ControllerAxis axis) const;

      /// @brief Check if controller vector is down.
      /// @param key1 X negative key.
      /// @param key2 X positive key.
      /// @param key3 Y negative key.
      /// @param key4 Y positive key.
      /// @return True if controller vector is down.
      bool is_down(Controller key1, Controller key2, Controller key3, Controller key4) const;

      /// @brief Check if controller vector is down.
      /// @param axis1 X axis.
      /// @param axis2 Y axis.
      /// @return True if controller vector is down.
      bool is_down(ControllerAxis axis1, ControllerAxis axis2) const;

      /// @brief Check if controller vector is down.
      /// @param vector Controller vector.
      /// @return True if controller vector is down.
      bool is_down(ControllerVector vector) const;

      /// @brief Check if input is down.
      /// @param key1 Keyboard key.
      /// @param key2 Controller key.
      /// @return True if either one is down.
      bool is_down(Key key1, Controller key2) const;

      /// @brief Check if input is down.
      /// @param key Keyboard key.
      /// @param axis Controller axis.
      /// @return True if either one is down.
      bool is_down(Key key, ControllerAxis axis) const;

      /// @brief Check if input is down.
      /// @param key Keyboard key.
      /// @param vector Controller vector.
      /// @return True if either one is down.
      bool is_down(Key key, ControllerVector vector) const;

      // Axis functions

      /// @brief Get key axis.
      /// @param key1 Negative key.
      /// @param key2 Positive key.
      /// @return Hold difference.
      float get_axis(Key key1, Key key2) const;

      /// @brief Get controller axis.
      /// @param key1 Negative key.
      /// @param key2 Positive key.
      /// @return Hold difference.
      float get_axis(Controller key1, Controller key2) const;

      /// @brief Get controller axis.
      /// @param axis Axis.
      /// @return Axis value.
      float get_axis(ControllerAxis axis) const;

      /// @brief Get input axis.
      /// @param key1 Negative key.
      /// @param key2 Positive key.
      /// @param axis Controller axis.
      /// @return Axis value.
      float get_axis(Key key1, Key key2, ControllerAxis axis) const;

      /// @brief Get input axis.
      /// @param key1 Negative key.
      /// @param key2 Positive key.
      /// @param key3 Negative key.
      /// @param key4 Negative key.
      /// @return Axis value.
      float get_axis(Key key1, Key key2, Controller key3, Controller key4) const;

      // Vector functions

      /// @brief Get key vector.
      /// @param key1 X negative key.
      /// @param key2 X positive key.
      /// @param key3 Y negative key.
      /// @param key4 Y positive key.
      /// @return Hold difference.
      Vec2f get_vector(Key key1, Key key2, Key key3, Key key4) const;

      /// @brief Get controller vector.
      /// @param key1 X negative key.
      /// @param key2 X positive key.
      /// @param key3 Y negative key.
      /// @param key4 Y positive key.
      /// @return Hold difference.
      Vec2f get_vector(Controller key1, Controller key2, Controller key3, Controller key4) const;
      
      /// @brief Get controller vector.
      /// @param axis1 X axis.
      /// @param axis2 Y axis.
      /// @return Axis values.
      Vec2f get_vector(ControllerAxis axis1, ControllerAxis axis2) const;

      /// @brief Get controller vector.
      /// @param vector Vector.
      /// @return Axis values.
      Vec2f get_vector(ControllerVector vector) const;

      /// @brief Get input vector.
      /// @param key1 X negative key.
      /// @param key2 X positive key.
      /// @param key3 Y negative key.
      /// @param key4 Y positive key.
      /// @param vector Controller vector.
      /// @return Axis values.
      Vec2f get_vector(Key key1, Key key2, Key key3, Key key4, ControllerVector vector) const;

      /// @brief Get input vector.
      /// @param key1 X negative key.
      /// @param key2 X positive key.
      /// @param key3 Y negative key.
      /// @param key4 Y positive key.
      /// @param key5 X negative key.
      /// @param key6 X positive key.
      /// @param key7 Y negative key.
      /// @param key8 Y positive key.
      /// @return Axis values.
      Vec2f get_vector(Key key1,
                       Key key2,
                       Key key3,
                       Key key4,
                       Controller key5,
                       Controller key6,
                       Controller key7,
                       Controller key8) const;

      // State functions

      /// @brief Get state of a keyboard key.
      /// @param key Key.
      /// @return State of the key.
      KeyState get_key_state(Key key) const;

      /// @brief Get state of a mouse button.
      /// @param button Mouse button.
      /// @return Button state.
      MouseState get_mouse_state(Mouse button) const;

      /// @brief Get state of a controller button.
      /// @param key Controller button.
      /// @return Button state.
      ControllerState get_controller_state(Controller key) const;

   private:
      sf::RenderWindow& window;

      sf::Clock dt_clock;
      MouseMode mouse_mode = MouseMode::free;

      Vec2f last_mouse_pos;
      Vec2f mouse_delta;
      char  typed_char              = {};
      float dt                      = 0.f;
      float scroll_dt               = 0.f;
      float controller_dead_zone    = .1f;
      bool  controller_connected    = false;
      bool  controller_disconnected = false;
      bool  window_focus_for_input  = true;

      std::bitset<size_t(Key::total) + 1>        keys_pressed;
      std::bitset<size_t(Key::total) + 1>        keys_released;
      std::bitset<size_t(Key::total) + 1>        keys_down;
      std::bitset<size_t(Mouse::total) + 1>      mouse_pressed;
      std::bitset<size_t(Mouse::total) + 1>      mouse_released;
      std::bitset<size_t(Mouse::total) + 1>      mouse_down;
      std::bitset<size_t(Controller::total) + 1> controller_pressed;
      std::bitset<size_t(Controller::total) + 1> controller_released;
      std::bitset<size_t(Controller::total) + 1> controller_down;
      std::unordered_map<ControllerAxis, float>  controller_axis;
   };
}

#endif
