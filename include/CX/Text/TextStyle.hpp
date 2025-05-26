#ifndef CX_TEXT_TEXT_STYLE_HPP
#define CX_TEXT_TEXT_STYLE_HPP

#include "CX/Color.hpp"
#include <memory>

namespace sf
{
   class Font;
}

namespace cx
{
   /// @brief Save styles between text.
   struct TextStyle
   {
   private:
      /// @brief Global overridable styles.
      static std::unique_ptr<TextStyle> style1_t, style2_t, style3_t;
   public:

      /// @brief Font of the text.
      std::shared_ptr<sf::Font> font;

      /// @brief Character size of the text.
      unsigned char_size = 32;

      /// @brief Color of the text.
      Color text_color = Color(255);

      /// @brief Outline color of the text.
      Color outline_color = Color(0);

      /// @brief Outline thickness of the text.
      float outline_thickness = 0.f;

      /// @brief Access first style.
      /// @return First style.
      static TextStyle& style1()
      {
         if (!style1_t)
            style1_t = std::make_unique<TextStyle>();
         return *style1_t;
      }

      /// @brief Access second style.
      /// @return Second style.
      static TextStyle& style2()
      {
         if (!style2_t)
            style2_t = std::make_unique<TextStyle>();
         return *style2_t;
      }

      /// @brief Access third style.
      /// @return Third style.
      static TextStyle& style3()
      {
         if (!style3_t)
            style3_t = std::make_unique<TextStyle>();
         return *style3_t;
      }
   };
}

#endif
