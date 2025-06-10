#include "CX/Button/Button.hpp"

#include <sstream>

namespace cx
{
   // Set default styles

   std::unique_ptr<ButtonStyle> ButtonStyle::style1_t;
   std::unique_ptr<ButtonStyle> ButtonStyle::style2_t;
   std::unique_ptr<ButtonStyle> ButtonStyle::style3_t;

   // Constructors

   Button::Button()
   {
      text.setOutlineColor(Color(0));
   }

   Button::Button(const ButtonStyle& style,
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

      rect.setSize(style.size);
      rect.setTexture(style.texture.get());
      rect.setFillColor(style.color);

      rect.setOrigin(style.size * .5f);
      recenter();
      text.setPosition(rect.getPosition());
   }

   Button::Button(const Color& color,
                  const std::string& string,
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

      rect.setPosition(position);
      rect.setSize(size);
      rect.setFillColor(color);

      rect.setOrigin(size * .5f);
      recenter();
      text.setPosition(rect.getPosition());
   }

   // Constructors after creation

   void Button::create(const ButtonStyle& style,
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

      rect.setSize(style.size);
      rect.setTexture(style.texture.get());
      rect.setFillColor(style.color);

      rect.setOrigin(style.size * .5f);
      recenter();
      text.setPosition(rect.getPosition());
   }

   void Button::create(const Color& color,
                       const std::string& string,
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

      rect.setPosition(position);
      rect.setSize(size);
      rect.setFillColor(color);

      rect.setOrigin(size * .5f);
      recenter();
      text.setPosition(rect.getPosition());
   }

   // Setter functions

   void Button::set_center(const Vec2f& position)
   {
      rect.setPosition(position);
      text.setPosition(position);
   }

   void Button::set_scale(const Vec2f& scale)
   {
      rect.setScale(scale);
      text.setScale(scale);
   }

   void Button::set_size(const Vec2f& size)
   {
      rect.setSize(size);
      rect.setOrigin(size * .5f);
      text.setPosition(rect.getPosition());
   }

   void Button::set_rotation(float angle)
   {
      rect.setRotation(angle);
      text.setRotation(angle);
   }

   void Button::set_texture(const sf::Texture* texture)
   {
      rect.setTexture(texture);
   }

   void Button::set_texture_rect(const Vec4i& texture_rect)
   {
      rect.setTextureRect(texture_rect);
   }

   void Button::set_color(const Color& color)
   {
      rect.setFillColor(color);
   }

   void Button::set_string(const std::string& string)
   {
      text.setString(string);
      recenter();
   }

   void Button::set_font(const sf::Font& font)
   {
      if (font.getInfo().family.empty())
         throw std::runtime_error(errors::text::invalid_font);
      text.setFont(font);
      recenter();
   }

   void Button::set_char_size(unsigned char_size)
   {
      text.setCharacterSize(char_size);
      recenter();
   }

   void Button::set_style(FontStyle style)
   {
      text.setStyle(static_cast<sf::Text::Style>(style));
      recenter();
   }

   void Button::set_text_color(const Color& color)
   {
      text.setFillColor(color);
   }

   void Button::set_text_opacity(unsigned char opacity)
   {
      text.setFillColor(Color(get_text_color(), opacity));
   }

   void Button::set_text_outline_color(const Color& color)
   {
      text.setOutlineColor(color);
   }

   void Button::set_text_outline_thickness(float thickness)
   {
      text.setOutlineThickness(thickness);
   }

   void Button::set_disabled(bool disabled)
   {
      button_disabled = disabled;
   }

   void Button::toggle_disabled()
   {
      button_disabled = !button_disabled;
   }

   // Getter functions

   ElementType Button::get_element_type() const
   {
      return ElementType::button;
   }

   Vec2f Button::get_center() const
   {
      return rect.getPosition();
   }

   Vec2f Button::get_scale() const
   {
      return rect.getScale();
   }

   Vec2f Button::get_size() const
   {
      return get_scale().abs() * rect.getSize();
   }

   Vec2f Button::get_origin() const
   {
      return get_scale().abs() * rect.getOrigin();
   }

   Deg Button::get_rotation() const
   {
      return rect.getRotation();
   }

   const sf::Texture* Button::get_texture() const
   {
      return rect.getTexture();
   }

   Vec4i Button::get_texture_rect() const
   {
      return rect.getTextureRect();
   }

   Color Button::get_color() const
   {
      return rect.getFillColor();
   }

   std::string Button::get_string() const
   {
      return text.getString();
   }

   const sf::Font& Button::get_font() const
   {
      return *text.getFont();
   }

   unsigned Button::get_char_size() const
   {
      return text.getCharacterSize();
   }

   FontStyle Button::get_text_style() const
   {
      return static_cast<FontStyle>(text.getStyle());
   }

   Color Button::get_text_color() const
   {
      return text.getFillColor();
   }

   unsigned char Button::get_text_opacity() const
   {
      return text.getFillColor().a;
   }

   Color Button::get_text_outline_color() const
   {
      return text.getOutlineColor();
   }

