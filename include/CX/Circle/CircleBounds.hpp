#ifndef CX_CIRCLE_CIRCLE_BOUNDS_HPP
#define CX_CIRCLE_CIRCLE_BOUNDS_HPP

#include "CX/Math/Math.hpp"
#include "CX/Vector/Vec5.hpp"

namespace cx
{
   /// @brief Circle boundaries.
   struct CircleBounds
   {
      float radius = 0.f;       ///< @brief Circle radius.
      Vec2f center;             ///< @brief Circle center.
      Vec2f scale = Vec2f(1.f); ///< @brief Circle scale.
      float rotation = 0.f;     ///< @brief Circle rotation.

      // Constructors

      /// @brief Create the default boundaries.
      constexpr CircleBounds();

      /// @brief Create new boundaries.
      /// @param radius Radius of the circle.
      /// @param center Center of the circle.
      constexpr CircleBounds(float radius,
                             const Vec2f& center,
                             const Vec2f& scale = {1.f},
                             float rotation = 0.f)
         : radius(radius), center(center), scale(scale), rotation(rotation) {}
      
      // Constructors after creation

      /// @brief Create new boundaries.
      /// @param radius Radius of the circle.
      /// @param center Center of the circle.
      constexpr void create(float radius,
                            const Vec2f& center,
                            const Vec2f& scale = {1.f},
                            float rotation = 0.f)
      {
         this->radius   = radius;
         this->center   = center;
         this->scale    = scale;
         this->rotation = rotation;
      }
      
      // Distance functions

      /// @brief Get distance between two boundaries.
      /// @param other Other boundaries.
      /// @return Distance.
      constexpr float distance(const CircleBounds& other) const
      {
         return center.distance(other.center);
      }

      /// @brief Get distance to a point.
      /// @param point Point.
      /// @return Distance.
      template<Number T = float>
      constexpr float distance(const Vec2<T>& point) const
      {
         return center.distance(point);
      }

      /// @brief Get distance between two boundaries.
      /// @param other Other boundaries.
      /// @return Distance.
      template<Number T = float>
      constexpr float distance(const Vec4<T>& other) const
      {
         return center.distance(other.get_center());
      }

      /// @brief Get distance between two boundaries.
      /// @param other Other boundaries.
      /// @return Distance.
      template<Number T = float>
      constexpr float distance(const Vec5<T>& other) const
      {
         return center.distance(other.get_center());
      }

      /// @brief Get distance squared between two boundaries.
      /// @param other Other boundaries.
      /// @return Distance.
      constexpr float distance_squared(const CircleBounds& other) const
      {
         return center.distance_squared(other.center);
      }

      /// @brief Get distance to a point.
      /// @param point Point.
      /// @return Distance.
      template<Number T = float>
      constexpr float distance_squared(const Vec2<T>& point) const
      {
         return center.distance_squared(point);
      }

      /// @brief Get distance between two boundaries.
      /// @param other Other boundaries.
      /// @return Distance.
      template<Number T = float>
      constexpr float distance_squared(const Vec4<T>& other) const
      {
         return center.distance_squared(other.get_center());
      }

      /// @brief Get distance between two boundaries.
      /// @param other Other boundaries.
      /// @return Distance.
      template<Number T = float>
      constexpr float distance_squared(const Vec5<T>& other) const
      {
         return center.distance_squared(other.get_center());
      }

      // Contains functions

      /// @brief Check if circle contains a point.
      /// @param point Point.
      /// @return True if contains.
      template<Number T = float>
      constexpr bool contains(const Vec2<T>& point) const
      {
         // Rotated, scaled circle collision
         if (!ellipsis())
            return distance_squared(point) <= scaled_radius() * scaled_radius();

         // Rotated, scaled ellipsis collision
         const auto size = get_half_size();

         if (size.zero())
            return false;

         if (rotated())
         {
            const auto local = point.rotate_relative_to(center, cx::Rad::convert(-rotation));
            return ((local - center) / size).magnitude_squared() <= 1.f;
         }
         return ((point - center) / size).magnitude_squared() <= 1.f;
      }

      // Collision functions

      /// @brief Check collision against other boundaries.
      /// @param other Other boundaries.
      /// @return True if colliding.
      constexpr bool colliding(const CircleBounds& other) const
      {
         // Circle against circle collision
         if (!ellipsis() && !other.ellipsis())
            return distance(other) <= scaled_radius() + other.scaled_radius();

         // Ellipsis against circle/ellipsis collision
         const auto size_a = get_half_size();
         const auto size_b = other.get_half_size();

         if (size_a.zero() || size_b.zero())
            return false;
         
         // Rotated ellipsis against rotated circle/ellipsis collision
         if (rotated() || other.rotated())
         {
            const auto local = other.center.rotate_relative_to(center, cx::Rad::convert(-rotation));
            const auto delta = (local - center) / (size_a + size_b);
            return delta.magnitude_squared() <= 1.f;
         }
         const auto delta = (other.center - center) / (size_a + size_b);
         return delta.magnitude_squared() <= 1.f;
      }

