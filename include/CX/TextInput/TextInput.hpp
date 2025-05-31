#ifndef CX_TEXTINPUT_TEXTINPUT_HPP
#define CX_TEXTINPUT_TEXTINPUT_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "CX/EventHandler/Controller.hpp"
#include "CX/EventHandler/Key.hpp"
#include "CX/Text/FontStyle.hpp"
#include "CX/TextInput/TextInputStyle.hpp"
#include "CX/UIElement/UIElement.hpp"

namespace cx
{
   class EventHandler;

   /// @brief Get text input from the user.
   class TextInput : public UIElement
   {
   public:
      // Constructors

      /// @brief Create a default input.
      TextInput();
      ~TextInput() = default;

      /// @brief Create a new input.
      /// @param style Style of the input.
      /// @param string String of the text.
      TextInput(const TextInputStyle& style,
                const std::string& string);

      /// @brief Create a new input.
      /// @param string String of the text.
      /// @param font Font of the text.
      /// @param size Size of the input.
      /// @param position Position of the input.
      /// @param char_size Character size of the input.
      TextInput(const std::string& string,
                const sf::Font& font,
                const Vec2f& size,
                const Vec2f& position = {},
                unsigned char_size = 32);

      // Constructors after creation

      /// @brief Create a new input.
      /// @param style Style of the input.
      /// @param string String of the text.
      void create(const TextInputStyle& style,
                  const std::string& string);

      /// @brief Create a new input.
      /// @param string String of the text.
      /// @param font Font of the text.
      /// @param size Size of the input.
      /// @param position Position of the input.
      /// @param char_size Character size of the input.
      void create(const std::string& string,
                  const sf::Font& font,
                  const Vec2f& size,
                  const Vec2f& position = {},
                  unsigned char_size = 32);

      // Setter functions

      /// @brief Import UIElement functions to not override them.
      using UIElement::set_center;
      using UIElement::set_top_left;
      using UIElement::set_bottom_right;
      using UIElement::set_scale;
      using UIElement::set_size;
      using UIElement::set_rotation;

      /// @brief Change center position of the input.
      /// @param position New center.
      void set_center(const Vec2f& position) override;

      /// @brief Change top-left position of the input.
      /// @param position New position.
      void set_top_left(const Vec2f& position) override;

      /// @brief Change bottom-right position of the input.
      /// @param position New position.
      void set_bottom_right(const Vec2f& position) override;

      /// @brief Change scale of the input.
      /// @param scale New scale.
      void set_scale(const Vec2f& scale) override;

      /// @brief Change size of the input.
      /// @param size New size.
      void set_size(const Vec2f& size) override;

      /// @brief Change rotation of the input.
      /// @param angle New rotation in degrees.
      void set_rotation(float angle) override;

      /// @brief Change texture of the input.
      /// @param texture New texture.
      void set_texture(const sf::Texture* texture);

      /// @brief Change texture rectangle of the input.
      /// @param texture_rect New texture rectangle.
      void set_texture_rect(const Vec4i& texture_rect);

      /// @brief Change color of the input.
      /// @param color New color.
      void set_color(const Color& color) override;

      /// @brief Change outline color of the input.
      /// @param color New color.
      void set_outline_color(const Color& color) override;

      /// @brief Change outline thickness of the input.
      /// @param thickness New thickness.
      void set_outline_thickness(float thickness) override;

      /// @brief Change string of the text.
      /// @param string New string.
      void set_string(const std::string& string);

      /// @brief Change the input.
      /// @param input New input.
      void set_input(const std::string& input);

      /// @brief Change font of the text.
      /// @param font New font.
      void set_font(const sf::Font& font);

      /// @brief Change character size of the text.
      /// @param char_size New character size.
      void set_char_size(unsigned char_size);

      /// @brief Change style of the text.
      /// @param style New style.
      void set_style(FontStyle style);

      /// @brief Change color of the text.
      /// @param color New color.
      void set_text_color(const Color& color);

      /// @brief Change outline color of the text.
      /// @param color New color.
      void set_text_outline_color(const Color& color);

      /// @brief Change outline thickness of the text.
      /// @param thickness New thickness.
      void set_text_outline_thickness(float thickness);

      /// @brief Set the input as disabled or enabled.
      /// @param disabled Should the input be disabled.
      void set_disabled(bool disabled);

      /// @brief Toggle disabled property of the input.
      void toggle_disabled();

      /// @brief Set the input as active or inactive.
      /// @param active Should the input be active.
      void set_active(bool active);

      /// @brief Toggle active property of the input.
      void toggle_active();

