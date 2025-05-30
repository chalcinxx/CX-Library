#include "CX/NavigationManager.hpp"

#include "CX/Slider/Slider.hpp"
#include "CX/TextInput/TextInput.hpp"

namespace cx
{
   // Constructors

   NavigationManager::NavigationManager(Key upkey,
                                        Key downkey,
                                        Key leftkey,
                                        Key rightkey,
                                        Key tabkey,
                                        Key enter_key,
                                        Controller upbutton,
                                        Controller downbutton,
                                        Controller leftbutton,
                                        Controller rightbutton,
                                        Controller tabbutton,
                                        Controller enter_button)
      : upkey(upkey), downkey(downkey), leftkey(leftkey), rightkey(rightkey),
      tabkey(tabkey), enter_key(enter_key), upbutton(upbutton), downbutton(downbutton),
      leftbutton(leftbutton), rightbutton(rightbutton), tabbutton(tabbutton),
      enter_button(enter_button) {}
   
   // Constructors after creation

   void NavigationManager::create(Key upkey,
                                  Key downkey,
                                  Key leftkey,
                                  Key rightkey,
                                  Key tabkey,
                                  Key enter_key,
                                  Controller upbutton,
                                  Controller downbutton,
                                  Controller leftbutton,
                                  Controller rightbutton,
                                  Controller tabbutton,
                                  Controller enter_button)
   {
      this->upkey = upkey;
      this->downkey = downkey;
      this->leftkey = leftkey;
      this->rightkey = rightkey;
      this->tabkey = tabkey;
      this->enter_key = enter_key;
      this->upbutton = upbutton;
      this->downbutton = downbutton;
      this->leftbutton = leftbutton;
      this->rightbutton = rightbutton;
      this->tabbutton = tabbutton;
      this->enter_button = enter_button;
   }

   // Setter functions

   void NavigationManager::set_up_key(Key key)
   {
      upkey = key;
   }

   void NavigationManager::set_down_key(Key key)
   {
      downkey = key;
   }

   void NavigationManager::set_left_key(Key key)
   {
      leftkey = key;
   }

   void NavigationManager::set_right_key(Key key)
   {
      rightkey = key;
   }

   void NavigationManager::set_tab_key(Key key)
   {
      tabkey = key;
   }

   void NavigationManager::set_enter_key(Key key)
   {
      enter_key = key;
   }

   void NavigationManager::set_keys(Key upkey,
                                   Key downkey,
                                   Key leftkey,
                                   Key rightkey,
                                   Key tabkey,
                                   Key enter_key)
   {
      this->upkey = upkey;
      this->downkey = downkey;
      this->leftkey = leftkey;
      this->rightkey = rightkey;
      this->tabkey = tabkey;
      this->enter_key = enter_key;
   }

   void NavigationManager::set_up_button(Controller button)
   {
      upbutton = button;
   }

   void NavigationManager::set_down_button(Controller button)
   {
      downbutton = button;
   }

   void NavigationManager::set_left_button(Controller button)
   {
      leftbutton = button;
   }

   void NavigationManager::set_right_button(Controller button)
   {
      rightbutton = button;
   }

   void NavigationManager::set_tab_button(Controller button)
   {
      tabbutton = button;
   }

   void NavigationManager::set_enter_button(Controller button)
   {
      enter_button = button;
   }

   void NavigationManager::set_buttons(Controller upbutton,
                                      Controller downbutton,
                                      Controller leftbutton,
                                      Controller rightbutton,
                                      Controller tabbutton,
                                      Controller enter_button)
   {
      this->upbutton = upbutton;
      this->downbutton = downbutton;
      this->leftbutton = leftbutton;
      this->rightbutton = rightbutton;
      this->tabbutton = tabbutton;
      this->enter_button = enter_button;
   }

   void NavigationManager::set_mouse_button(Mouse mousebutton)
   {
      this->mousebutton = mousebutton;
   }

   void NavigationManager::set_looping(bool loop)
   {
      looping = loop;
   }

   void NavigationManager::set_hold_navigation(bool allow_holding)
   {
      allow_hold = allow_holding;
   }

   void NavigationManager::set_hold_delay(float delay)
   {
      hold_delay = delay;
   }

   void NavigationManager::set_value_hold_delay(float delay)
   {
      hold_value_delay = delay;
   }

   void NavigationManager::set_hold_interval(float interval)
   {
      hold_inter = interval;
   }

   void NavigationManager::set_value_hold_interval(float interval)
   {
      hold_value_inter = interval;
   }

   void NavigationManager::set_selected_index(size_t index)
   {
      cindex = index;
   }

   void NavigationManager::reset_selected_index()
   {
      cindex = 0;
   }

