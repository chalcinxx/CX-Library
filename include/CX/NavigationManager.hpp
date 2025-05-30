#ifndef CX_NAVIGATION_MANAGER_HPP
#define CX_NAVIGATION_MANAGER_HPP

#include "CX/EventHandler/EventHandler.hpp"
#include "CX/Timer/BasicTimer.hpp"
#include "CX/UIElement/UIElement.hpp"

namespace cx
{
   /// @brief Enable navigation for elements.
   class NavigationManager
   {
   public:
      // Constructors

      /// @brief Create a default navigation manager.
      /// @param upkey Key to go up.
      /// @param downkey Key to go down.
      /// @param leftkey Key to change values to the left.
      /// @param rightkey Key to change values to the right.
      /// @param tabkey Key to go to nearest.
      /// @param enter_key Key to accept.
      /// @param upbutton Button to go up.
      /// @param downbutton Button to go down.
      /// @param leftbutton Button to change values to the left.
      /// @param rightbutton Button to change values to the right.
      /// @param tabbutton Button to go to nearest.
      /// @param enter_button Button to accept.
      NavigationManager(Key upkey = Key::up,
                        Key downkey = Key::down,
                        Key leftkey = Key::left,
                        Key rightkey = Key::right,
                        Key tabkey = Key::tab,
                        Key enter_key = Key::enter,
                        Controller upbutton = Controller::up,
                        Controller downbutton = Controller::down,
                        Controller leftbutton = Controller::left,
                        Controller rightbutton = Controller::right,
                        Controller tabbutton = Controller::menu,
                        Controller enter_button = Controller::a);
      ~NavigationManager() = default;

      // Constructors after creation

      /// @brief Create a default navigation manager.
      /// @param upkey Key to go up.
      /// @param downkey Key to go down.
      /// @param leftkey Key to change values to the left.
      /// @param rightkey Key to change values to the right.
      /// @param tabkey Key to go to nearest.
      /// @param enter_key Key to accept.
      /// @param upbutton Button to go up.
      /// @param downbutton Button to go down.
      /// @param leftbutton Button to change values to the left.
      /// @param rightbutton Button to change values to the right.
      /// @param tabbutton Button to go to nearest.
      /// @param enter_button Button to accept.
      void create(Key upkey = Key::up,
                  Key downkey = Key::down,
                  Key leftkey = Key::left,
                  Key rightkey = Key::right,
                  Key tabkey = Key::tab,
                  Key enter_key = Key::enter,
                  Controller upbutton = Controller::up,
                  Controller downbutton = Controller::down,
                  Controller leftbutton = Controller::left,
                  Controller rightbutton = Controller::right,
                  Controller tabbutton = Controller::menu,
                  Controller enter_button = Controller::a);

      // Setter functions

      /// @brief Set up key.
      /// @param key Key.
      void set_up_key(Key key);

      /// @brief Set down key.
      /// @param key Key.
      void set_down_key(Key key);

      /// @brief Set left key.
      /// @param key Key.
      void set_left_key(Key key);

      /// @brief Set right key.
      /// @param key Key.
      void set_right_key(Key key);

      /// @brief Set tab key.
      /// @param key Key.
      void set_tab_key(Key key);

      /// @brief Set enter key.
      /// @param key Key.
      void set_enter_key(Key key);

      /// @brief Set keyboard keys.
      /// @param upkey Key to go up.
      /// @param downkey Key to go down.
      /// @param leftkey Key to change values to the left.
      /// @param rightkey Key to change values to the right.
      /// @param tabkey Key to go to nearest.
      /// @param enter_key Key to accept.
      void set_keys(Key upkey = Key::up,
                    Key downkey = Key::down,
                    Key leftkey = Key::left,
                    Key rightkey = Key::right,
                    Key tabkey = Key::tab,
                    Key enter_key = Key::enter);

      /// @brief Set controller up button.
      /// @param button Button.
      void set_up_button(Controller button);