      /// @brief Set the clear on enter property of the input.
      /// @param clear Should input be cleared on enter.
      void set_clear_on_enter(bool clear);

      /// @brief Set the maximum character count.
      /// @param char_count Maximum character count.
      void set_maximum_char_count(unsigned char_count);

      /// @brief Set the enter keyboard key.
      /// @param key Key.
      void set_enter_key(Key key);

      /// @brief Set the enter controller key.
      /// @param key Key.
      void set_controller_enter_key(Controller key);

      /// @brief Set the enter keyboard and controller key.
      /// @param key1 Keyboard key.
      /// @param key2 Controller key.
      void set_enter_keys(Key key1, Controller key2);

      // Getter functions

      /// @brief Get input type.
      /// @return Type.
      ElementType get_element_type() const override;

      /// @brief Get center position of the input.
      /// @return Center.
      Vec2f get_center() const override;

      /// @brief Get scale of the input.
      /// @return Scale.
      Vec2f get_scale() const override;

      /// @brief Get size of the input.
      /// @return Size.
      Vec2f get_size() const override;

      /// @brief Get origin of the input.
      /// @return Origin.
      Vec2f get_origin() const override;

      /// @brief Get rotation of the input.
      /// @return Rotation in degrees.
      Deg get_rotation() const override;

      /// @brief Get texture of the input.
      /// @return Texture.
      const sf::Texture* get_texture() const;

      /// @brief Get texture rectangle of the input.
      /// @return Texture rectangle.
      Vec4i get_texture_rect() const;

      /// @brief Get color of the input.
      /// @return Color.
      Color get_color() const override;

      /// @brief Get outline color of the input.
      /// @return Outline color.
      Color get_outline_color() const override;

      /// @brief Get outline thickness of the input.
      /// @return Outline thickness.
      float get_outline_thickness() const override;

      /// @brief Get default text.
      /// @return Default text.
      const std::string& get_string() const;

      /// @brief Get user input.
      /// @return Input.
      const std::string& get_input() const;

      /// @brief Get font of the text.
      /// @return Font.
      const sf::Font& get_font() const;

      /// @brief Get character size of the text.
      /// @return Character size.
      unsigned get_char_size() const;

      /// @brief Get style of the text.
      /// @return Style.
      FontStyle get_text_style() const;

      /// @brief Get color of the text.
      /// @return Color.
      Color get_text_color() const;

      /// @brief Get outline color of the text.
      /// @return Outline color.
      Color get_text_outline_color() const;

      /// @brief Get outline thickness of the text.
      /// @return Outline thickness.
      float get_text_outline_thickness() const;

      /// @brief Get disabled property of the input.
      /// @return Disabled property.
      bool is_disabled() const;

      /// @brief Get active property of the input.
      /// @return True if active.
      bool is_active() const;

      /// @brief Check if selection ended.
      /// @return True if ended.
      bool active_ended() const;

      /// @brief Check if selection started.
      /// @return True if started.
      bool active_started() const;
      
      /// @brief Check if input gets cleared on enter.
      /// @return True if cleared.
      bool is_cleared_on_enter() const;

      /// @brief Get maximum character count.
      /// @return Maximum character count.
      unsigned get_maximum_char_count() const;

      /// @brief Get keyboard enter key.
      /// @return Key.
      Key get_enter_key() const;

      /// @brief Get controller enter key.
      /// @return Key.
      Controller get_controller_enter_key() const; 

      // Update functions

      /// @brief Update input's state and functions.
      /// @param state Mouse state.
      /// @param local Should local boundaries be used.
      void update(const MouseState& state, bool local = false) override;

      /// @brief Update input's user input.
      /// @param event Event handler.
      /// @param local Should local boundaries be used.
      void update_input(const EventHandler& event, bool local = false);

      // Render functions

      /// @brief Render the input.
      /// @param window Window to draw to.
      void render(sf::RenderWindow& window) const override;

      /// @brief Render the input.
      /// @param window Window to draw to.
      /// @param shader Shader.
      void render(sf::RenderWindow& window, const sf::Shader* shader) const override;

   // Access functions

   /// @brief Get background.
   /// @return Background.
   sf::RectangleShape& get_background();

   /// @brief Get text.
   /// @return Text.
   sf::Text& get_text();

   private:
      unsigned max_char_count = 256;
      bool clear_on_enter     = true;
      bool input_disabled     = false;
      bool input_active       = false;
      bool was_input_active   = false;
      std::string input       = "";
      std::string hidden      = "";

      Key enter_key        = Key::enter;
      Controller enter_btn = Controller::a;

      sf::RectangleShape rect;
      sf::Text text;

      /// @brief Recenter the text.
      void recenter();
   };
}

#endif
