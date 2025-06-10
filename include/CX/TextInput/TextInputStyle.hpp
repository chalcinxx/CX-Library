#ifndef CX_TEXTINPUT_TEXTINPUT_STYLE_HPP
#define CX_TEXTINPUT_TEXTINPUT_STYLE_HPP

#include "CX/Color.hpp"
#include "CX/Vector/Vec2.hpp"
#include <memory>

namespace sf
{
   class Font;
   class Texture;
}

namespace cx
{
   /// @brief Save styles between inputs.
   struct TextInputStyle
   {
   private:
      /// @brief Global overridable styles.
      static std::unique_ptr<TextInputStyle> style1_t, style2_t, style3_t;
   public:

      /// @brief Size of the input.
      Vec2f size = Vec2f(200.f, 50.f);

      /// @brief Font of the input.
      std::shared_ptr<sf::Font> font;

      /// @brief Character size of the input.
      unsigned char_size = 32u;

      /// @brief Color of the input.
      Color color = Color(255);

      /// @brief Color of the text.
      Color text_color = Color(255);

      /// @brief Outline color of the text.
      Color text_outline_color = Color(0);

      /// @brief Outline thickness of the text.
      float text_outline_thickness = 1.f;

      /// @brief Texture of the input.
      std::shared_ptr<sf::Texture> texture;

      /// @brief Access first style.
      /// @return First style.
      static TextInputStyle& style1()
      {
         if (!style1_t)
            style1_t = std::make_unique<TextInputStyle>();
         return *style1_t;
      }

      /// @brief Access second style.
      /// @return Second style.
      static TextInputStyle& style2()
      {
         if (!style2_t)
            style2_t = std::make_unique<TextInputStyle>();
         return *style2_t;
      }

      /// @brief Access third style.
      /// @return Third style.
      static TextInputStyle& style3()
      {
         if (!style3_t)
            style3_t = std::make_unique<TextInputStyle>();
         return *style3_t;
      }
   };
}

#endif