      /// @brief Set controller down button.
      /// @param button Button.
      void set_down_button(Controller button);

      /// @brief Set controller left button.
      /// @param button Button.
      void set_left_button(Controller button);

      /// @brief Set controller right button.
      /// @param button Button.
      void set_right_button(Controller button);

      /// @brief Set controller tab button.
      /// @param button Button.
      void set_tab_button(Controller button);

      /// @brief Set controller enter button.
      /// @param button Button.
      void set_enter_button(Controller button);

      /// @brief Set controller buttons.
      /// @param upbutton Button to go up.
      /// @param downbutton Button to go down.
      /// @param leftbutton Button to change values to the left.
      /// @param rightbutton Button to change values to the right.
      /// @param tabbutton Button to go ot nearest.
      /// @param enter_button Button to accept.
      void set_buttons(Controller upbutton = Controller::up,
                       Controller downbutton = Controller::down,
                       Controller leftbutton = Controller::left,
                       Controller rightbutton = Controller::right,
                       Controller tabbutton = Controller::menu,
                       Controller enter_button = Controller::a);
      
      /// @brief Set mouse used for updating.
      /// @param mousebutton Mouse button.
      void set_mouse_button(Mouse mousebutton);

      /// @brief Set looping property.
      /// @param loop Should indexes loop smoothly.
      void set_looping(bool loop);

      /// @brief Set allow hold property.
      /// @param allow_holding Can the keys be held down.
      void set_hold_navigation(bool allow_holding);

      /// @brief Set holding delay.
      /// @param delay Delay.
      void set_hold_delay(float delay);

      /// @brief Set holding delay for values.
      /// @param delay Delay.
      void set_value_hold_delay(float delay);

      /// @brief Set holding interval.
      /// @param interval Time between press while holding.
      void set_hold_interval(float interval);

      /// @brief Set holding interval for values.
      /// @param interval Time between press while holding.
      void set_value_hold_interval(float interval);

      /// @brief Set current index.
      /// @param index New index.
      void set_selected_index(size_t index);

      /// @brief Reset current index to zero.
      void reset_selected_index();

      /// @brief Insert an element into the list.
      /// @param index Index of element.
      /// @param element Element.
      void add_element(size_t index, UIElement& element);

      /// @brief Insert an element. Automatically assigns index.
      /// @param element ELement.
      void add_element(UIElement& element); 

      /// @brief Insert multiple elements at once. Automatically assigns index.
      /// @param args Elements.
      template<typename... Args>
      void add_elements(Args&&... args)
      {
         if (elements.size() <= 0)
            first = 1;

         size_t start = last;
         (elements.insert({++start, std::forward<Args>(args)}), ...);
         last = start;
      }

      /// @brief Remove an element by index.
      /// @param index Index of element.
      void remove_element(size_t index);

      /// @brief Remove all elements.
      void clear();

      // Getter functions

      /// @brief Get up key.
      /// @return Up key.
      Key get_up_key() const;

      /// @brief Get down key.
      /// @return Down key.
      Key get_down_key() const;

      /// @brief Get left key.
      /// @return Left key.
      Key get_left_key() const;

      /// @brief Get right key.
      /// @return Right key.
      Key get_right_key() const;

      /// @brief Get tab key.
      /// @return Tab key.
      Key get_tab_key() const;

      /// @brief Get enter key.
      /// @return Enter key.
      Key get_enter_key() const;

      /// @brief Get up button.
      /// @return Up button.
      Controller get_up_button() const;

      /// @brief Get down button.
      /// @return Down button.
      Controller get_down_button() const;

      /// @brief Get left button.
      /// @return Left button.
      Controller get_left_button() const;

      /// @brief Get right button.
      /// @return Right button/
      Controller get_right_button() const;

      /// @brief Get tab button.
      /// @return Tab button.
      Controller get_tab_button() const;

      /// @brief Get enter button.
      /// @return Enter button.
      Controller get_enter_button() const;

