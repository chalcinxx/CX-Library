#include "CX/Text/Text.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <sstream>

namespace cx
{
   // Set default styles

   std::unique_ptr<TextStyle> TextStyle::style1_t;
   std::unique_ptr<TextStyle> TextStyle::style2_t;
   std::unique_ptr<TextStyle> TextStyle::style3_t;

   // Constructors

   Text::Text()
   {
      text.setOutlineColor(Color(0));
   }

   Text::Text(const TextStyle& style,
              const std::string& string)
   {
      if (style.font->getInfo().family.empty())
         throw std::runtime_error(errors::text::invalid_font);

      text.setString(string);
      text.setFont(*style.font);
      text.setCharacterSize(style.char_size);
      text.setFillColor(style.text_color);
      text.setOutlineColor(style.outline_color);
      text.setOutlineThickness(style.outline_thickness);

      text.setOrigin(Vec4f(text.getGlobalBounds()).get_center());
   }

   Text::Text(const std::string& string,
              const sf::Font& font,
              const Vec2f& position,
              unsigned char_size,
              float shadow_thickness)
   {
      if (font.getInfo().family.empty())
         throw std::runtime_error(errors::text::invalid_font);

      text.setString(string);
      text.setFont(font);
      text.setCharacterSize(char_size);
      text.setOutlineThickness(shadow_thickness);
      text.setOutlineColor(Color(0));

      text.setOrigin(Vec4f(text.getGlobalBounds()).get_center());
      text.setPosition(position);
   }

   // Constructors after creation.

   void Text::create(const TextStyle& style,
                     const std::string& string)
   {
      if (style.font->getInfo().family.empty())
         throw std::runtime_error(errors::text::invalid_font);

      text.setString(string);
      text.setFont(*style.font);
      text.setCharacterSize(style.char_size);
      text.setFillColor(style.text_color);
      text.setOutlineColor(style.outline_color);
      text.setOutlineThickness(style.outline_thickness);

      text.setOrigin(Vec4f(text.getGlobalBounds()).get_center());
   }

   void Text::create(const std::string& string,
                     const sf::Font& font,
                     const Vec2f& position,
                     unsigned char_size,
                     float shadow_thickness)
   {
      if (font.getInfo().family.empty())
         throw std::runtime_error(errors::text::invalid_font);

      text.setString(string);
      text.setFont(font);
      text.setCharacterSize(char_size);
      text.setOutlineThickness(shadow_thickness);
      text.setOutlineColor(Color(0));

      text.setOrigin(Vec4f(text.getGlobalBounds()).get_center());
      text.setPosition(position);
   }

   // Setter functions

   void Text::set_string(const std::string& string, bool stay_still)
   {
      text.setString(string);

      if (stay_still)
      {
         const Vec2f original = Vec2f(text.getPosition()) - Vec2f(text.getOrigin()) * text.getScale();
         recenter();
         text.setPosition(original + Vec2f(text.getOrigin()) * text.getScale());
      }
      else recenter();
   }

   void Text::set_font(const sf::Font& font)
   {
      if (font.getInfo().family.empty())
         throw std::runtime_error(errors::text::invalid_font);
      text.setFont(font);
      recenter();
   }

   void Text::set_char_size(unsigned char_size)
   {
      text.setCharacterSize(char_size);
      recenter();
   }

   void Text::set_style(FontStyle style)
   {
      text.setStyle(static_cast<sf::Text::Style>(style));
      recenter();
   }

   void Text::set_center(const Vec2f& position)
   {
      text.setPosition(position);
   }

   void Text::set_top_left(const Vec2f& position)
   {
      text.setPosition(position + text.getOrigin());
   }

   void Text::set_bottom_right(const Vec2f& position)
   {
      text.setPosition(position - text.getOrigin());
   }

   void Text::set_scale(const Vec2f& scale)
   {
      text.setScale(scale);
   }

   void Text::set_size(const Vec2f& size)
   {
      text.setScale(size / Vec2f(text.getLocalBounds().getSize()));
   }

   void Text::set_rotation(float angle)
   {
      text.setRotation(angle);
   }

   void Text::set_color(const Color& color)
   {
      text.setFillColor(color);
   }

   void Text::set_outline_color(const Color& color)
   {
      text.setOutlineColor(color);
   }

   void Text::set_outline_thickness(float thickness)
   {
      text.setOutlineThickness(thickness);
   }

   // Text specific functions

   void Text::place_inside(const Vec5f& bounds)
   {
      fit_inside(bounds.get_size());
      text.setPosition(bounds.get_center());
      text.setRotation(bounds.r);
   }

   void Text::place_inside(const Vec4f& bounds)
   {
      fit_inside(bounds.get_size());
      text.setPosition(bounds.get_center());
   }

