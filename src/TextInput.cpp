#include "CX/TextInput/TextInput.hpp"

#include "CX/EventHandler/EventHandler.hpp"

namespace cx
{
   // Set default styles

   std::unique_ptr<TextInputStyle> TextInputStyle::style1_t;
   std::unique_ptr<TextInputStyle> TextInputStyle::style2_t;
   std::unique_ptr<TextInputStyle> TextInputStyle::style3_t;

   // Constructors

   TextInput::TextInput()
   {
      text.setOutlineColor(Color(0));
      rect.setOutlineColor(Color(0));
   }

   TextInput::TextInput(const TextInputStyle& style,
                        const std::string& string)
   {
      if (style.font->getInfo().family.empty())
         throw std::runtime_error(errors::text::invalid_font);

      text.setString(string);
      text.setFont(*style.font);
      text.setCharacterSize(style.char_size);
      text.setFillColor(style.text_color);
      text.setOutlineThickness(style.text_outline_thickness);
      text.setOutlineColor(style.text_outline_color);
      hidden = string;

      rect.setSize(style.size);
      rect.setTexture(style.texture.get());
      rect.setFillColor(style.color);
      rect.setOutlineThickness(style.outline_thickness);
      rect.setOutlineColor(style.outline_color);

      rect.setOrigin(style.size * .5f);
      recenter();
      text.setPosition(rect.getPosition());
   }

   TextInput::TextInput(const std::string& string,
                        const sf::Font& font,
                        const Vec2f& size,
                        const Vec2f& position,
                        unsigned char_size)
   {
      if (font.getInfo().family.empty())
         throw std::runtime_error(errors::text::invalid_font);

      text.setString(string);
      text.setFont(font);
      text.setCharacterSize(char_size);
      text.setOutlineColor(Color(0));
      hidden = string;

      rect.setPosition(position);
      rect.setSize(size);
      rect.setOutlineColor(Color(0));

      rect.setOrigin(size * .5f);
      recenter();
      text.setPosition(rect.getPosition());
   }

   // Constructors after creation

   void TextInput::create(const TextInputStyle& style,
                          const std::string& string)
   {
      if (style.font->getInfo().family.empty())
         throw std::runtime_error(errors::text::invalid_font);

      text.setString(string);
      text.setFont(*style.font);
      text.setCharacterSize(style.char_size);
      text.setFillColor(style.text_color);
      text.setOutlineThickness(style.text_outline_thickness);
      text.setOutlineColor(style.text_outline_color);
      hidden = string;

      rect.setSize(style.size);
      rect.setTexture(style.texture.get());
      rect.setFillColor(style.color);
      rect.setOutlineThickness(style.outline_thickness);
      rect.setOutlineColor(style.outline_color);

      rect.setOrigin(style.size * .5f);
      recenter();
      text.setPosition(rect.getPosition());
   }

   void TextInput::create(const std::string& string,
                          const sf::Font& font,
                          const Vec2f& size,
                          const Vec2f& position,
                          unsigned char_size)
   {
      if (font.getInfo().family.empty())
         throw std::runtime_error(errors::text::invalid_font);

      text.setString(string);
      text.setFont(font);
      text.setCharacterSize(char_size);
      text.setOutlineColor(Color(0));
      hidden = string;

      rect.setPosition(position);
      rect.setSize(size);
      rect.setOutlineColor(Color(0));

      rect.setOrigin(size * .5f);
      recenter();
      text.setPosition(rect.getPosition());
   }

   // Setter functions

   void TextInput::set_center(const Vec2f& position)
   {
      rect.setPosition(position);
      text.setPosition(position);
   }

   void TextInput::set_top_left(const Vec2f& position)
   {
      rect.setPosition(position + rect.getOrigin());
      text.setPosition(rect.getPosition());
   }

   void TextInput::set_bottom_right(const Vec2f& position)
   {
      rect.setPosition(position - rect.getOrigin());
      text.setPosition(rect.getPosition());
   }

   void TextInput::set_scale(const Vec2f& scale)
   {
      rect.setScale(scale);
      text.setScale(scale);
   }

   void TextInput::set_size(const Vec2f& size)
   {
      rect.setSize(size);
      rect.setOrigin(size * .5f);
      text.setPosition(rect.getPosition());
   }

   void TextInput::set_rotation(float angle)
   {
      rect.setRotation(angle);
      text.setRotation(angle);
   }

   void TextInput::set_texture(const sf::Texture* texture)
   {
      rect.setTexture(texture);
   }

   void TextInput::set_texture_rect(const Vec4i& texture_rect)
   {
      rect.setTextureRect(texture_rect);
   }

   void TextInput::set_color(const Color& color)
   {
      rect.setFillColor(color);
   }

   void TextInput::set_outline_color(const Color& color)
   {
      rect.setOutlineColor(color);
   }

   void TextInput::set_outline_thickness(float thickness)
   {
      rect.setOutlineThickness(thickness);
   }

   void TextInput::set_string(const std::string& string)
   {
      hidden = string;
      if (!input_active)
      {
         text.setString(string);
         recenter();
      }
   }

   void TextInput::set_input(const std::string& string)
   {
      input = string;
      if (input_active)
      {
         text.setString(string);
         recenter();
      }
   }

   void TextInput::set_font(const sf::Font& font)
   {
      if (font.getInfo().family.empty())
         throw std::runtime_error(errors::text::invalid_font);

      text.setFont(font);
      recenter();
   }

   void TextInput::set_char_size(unsigned char_size)
   {
      text.setCharacterSize(char_size);
      recenter();
   }

   void TextInput::set_style(FontStyle style)
   {
      text.setStyle(static_cast<sf::Text::Style>(style));
      recenter();
   }