      /// @brief Check collision against other boundaries.
      /// @param other Other boundaries.
      /// @return True if colliding.
      template<Number T>
      constexpr bool colliding(const Vec4<T>& other) const
      {
         const auto size = get_half_size();

         // Un-rotated rectangle against circle or un-rotated ellipsis collision
         if (!rotated() || !ellipsis())
         {
            const Vec2f min = (other.get_top_left() - center) / size;
            const Vec2f max = (other.get_bottom_right() - center) / size;

            const Vec2f closest (cx::safe_clamp(0.f, min.x, max.x), cx::safe_clamp(0.f, min.y, max.y));
            return closest.magnitude_squared() <= 1.f;
         }

         // Un-rotated rectangle against rotated ellipsis collision
         const auto rad = cx::Rad::convert(rotation);
         const Vec2f corners[] = {
            other.get_top_left(),
            Vec2f(other.get_right(), other.get_top()),
            other.get_bottom_right(),
            Vec2f(other.get_left(), other.get_bottom())
         };

         const Vec2f axes[] {
            Vec2f(1.f, 0.f),
            Vec2f(0.f, 1.f),
            Vec2f(1.f, 0.f).rotate(rad),
            Vec2f(0.f, 1.f).rotate(rad)
         };

         const auto e1 = axes[2] * size.x;
         const auto e2 = axes[3] * size.y;

         for (const auto& axis : axes)
         {
            float min_r = std::numeric_limits<float>::max();
            float max_r = -std::numeric_limits<float>::max();

            for (const auto& c : corners)
            {
               float proj = axis.dot(c);
               min_r = std::min(min_r, proj);
               max_r = std::max(max_r, proj);
            }

            float center_proj = axis.dot(center);
            float r = std::sqrt(std::pow(axis.dot(e1), 2) + std::pow(axis.dot(e2), 2));

            if (max_r < center_proj - r || center_proj + r < min_r)
               return false;
         }
         return true;
      }

      /// @brief Check collision against other boundaries.
      /// @param other Other boundaries.
      /// @return True if colliding.
      template<Number T>
      constexpr bool colliding(const Vec5<T>& other) const
      {
         if (!other.rotated())
            return colliding(other.un_rotated());

         const auto corners = other.get_corners();
         const auto r_rad   = cx::Rad::convert(-other.r);
         const auto size    = get_half_size();

         // Rotated rectangle against circle collision
         if (!ellipsis())
         {
            const Vec2f min = (corners.at(0) - center).rotate(r_rad) / size;
            const Vec2f max = (corners.at(2) - center).rotate(r_rad) / size;

            const Vec2f closest = {cx::safe_clamp(0.f, min.x, max.x), cx::safe_clamp(0.f, min.y, max.y)};
            return closest.magnitude_squared() <= 1.f;
         }

         // Rotated rectangle against rotated ellipsis collision
         const auto rad    = cx::Rad::convert(rotation);
         const auto r_axes = other.get_axes();

         const Vec2f axes[] {
            r_axes[0][1],
            r_axes[1][1],
            Vec2f(1.f, 0.f).rotate(rad),
            Vec2f(0.f, 1.f).rotate(rad)
         };

         const auto e1 = axes[2] * size.x;
         const auto e2 = axes[3] * size.y;

         for (const auto& axis : axes)
         {
            float min_r = std::numeric_limits<float>::max();
            float max_r = -std::numeric_limits<float>::max();

            for (const auto& c : corners)
            {
               float proj = axis.dot(c);
               min_r = std::min(min_r, proj);
               max_r = std::max(max_r, proj);
            }

            float center_proj = axis.dot(center);
            float r = std::sqrt(std::pow(axis.dot(e1), 2) + std::pow(axis.dot(e2), 2));

            if (max_r < center_proj - r || center_proj + r < min_r)
               return false;
         }
         return true;
      }

      // Getter functions

      /// @brief Get scaled size.
      /// @return Size.
      constexpr Vec2f get_size() const
      {
         return scale * radius * 2.f;
      }

      /// @brief Get scaled half size.
      /// @return Half size.
      constexpr Vec2f get_half_size() const
      {
         return scale * radius;
      }

      /// @brief Get scaled radius.
      /// @return Scaled radius.
      constexpr float scaled_radius() const
      {
         return radius * scale.x;
      }

      /// @brief Check if circle is rotated.
      /// @return True if rotated.
      constexpr bool rotated() const
      {
         return rotation != 0.f;
      }

      /// @brief Check if circle is an ellipsis.
      /// @return True if ellipsis.
      constexpr bool ellipsis() const
      {
         return scale.x != scale.y;
      }

      // Other functions

      /// @brief Copy boundaries.
      /// @param other Other boundaries.
      /// @return Boundaries.
      constexpr const CircleBounds& operator=(const CircleBounds& other)
      {
         radius   = other.radius;
         center   = other.center;
         scale    = other.scale;
         rotation = other.rotation;
         return *this;
      }

      /// @brief Clear boundaries.
      constexpr void clear()
      {
         radius = rotation = 0.f;
         center = Vec2f(0.f);
         scale  = Vec2f(1.f);
      }
   };
}

#endif