   void NavigationManager::add_element(size_t index, UIElement& element)
   {
      if (elements.contains(index))
         throw std::runtime_error(std::format(errors::navigation::index_taken, index));
      
      elements.insert({index, element});

      if (index > last) last = index;
      if (index < first) first = index;
   }

   void NavigationManager::remove_element(size_t index)
   {
      elements.erase(index);

      if (index == last)
      {
         size_t max = first;

         for (const auto& pair : elements)
            if (pair.first > max) max = pair.first;
         last = max;
      }
      else if (index == first)
      {
         size_t min = last;

         for (const auto& pair : elements)
            if (pair.first < min) min = pair.first;
         first = min;
      }
   }

   void NavigationManager::clear()
   {
      elements.clear();
      last = 0u;
      first = -1u;
      cindex = 0u;
   }

   // Getter functions

   Key NavigationManager::get_up_key() const
   {
      return upkey;
   }

   Key NavigationManager::get_down_key() const
   {
      return downkey;
   }

   Key NavigationManager::get_left_key() const
   {
      return leftkey;
   }

   Key NavigationManager::get_right_key() const
   {
      return rightkey;
   }

   Key NavigationManager::get_tab_key() const
   {
      return tabkey;
   }

   Key NavigationManager::get_enter_key() const
   {
      return enter_key;
   }

   Controller NavigationManager::get_up_button() const
   {
      return upbutton;
   }

   Controller NavigationManager::get_down_button() const
   {
      return downbutton;
   }

   Controller NavigationManager::get_left_button() const
   {
      return leftbutton;
   }

   Controller NavigationManager::get_right_button() const
   {
      return rightbutton;
   }

   Controller NavigationManager::get_tab_button() const
   {
      return tabbutton;
   }

   Controller NavigationManager::get_enter_button() const
   {
      return enter_button;
   }

   Mouse NavigationManager::get_mouse_button() const
   {
      return mousebutton;
   }

   bool NavigationManager::is_looping() const
   {
      return looping;
   }

   bool NavigationManager::is_hold_navigation_enabled() const
   {
      return allow_hold;
   }

   float NavigationManager::get_hold_delay() const
   {
      return hold_delay;
   }

   float NavigationManager::get_value_hold_delay() const
   {
      return hold_value_delay;
   }

   float NavigationManager::get_hold_interval() const
   {
      return hold_inter;
   }

   float NavigationManager::get_value_hold_interval() const
   {
      return hold_value_inter;
   }

   // Access functions

   UIElement& NavigationManager::get_element(size_t index) const
   {
      if (!elements.contains(index) || index == 0)
         throw std::runtime_error(std::format(errors::navigation::invalid_index, index));
      return elements.at(index);
   }

   UIElement& NavigationManager::get_selected_element() const
   {
      if (!elements.contains(cindex))
         throw std::runtime_error(errors::navigation::no_selection);
      return elements.at(cindex);
   }

   bool NavigationManager::is_input_held_down() const
   {
      return holding;
   }
   
   bool NavigationManager::is_selected_clicked() const
   {
      return elements.contains(cindex) && elements.at(cindex).is_clicked();
   }

   bool NavigationManager::is_selected_up() const
   {
      return elements.contains(cindex) && elements.at(cindex).is_mouse_up();
   }

   bool NavigationManager::is_selected_down() const
   {
      return elements.contains(cindex) && elements.at(cindex).is_mouse_down();
   }

   bool NavigationManager::is_selected_hovered_on() const
   {
      return elements.contains(cindex) && elements.at(cindex).is_hovering();
   }

   size_t NavigationManager::get_selected_index() const
   {
      return cindex;
   }

   size_t NavigationManager::get_first_index() const
   {
      return first;
   }

   size_t NavigationManager::get_last_index() const
   {
      return last;
   }

   bool NavigationManager::is_valid_index(size_t index) const
   {
      return elements.contains(index);
   }

   bool NavigationManager::any_selected() const
   {
      return elements.contains(cindex);
   }

   bool NavigationManager::selection_changed() const
   {
      return changed;
   }

   // Update functions

