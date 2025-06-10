#ifndef CX_CIRCLE_CIRCLE_STYLE_HPP
#define CX_CIRCLE_CIRCLE_STYLE_HPP

#include "CX/Color.hpp"
#include <memory>

namespace sf
{
   class Texture;
}

namespace cx
{
   /// @brief Save styles between circles.
   struct CircleStyle
   {
   private:
      /// @brief Global overridable styles.
      static std::unique_ptr<CircleStyle> style1_t, style2_t, style3_t;
   public:

      /// @brief Radius of the circle.
      float radius = 25.f;

      /// @brief Segment count of the circle.
      size_t point_count = 30;

      /// @brief Color of the circle.
      Color color = Color(255);

      /// @brief Texture of the circle.
      std::shared_ptr<sf::Texture> texture;

      /// @brief Access first style.
      /// @return First style.
      static CircleStyle& style1()
      {
         if (!style1_t)
            style1_t = std::make_unique<CircleStyle>();
         return *style1_t;
      }

      /// @brief Access second style.
      /// @return Second style.
      static CircleStyle& style2()
      {
         if (!style2_t)
            style2_t = std::make_unique<CircleStyle>();
         return *style2_t;
      }

      /// @brief Access third style.
      /// @return Third style.
      static CircleStyle& style3()
      {
         if (!style3_t)
            style3_t = std::make_unique<CircleStyle>();
         return *style3_t;
      }
   };
}

#endif
