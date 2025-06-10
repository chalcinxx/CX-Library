#ifndef CX_BUTTON_BUTTON_STYLE_HPP
#define CX_BUTTON_BUTTON_STYLE_HPP

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
   /// @brief Save styles between buttons.
   struct ButtonStyle
   {
   private:
      /// @brief Global overridable styles.
      static std::unique_ptr<ButtonStyle> style1_t, style2_t, style3_t;
   public:

      /// @brief Size of the button.
      Vec2f size = Vec2f(200.f, 50.f);

      /// @brief Font of the button.
      std::shared_ptr<sf::Font> font;

      /// @brief Character size of the button.
      unsigned char_size = 32U;

      /// @brief Color of the button.
      Color color = Color(255);

      /// @brief Color of the text.
      Color text_color = Color(255);

      /// @brief Outline color of the text.
      Color text_outline_color = Color(0);

      /// @brief Outline thickness of the text.
      float text_outline_thickness = 1.f;

      /// @brief Texture of the button.
      std::shared_ptr<sf::Texture> texture;

      /// @brief Access first style.
      /// @return First style.
      static ButtonStyle& style1()
      {
         if (!style1_t)
            style1_t = std::make_unique<ButtonStyle>();
         return *style1_t;
      }

      /// @brief Access second style.
      /// @return Second style.
      static ButtonStyle& style2()
      {
         if (!style2_t)
            style2_t = std::make_unique<ButtonStyle>();
         return *style2_t;
      }

      /// @brief Access third style.
      /// @return Third style.
      static ButtonStyle& style3()
      {
         if (!style3_t)
            style3_t = std::make_unique<ButtonStyle>();
         return *style3_t;
      }
   };
}

#endif