   float Button::get_text_outline_thickness() const
   {
      return text.getOutlineThickness();
   }

   bool Button::is_disabled() const
   {
      return button_disabled;
   }

   // Update functions

   void Button::truncate()
   {
      const float max_width {rect.getSize().x};

      if (text.getGlobalBounds().width <= max_width || text.getString().isEmpty())
         return;

      const std::string original {text.getString()};
      std::string_view view (original);

      size_t left {}, right {original.size()};
      std::string_view truncated;

      while (left < right)
      {
         const size_t mid {(left + right) / 2};

         truncated = view.substr(0, mid);
         text.setString(std::string(truncated) + "...");

         if (text.getGlobalBounds().width > max_width)
            right = mid;
         else
            left = mid + 1;
      }
      truncated = view.substr(0, left - 1);
      text.setString(std::string(truncated) + "...");
      recenter();
   }

   void Button::wrap()
   {
      const float max_width {rect.getSize().x};

      if (text.getGlobalBounds().width <= max_width || text.getString().isEmpty())
         return;

      if (max_width <= 3 * text.getFont()->getGlyph('-', text.getCharacterSize(), text.getStyle() == sf::Text::Style::Bold).advance)
      {
         text.setString("...");
         return;
      }

      const std::string original {text.getString()};
      std::string_view view (original), split (original);
      std::stringstream result;

      while (text.getGlobalBounds().width > max_width)
      {
         size_t left {}, right {split.size()};
         std::string_view truncated;

         while (left < right)
         {
            const size_t mid {(left + right) / 2};

            truncated = split.substr(0, mid);
            text.setString(std::string(truncated) + "-");

            if (text.getGlobalBounds().width > max_width)
               right = mid;
            else
               left = mid + 1;
         }

         truncated = split.substr(0, left - 1);
         split = split.substr(left - 1);

         const bool should_break = isalpha(truncated.back()) && isalpha(split.front());
         result << truncated << (should_break ? "-" : "") << "\n";

         text.setString(std::string(split));
         if (text.getGlobalBounds().width <= max_width)
         {
            result << split;
            break;
         }
      }
      text.setString(result.str());
      recenter();
   }

   void Button::fit_inside()
   {
      const Vec2f rect_size (rect.getSize());
      
      if ((text.getGlobalBounds().width <= rect_size.x && text.getGlobalBounds().height <= rect_size.y) || text.getString().isEmpty())
         return;
      
      if (rect_size.x <= 3 * text.getFont()->getGlyph('-', text.getCharacterSize(), text.getStyle() == sf::Text::Style::Bold).advance)
      {
         text.setString("...");
         return;
      }

      if (text.getGlobalBounds().height > rect_size.y)
      {
         truncate();
         return;
      }

      const std::string original {text.getString()};
      std::string_view view (original), split (original);
      std::stringstream result;

      while (text.getGlobalBounds().width > rect_size.x)
      {
         size_t left {}, right {split.size()};
         std::string_view truncated;

         while (left < right)
         {
            const size_t mid {(left + right) / 2};

            truncated = split.substr(0, mid);
            text.setString(std::string(truncated) + "-");

            if (text.getGlobalBounds().width > rect_size.x)
               right = mid;
            else
               left = mid + 1;
         }

         truncated = split.substr(0, left - 1);
         split = split.substr(left - 1);

         text.setString(result.str() + "\n");

         if (text.getGlobalBounds().height > rect_size.y)
         {
            const std::string finalstr {std::string(truncated) + std::string(split)};
            std::string final {finalstr};

            left = 0;
            right = split.size();

            while (left < right)
            {
               const size_t mid {(left + right) / 2};

               final = finalstr.substr(0, mid);
               text.setString(std::string(final) + "...");

               if (text.getGlobalBounds().width > rect_size.x)
                  right = mid;
               else
                  left = mid + 1;
            }

            final = finalstr.substr(0, left - 1);
            result << final << "...";
            break;
         }

         const bool should_break = isalpha(truncated.back()) && isalpha(split.front());
         result << truncated << (should_break ? "-" : "") << "\n";

         text.setString(std::string(split));
         if (text.getGlobalBounds().width <= rect_size.x)
         {
            result << split;
            break;
         }
      }
      text.setString(result.str());
      recenter();
   }

   void Button::update(const MouseState& state, bool local)
   {
      update_state(state, local);
      clicked = clicked && !button_disabled;
      mouse_up = mouse_up && !button_disabled;
      mouse_down = mouse_down && !button_disabled;
   }

   // Render functions

   void Button::render(sf::RenderWindow& window) const
   {
      window.draw(rect);
      window.draw(text);
   }

   void Button::render(sf::RenderWindow& window, const sf::Shader* shader) const
   {
      window.draw(rect, shader);
      window.draw(text, shader);
   }

   // Access functions

   sf::RectangleShape& Button::get_background()
   {
      return rect;
   }

   sf::Text& Button::get_text()
   {
      return text;
   }

   // Private functions

   void Button::recenter()
   {
      text.setOrigin(text.getLocalBounds().getSize() / 2.f + text.getLocalBounds().getPosition());
   }
}