   void Text::fit_inside(const Vec2f& rectSize)
   {
      if ((get_width() <= rectSize.x && get_height() <= rectSize.y) || text.getString().isEmpty())
         return;
      
      if (rectSize.x <= 3 * text.getFont()->getGlyph('-', text.getCharacterSize(), text.getStyle() == sf::Text::Style::Bold).advance)
      {
         text.setString("...");
         return;
      }

      if (get_height() > rectSize.y)
      {
         truncate(rectSize.x);
         return;
      }

      const std::string original {text.getString()};
      std::string_view view (original), split (original);
      std::stringstream result;

      while (get_width() > rectSize.x)
      {
         size_t left {}, right {split.size()};
         std::string_view truncated;

         while (left < right)
         {
            const size_t mid {(left + right) / 2};

            truncated = split.substr(0, mid);
            text.setString(std::string(truncated) + "-");

            if (get_width() > rectSize.x)
               right = mid;
            else
               left = mid + 1;
         }

         truncated = split.substr(0, left - 1);
         split = split.substr(left - 1);

         text.setString(result.str() + "\n");

         if (text.getGlobalBounds().height > rectSize.y)
         {
            const std::string finalstr = std::string(truncated) + std::string(split);
            std::string final {finalstr};

            left = 0;
            right = split.size();

            while (left < right)
            {
               const size_t mid {(left + right) / 2};

               final = finalstr.substr(0, mid);
               text.setString(std::string(final) + "...");

               if (get_width() > rectSize.x)
                  right = mid;
               else
                  left = mid + 1;
            }

            final = finalstr.substr(0, left - 1);
            result << final << "...";
            break;
         }

         const bool shouldBreak = isalpha(truncated.back()) && isalpha(split.front());
         result << truncated << (shouldBreak ? "-" : "") << "\n";

         text.setString(std::string(split));
         if (get_width() <= rectSize.x)
         {
            result << split;
            break;
         }
      }
      text.setString(result.str());
      recenter();
   }

   void Text::wrap_inside(const Vec5f& bounds)
   {
      wrap(bounds.w);
      text.setPosition(bounds.get_center());
      text.setRotation(bounds.r);
   }

   void Text::wrap_inside(const Vec4f& bounds)
   {
      wrap(bounds.w);
      text.setPosition(bounds.get_center());
   }

   void Text::wrap(float maxWidth)
   {
      if (get_width() <= maxWidth || text.getString().isEmpty())
         return;

      if (maxWidth <= 3 * text.getFont()->getGlyph('-', text.getCharacterSize(), text.getStyle() == sf::Text::Style::Bold).advance)
      {
         text.setString("...");
         return;
      }

      const std::string original {text.getString()};
      std::string_view view (original), split (original);
      std::stringstream result;

      while (get_width() > maxWidth)
      {
         size_t left {}, right {split.size()};
         std::string_view truncated;

         while (left < right)
         {
            const size_t mid {(left + right) / 2};

            truncated = split.substr(0, mid);
            text.setString(std::string(truncated) + "-");

            if (get_width() > maxWidth)
               right = mid;
            else
               left = mid + 1;
         }

         truncated = split.substr(0, left - 1);
         split = split.substr(left - 1);

         const bool shouldBreak = isalpha(truncated.back()) && isalpha(split.front());
         result << truncated << (shouldBreak ? "-" : "") << "\n";

         text.setString(std::string(split));
         if (get_width() <= maxWidth)
         {
            result << split;
            break;
         }
      }
      text.setString(result.str());
      recenter();
   }

   void Text::truncate_inside(const Vec5f& bounds)
   {
      truncate(bounds.w);
      text.setPosition(bounds.get_center());
      text.setRotation(bounds.r);
   }

   void Text::truncate_inside(const Vec4f& bounds)
   {
      truncate(bounds.w);
      text.setPosition(bounds.get_center());  
   }

   void Text::truncate(float maxWidth)
   {
      if (get_width() <= maxWidth || text.getString().isEmpty())
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

         if (text.getGlobalBounds().width > maxWidth)
            right = mid;
         else
            left = mid + 1;
      }
      truncated = view.substr(0, left - 1);
      text.setString(std::string(truncated) + "...");
      recenter();
   }

   // Getter functions

   ElementType Text::get_element_type() const
   {
      return ElementType::text;
   }
   
   std::string Text::get_string() const
   {
      return text.getString();
   }

   const sf::Font& Text::get_font() const
   {
      return *text.getFont();
   }

   unsigned Text::get_char_size() const
   {
      return text.getCharacterSize();
   }

   FontStyle Text::get_style() const
   {
      return static_cast<FontStyle>(text.getStyle());
   }

   Vec2f Text::get_center() const
   {
      return text.getPosition();
   }

   Vec2f Text::get_top_left() const
   {
      return text.getPosition() - text.getOrigin();
   }

   Vec2f Text::get_bottom_right() const
   {
      return text.getPosition() + text.getOrigin();
   }

   Vec2f Text::get_scale() const
   {
      return text.getScale();
   }

   Vec2f Text::get_size() const
   {
      return text.getGlobalBounds().getSize();
   }

   Vec2f Text::get_origin() const
   {
      return text.getOrigin();
   }

   Degrees Text::get_rotation() const
   {
      return text.getRotation();
   }

   Color Text::get_color() const
   {
      return text.getFillColor();
   }

   Color Text::get_outline_color() const
   {
      return text.getOutlineColor();
   }

   float Text::get_outline_thickness() const
   {
      return text.getOutlineThickness();
   }

   // Update functions

   void Text::update(const MouseState& state, bool local)
   {
      update_state(state, local);
   }

   // Render functions
   
   void Text::render(sf::RenderWindow& window) const
   {
      window.draw(text);
   }

   void Text::render(sf::RenderWindow& window,
                     const sf::Shader* shader) const
   {
      window.draw(text, shader);
   }

   // Access functions

   sf::Text& Text::get_text()
   {
      return text;
   }

   // Private functions

   void Text::recenter()
   {
      text.setOrigin(text.getLocalBounds().getPosition() + text.getLocalBounds().getSize() * .5f);
   }
}
