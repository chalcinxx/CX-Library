#ifndef CX_PLANE_PLANE_STYLE_HPP
#define CX_PLANE_PLANE_STYLE_HPP

#include "CX/Color.hpp"
#include "CX/Vector/Vec3.hpp"
#include <memory>

namespace sf
{
   class Texture;
}

namespace cx
{
   /// @brief Save styles between planes.
   struct PlaneStyle
   {
   private:
      /// @brief Global overridable styles.
      static std::unique_ptr<PlaneStyle> style1_t, style2_t, style3_t;
   public:

      /// @brief Size of the plane.
      Vec2f size = Vec2f(50.f);

      /// @brief Skew of the plane.
      Vec2f skew;

      /// @brief Rotation of the plane.
      Vec3f rotation;

      /// @brief Color of the plane.
      Color color = Color(255);

      /// @brief Texture of the plane.
      std::shared_ptr<sf::Texture> texture;

      /// @brief Access first style.
      /// @return First style.
      static PlaneStyle& style1()
      {
         if (!style1_t)
            style1_t = std::make_unique<PlaneStyle>();
         return *style1_t;
      }

      /// @brief Access second style.
      /// @return Second style.
      static PlaneStyle& style2()
      {
         if (!style2_t)
            style2_t = std::make_unique<PlaneStyle>();
         return *style2_t;
      }

      /// @brief Access third style.
      /// @return Third style.
      static PlaneStyle& style3()
      {
         if (!style3_t)
            style3_t = std::make_unique<PlaneStyle>();
         return *style3_t;
      }
   };
}

#endif
