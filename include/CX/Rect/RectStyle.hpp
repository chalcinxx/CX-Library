#ifndef CX_RECT_RECT_STYLE_HPP
#define CX_RECT_RECT_STYLE_HPP

#include "CX/Color.hpp"
#include "CX/Vector/Vec2.hpp"
#include <memory>

namespace sf
{
   class Texture;
}

namespace cx
{
   /// @brief Save styles between rectangles.
   struct RectStyle
   {
   private:
      /// @brief Global overridable styles.
      static std::unique_ptr<RectStyle> style1_t, style2_t, style3_t;
   public:

      /// @brief Size of the rectangle.
      Vec2f size = Vec2f(50.f);

      /// @brief Color of the rectangle.
      Color color = Color(255);

      /// @brief Texture of the rectangle.
      std::shared_ptr<sf::Texture> texture;

      /// @brief Access first style.
      /// @return First style.
      static RectStyle& style1()
      {
         if (!style1_t)
            style1_t = std::make_unique<RectStyle>();
         return *style1_t;
      }

      /// @brief Access second style.
      /// @return Second style.
      static RectStyle& style2()
      {
         if (!style2_t)
            style2_t = std::make_unique<RectStyle>();
         return *style2_t;
      }

      /// @brief Access third style.
      /// @return Third style.
      static RectStyle& style3()
      {
         if (!style3_t)
            style3_t = std::make_unique<RectStyle>();
         return *style3_t;
      }
   };
}

#endif