   void TextInput::set_text_color(const Color& color)
   {
      text.setFillColor(color);
   }

   void TextInput::set_text_outline_color(const Color& color)
   {
      text.setOutlineColor(color);
   }

   void TextInput::set_text_outline_thickness(float thickness)
   {
      text.setOutlineThickness(thickness);
   }

   void TextInput::set_disabled(bool disabled)
   {
      input_disabled = disabled;
   }

   void TextInput::toggle_disabled()
   {
      input_disabled = !input_disabled;
   }

   void TextInput::set_active(bool active)
   {
      input_active = active;
   }

   void TextInput::toggle_active()
   {
      input_active = !input_active;
   }

   void TextInput::set_clear_on_enter(bool clear)
   {
      clear_on_enter = clear;
   }

   void TextInput::set_maximum_char_count(unsigned char_count)
   {
      max_char_count = char_count;
   }

   void TextInput::set_enter_key(Key key)
   {
      enter_key = key;
   }

   void TextInput::set_controller_enter_key(Controller key)
   {
      enter_btn = key;
   }

   void TextInput::set_enter_keys(Key key1, Controller key2)
   {
      enter_key = key1;
      enter_btn = key2;
   }

   // Getter functions

   ElementType TextInput::get_element_type() const
   {
      return ElementType::textInput;
   }

   Vec2f TextInput::get_center() const
   {
      return rect.getPosition();
   }

   Vec2f TextInput::get_top_left() const
   {
      return rect.getPosition() - rect.getOrigin();
   }

   Vec2f TextInput::get_bottom_right() const
   {
      return rect.getPosition() + rect.getOrigin();
   }

   Vec2f TextInput::get_scale() const
   {
      return rect.getScale();
   }

   Vec2f TextInput::get_size() const
   {
      return rect.getSize();
   }

   Vec2f TextInput::get_origin() const
   {
      return rect.getOrigin();
   }

   Degrees TextInput::get_rotation() const
   {
      return rect.getRotation();
   }

   const sf::Texture* TextInput::get_texture() const
   {
      return rect.getTexture();
   }

   Vec4i TextInput::get_texture_rect() const
   {
      return rect.getTextureRect();
   }

   Color TextInput::get_color() const
   {
      return rect.getFillColor();
   }

   Color TextInput::get_outline_color() const
   {
      return rect.getOutlineColor();
   }

   float TextInput::get_outline_thickness() const
   {
      return rect.getOutlineThickness();
   }

   const std::string& TextInput::get_string() const
   {
      return hidden;
   }

   const std::string& TextInput::get_input() const
   {
      return input;
   }

   const sf::Font& TextInput::get_font() const
   {
      return *text.getFont();
   }

   unsigned TextInput::get_char_size() const
   {
      return text.getCharacterSize();
   }

   FontStyle TextInput::get_text_style() const
   {
      return static_cast<FontStyle>(text.getStyle());
   }

   Color TextInput::get_text_color() const
   {
      return text.getFillColor();
   }

   Color TextInput::get_text_outline_color() const
   {
      return text.getOutlineColor();
   }

   float TextInput::get_text_outline_thickness() const
   {
      return text.getOutlineThickness();
   }

   bool TextInput::is_disabled() const
   {
      return input_disabled;
   }

   bool TextInput::is_active() const
   {
      return input_active;
   }

   bool TextInput::active_ended() const
   {
      return was_input_active && !input_active;
   }

   bool TextInput::active_started() const
   {
      return !was_input_active && input_active;
   }

   bool TextInput::is_cleared_on_enter() const
   {
      return clear_on_enter;
   }

   unsigned TextInput::get_maximum_char_count() const
   {
      return max_char_count;
   }

   Key TextInput::get_enter_key() const
   {
      return enter_key;
   }

   Controller TextInput::get_controller_enter_key() const
   {
      return enter_btn;
   }

   // Update functions

   void TextInput::update(const MouseState& state, bool local)
   {
      const auto& en = !input_disabled;
      const MouseState new_state {state.button, state.position, state.is_pressed && en, state.is_released && en, state.is_down && en};
      update_state(new_state, local);
   }

   void TextInput::update_input(const EventHandler& event, bool local)
   {
      update(event.get_mouse_state(Mouse::left), local);
      was_input_active = input_active && !input_disabled;

      if (mouse_up && hovering)
         input_active = !input_disabled;
      else if (event.is_released(Mouse::left) || event.is_released(enter_key, enter_btn))
         input_active = false;

      if (input_active && event.is_typing())
      {
         char ch = event.get_typed_char();

         if ((ch == 8 || ch == 127) && input.size() > 0)
            input.pop_back();
         else if (ch != 8 && ch != 127 && input.size() < max_char_count)
            input += event.get_typed_char();

         text.setString(input);
         recenter();
      }

      if (was_input_active && !input_active)
      {
         if (input == "")
            text.setString(hidden);
      }

      if (!was_input_active && input_active)
      {
         if (clear_on_enter)
         {
            input = "";
            text.setString("");
         }
      }
   }

   // Render functions

   void TextInput::render(sf::RenderWindow& window) const
   {
      window.draw(rect);
      window.draw(text);
   }

   void TextInput::render(sf::RenderWindow& window, const sf::Shader* shader) const
   {
      window.draw(rect, shader);
      window.draw(text, shader);
   }

   // Access functions

   sf::RectangleShape& TextInput::get_background()
   {
      return rect;
   }

   sf::Text& TextInput::get_text()
   {
      return text;
   }

   // Private functions

   void TextInput::recenter()
   {
      text.setOrigin(text.getLocalBounds().getSize() / 2.f + text.getLocalBounds().getPosition());
   }
}