      /// @brief Get mouse button.
      /// @return Mouse button.
      Mouse get_mouse_button() const;

      /// @brief Get looping property.
      /// @return True if looping.
      bool is_looping() const;

      /// @brief Get allow hold property.
      /// @return True if can hold.
      bool is_hold_navigation_enabled() const;

      /// @brief Get hold delay.
      /// @return Hold delay.
      float get_hold_delay() const;

      /// @brief Get hold delay of the values.
      /// @return Hold delay.
      float get_value_hold_delay() const;

      /// @brief Get hold interval.
      /// @return Time between press while holding.
      float get_hold_interval() const;

      /// @brief Get hold interval of the values.
      /// @return Time between press while holding.
      float get_value_hold_interval() const;

      // Access functions

      /// @brief Get element by index.
      /// @return Element.
      UIElement& get_element(size_t index) const;

      /// @brief Get selected element or throw error.
      /// @return Element.
      UIElement& get_selected_element() const;

      /// @brief Check if navigation keys are being held down.
      /// @return True if held down.
      bool is_input_held_down() const;

      /// @brief Check if selected has been clicked on this frame.
      /// @return True if clicked.
      bool is_selected_clicked() const;

      /// @brief Check if mouse has been released on selected.
      /// @return True if released.
      bool is_selected_up() const;

      /// @brief Check if mouse is down on selected.
      /// @return True if down.
      bool is_selected_down() const;

      /// @brief Check if selected is getting hovered on.
      /// @return True if hovered.
      bool is_selected_hovered_on() const;

      /// @brief Get selected index. Will be invalid if none are selected.
      /// @return Selected index.
      size_t get_selected_index() const;

      /// @brief Get first index.
      /// @return First index.
      size_t get_first_index() const;

      /// @brief Get last index.
      /// @return Last index.
      size_t get_last_index() const;

      /// @brief Check if index is valid.
      /// @return True if valid.
      bool is_valid_index(size_t index) const;

      /// @brief Check if any element is selected.
      /// @return True if any are selected.
      bool any_selected() const;

      /// @brief Check if selection has changed.
      /// @return True if changed.
      bool selection_changed() const;

      // Update functions

      /// @brief Update all of the elements. Must be called after
      /// `eventHandler::update();` 
      /// @param event Event handler.
      /// @param local Should local boundaries be used.
      void update(const EventHandler& event, bool local = false);

      // Render functions

      /// @brief Render all elements.
      /// @param window Window to draw to.
      void render(sf::RenderWindow& window) const;

      /// @brief Render all elements.
      /// @param window Window to draw to.
      void render(sf::RenderWindow& window, const sf::Shader* shader) const;

      // Access functions

      /// @brief Get elements.
      /// @return Elements.
      std::unordered_map<size_t, UIElement&>& get_elements(); 

   private:
      Key upkey     = Key::up;
      Key downkey   = Key::down;
      Key leftkey   = Key::left;
      Key rightkey  = Key::right;
      Key tabkey    = Key::tab;
      Key enter_key = Key::enter;

      Controller upbutton     = Controller::up;
      Controller downbutton   = Controller::down;
      Controller leftbutton   = Controller::left;
      Controller rightbutton  = Controller::right;
      Controller tabbutton    = Controller::menu;
      Controller enter_button = Controller::a;

      Mouse mousebutton = Mouse::left;
      std::unordered_map<size_t, UIElement&> elements;
      BasicTimer hold_timer;
      BasicTimer interval_timer;
      BasicTimer hold_value_timer;
      BasicTimer interval_value_timer;

      size_t cindex          = 0;
      size_t last            = 0;
      size_t first           = -1;
      bool changed           = false;
      bool looping           = true;
      bool allow_hold        = true;
      bool holding           = false;
      bool holding_value     = false;
      float hold_value_delay = .4f;
      float hold_value_inter = .1f;
      float hold_delay       = .4f;
      float hold_inter       = .1f;
   };
}

#endif