   void NavigationManager::update(const EventHandler& event, bool local)
   {
      const size_t previous = cindex;

      // Hold navigation
      const bool up_down   = (event.is_down(upkey) || event.is_down(upbutton));
      const bool down_down = (event.is_down(downkey) || event.is_down(downbutton));
      const bool tab_down  = (event.is_down(tabkey) || event.is_down(tabbutton));

      bool should_go_up   = (event.is_released(upkey) || event.is_released(upbutton));
      bool should_go_down = (event.is_released(downkey) || event.is_released(downbutton));
      bool should_tab    = (event.is_released(tabkey) || event.is_released(tabbutton));

      if (allow_hold && (up_down || down_down || tab_down))
      {
         if (!holding)
         {
            hold_timer.reset();
            holding = true;
         }
         else if (hold_timer.get_elapsed() >= hold_delay)
         {
            if (interval_timer.get_elapsed() >= hold_inter)
            {
               interval_timer.reset();

               if (up_down)   should_go_up = true;
               if (down_down) should_go_down = true;
               if (tab_down)  should_tab = true;
            }
         }
      }
      else holding = false;

      // Single press navigation
      if (should_go_up)
         cindex = (cindex == first ? (looping ? last : last + 1)
            : (cindex == first - 1 ? last : cindex - 1));

      if (should_go_down)
         cindex = (cindex == last ? (looping ? first : first - 1)
            : (cindex == last + 1 ? first : cindex + 1));

      // Tab navigation
      if (should_tab)
      {
         if (!elements.contains(cindex))
            cindex = first - 1;

         size_t found = first - 1;

         for (const auto& pair : elements)
            if (pair.first > cindex && (found == first - 1 || pair.first < found))
               found = pair.first;
         cindex = (looping && found == first - 1 ? first : found);
      }

      // Hold value navigation
      const bool left_down  = (event.is_down(leftkey) || event.is_down(leftbutton));
      const bool right_down = (event.is_down(rightkey) || event.is_down(rightbutton));

      bool should_go_left  = (event.is_released(leftkey) || event.is_released(leftbutton));
      bool should_go_right = (event.is_released(rightkey) || event.is_released(rightbutton));

      if (left_down || right_down)
      {
         if (!holding_value)
         {
            hold_value_timer.reset();
            holding_value = true;
         }
         else if (hold_value_timer.get_elapsed() >= hold_value_delay)
         {
            if (interval_value_timer.get_elapsed() >= hold_value_inter)
            {
               interval_value_timer.reset();

               if (left_down)  should_go_left = true;
               if (right_down) should_go_right = true;
            }
         }
      }
      else holding_value = false;

      // Single press navigation
      if (should_go_left && elements.contains(cindex))
      {
         if (elements.at(cindex).get_element_type() == ElementType::slider)
         {
            Slider& slider = static_cast<Slider&>(elements.at(cindex));
            slider.decrement_value(slider.get_step());
         }
      }

      if (should_go_right && elements.contains(cindex))
      {
         if (elements.at(cindex).get_element_type() == ElementType::slider)
         {
            Slider& slider = static_cast<Slider&>(elements.at(cindex));
            slider.increment_value(slider.get_step());
         }
      }

      // Update selected UI element
      changed = (previous != cindex);
      MouseState state = event.get_mouse_state(mousebutton);

      if (changed && is_valid_index(previous) && get_element(previous).get_element_type() == ElementType::textInput)
      {
         auto& input = static_cast<TextInput&>(get_element(previous));
         input.set_active(false);
      }

      for (auto& [eIndex, element] : elements)
      {
         if (eIndex != cindex)
         {
            if (element.get_element_type() != ElementType::textInput)
               element.update(state, local);
            else
               (static_cast<TextInput&>(element)).update_input(event, local);
            continue;
         }

         const Vec2f originalPos = state.position;
         const bool originalDown = state.is_down;

         if (element.get_element_type() == ElementType::textInput)
         {
            auto& input = static_cast<TextInput&>(element);
            bool active = input.is_active();
            input.update_input(event, local);

            if (changed)
               input.set_active(true);

            if (event.is_released(enter_key, enter_button) && !active && !input.is_active())
               input.set_active(true);
         }
         else if (element.get_element_type() == ElementType::slider && !element.contains(state.position))
         {
            const auto& slider = static_cast<Slider&>(element);
            state.position = slider.get_knob_center();
         }
         else
         {
            state.is_down = ((event.is_down(enter_key, enter_button)) || ((local
               ? element.get_local_bounds() : element.get_bounds()).contains
               (state.position) && state.is_down));
            state.position = element.get_center();
         }

         if (element.get_element_type() != ElementType::textInput)
            element.update(state, local);

         state.position = originalPos;
         state.is_down = originalDown;
      }
   }

   // Render functions

   void NavigationManager::render(sf::RenderWindow& window) const
   {
      for (const auto& [_, element] : elements)
         element.render(window);
   }

   void NavigationManager::render(sf::RenderWindow& window, const sf::Shader* shader) const
   {
      for (const auto& [_, element] : elements)
         element.render(window, shader);
   }

   // Access

   std::unordered_map<size_t, UIElement&>& NavigationManager::get_elements()
   {
      return elements;
   }
}
