#ifndef CX_RAY_RAY_HPP
#define CX_RAY_RAY_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include "CX/Ray/RaycastResult.hpp"
#include "CX/UIElement/UIElement.hpp"
#include <algorithm>

namespace cx
{
   /// @brief Check collision against a line.
   class Ray
   {
   public:
      // Constructors

      /// @brief Create a default ray.
      Ray() = default;
      ~Ray() = default;

      /// @brief Create a new ray.
      /// @param origin Position of the ray.
      /// @param direction Ray direction.
      /// @param length Length of ray.
      constexpr Ray(const Vec2f& origin, const Vec2f& direction, float length)
         : origin(origin), direction(direction.normalize()),
         length(std::abs(length)) {}

      /// @brief Create a new ray.
      /// @param origin Position of the ray.
      /// @param endPoint End point of the ray.
      constexpr Ray(const Vec2f& origin, const Vec2f& endPoint)
         : origin(origin), direction(origin.direction_to(endPoint)),
         length(origin.distance(endPoint)) {}

      /// @brief Create a new ray.
      /// @param origin Position of the ray.
      /// @param angle Rotation of the ray in degrees.
      /// @param length Length of ray.
      constexpr Ray(const Vec2f& origin, float angle, float length)
         : origin(origin), direction(Vec2f()), length(std::abs(length))
      {
         const float rad = cx::Radians::convert(angle);
         direction = Vec2f(std::cos(rad), std::sin(rad)).normalize();
      }

      /// @brief Copy a ray.
      /// @param ray Ray to copy.
      constexpr Ray(const Ray& ray)
         : origin(ray.origin), direction(ray.direction), length(ray.length), ray_disabled(ray.ray_disabled) {}

      // Constructors after creation

      /// @brief Create a new ray.
      /// @param origin Position of the ray.
      /// @param direction Ray direction.
      /// @param length Length of ray.
      constexpr void create(const Vec2f& origin, const Vec2f& direction, float length)
      {
         this->origin = origin;
         this->direction = direction.normalize();
         this->length = std::abs(length);
      }

      /// @brief Create a new ray.
      /// @param origin Position of the ray.
      /// @param endPoint End point of the ray.
      constexpr void create(const Vec2f& origin, const Vec2f& endPoint)
      {
         this->origin = origin;
         this->direction = origin.direction_to(endPoint);
         this->length = origin.distance(endPoint);
      }

      /// @brief Create a new ray.
      /// @param origin Position of the ray.
      /// @param angle Rotation of the ray in degrees.
      /// @param length Length of ray.
      constexpr void create(const Vec2f& origin, float angle, float length)
      {
         const float rad = cx::Radians::convert(angle);
         this->direction = Vec2f(std::cos(rad), std::sin(rad)).normalize();
         this->origin = origin;
         this->length = std::abs(length);
      }

      /// @brief Copy a ray.
      /// @param ray Ray to copy.
      constexpr void create(const Ray& ray)
      {
         this->origin = ray.origin;
         this->direction = ray.direction;
         this->length = ray.length;
         this->ray_disabled = ray.ray_disabled;
      }

      // Collision functions

      /// @brief Check for collision against boundaries.
      /// @param bounds Boundaries to check collision against.
      /// @return True if colliding.
      constexpr bool colliding(const Vec4f& bounds) const
      {
         if (direction.empty() || ray_disabled)
            return false;

         constexpr float inf = std::numeric_limits<float>::infinity();
         const Vec2f inverted_dir (
            (direction.x == 0.f ? inf : 1.f / direction.x),
            (direction.y == 0.f ? inf : 1.f / direction.y)
         );

         float tmin_x = (bounds.x - origin.x) * inverted_dir.x;
         float tmax_x = (bounds.x + bounds.w - origin.x) * inverted_dir.x;
         if (inverted_dir.x < 0.f)
            std::swap(tmin_x, tmax_x);
         
         float tmin_y = (bounds.y - origin.y) * inverted_dir.y;
         float tmax_y = (bounds.y + bounds.h - origin.y) * inverted_dir.y;
         if (inverted_dir.y < 0.f)
            std::swap(tmin_y, tmax_y);

         const float tmin = std::max(tmin_x, tmin_y);
         const float tmax = std::min(tmax_x, tmax_y);

         return tmin <= tmax && tmax > 0.f && tmin <= length;
      }

      /// @brief Check for collision against boundaries.
      /// @param bounds Boundaries to check collision against.
      /// @return True if colliding.
      constexpr bool colliding(const Vec5f& bounds) const
      {
         if (!bounds.is_rotated())
            return colliding(bounds.un_rotated());

         if (direction.empty() || ray_disabled)
            return false;

         const float rad = -bounds.r * (M_PIf / 180.f);
         const Vec2f r_direction = direction.rotate(rad).normalize();
         const Vec2f r_origin = (origin - bounds.get_center()).rotate(rad) + bounds.get_center();

         if (r_direction.empty())
            return false;

         constexpr float inf = std::numeric_limits<float>::infinity();
         const Vec2f inverted_dir (
            (r_direction.x == 0.f ? inf : 1.f / r_direction.x),
            (r_direction.y == 0.f ? inf : 1.f / r_direction.y)
         );

         float tmin_x = (bounds.x - r_origin.x) * inverted_dir.x;
         float tmax_x = (bounds.x + bounds.w - r_origin.x) * inverted_dir.x;
         if (inverted_dir.x < 0.f)
            std::swap(tmin_x, tmax_x);
         
         float tmin_y = (bounds.y - r_origin.y) * inverted_dir.y;
         float tmax_y = (bounds.y + bounds.h - r_origin.y) * inverted_dir.y;
         if (inverted_dir.y < 0.f)
            std::swap(tmin_y, tmax_y);

         const float tmin = std::max(tmin_x, tmin_y);
         const float tmax = std::min(tmax_x, tmax_y);

         return tmin <= tmax && tmax > 0.f && tmin <= length;
      }

      /// @brief Check for collision against a ray.
      /// @param other Ray to check collision against.
      /// @return True if colliding.
      constexpr bool colliding(const Ray& other) const
      {
         const Vec2f delta = other.origin - origin;
         const float det = direction.cross(other.direction);

         if (std::abs(det) < .001f)
            return false;

         const float t1 = delta.cross(other.direction) / det;
         const float t2 = delta.cross(direction) / det;

         return t1 >= 0.f && t2 >= 0.f && t1 <= length && t2 <= other.length;
      }

      /// @brief Check for collision against an element.
      /// @param element Element to check collision against.
      /// @return True if colliding.
      constexpr bool colliding(const UIElement& element) const
      {
         return colliding(element.get_bounds());
      }

      /// @brief Get collision point if colliding.
      /// @param bounds Boundaries to check collision against.
      /// @return Collision point if colliding.
      constexpr std::optional<Vec2f> collision_point(const Vec4f& bounds) const
      {
         if (direction.empty() || ray_disabled)
            return std::optional<Vec2f>();

         constexpr float inf = std::numeric_limits<float>::infinity();
         const Vec2f inverted_dir (
            (direction.x == 0.f ? inf : 1.f / direction.x),
            (direction.y == 0.f ? inf : 1.f / direction.y)
         );

         float tmin_x = (bounds.x - origin.x) * inverted_dir.x;
         float tmax_x = (bounds.x + bounds.w - origin.x) * inverted_dir.x;
         if (inverted_dir.x < 0.f)
            std::swap(tmin_x, tmax_x);
         
         float tmin_y = (bounds.y - origin.y) * inverted_dir.y;
         float tmax_y = (bounds.y + bounds.h - origin.y) * inverted_dir.y;
         if (inverted_dir.y < 0.f)
            std::swap(tmin_y, tmax_y);

         const float tmin = std::max(tmin_x, tmin_y);
         const float tmax = std::min(tmax_x, tmax_y);

         if (tmin > tmax || tmax < 0.f || tmin > length || tmin < 0.f)
            return std::optional<Vec2f>();

         return std::optional<Vec2f>(origin + direction * tmin);
      }

      /// @brief Get collision point if colliding.
      /// @param bounds Boundaries to check collision against.
      /// @return Collision point if colliding.
      constexpr std::optional<Vec2f> collision_point(const Vec5f& bounds) const
      {
         if (!bounds.is_rotated())
            return collision_point(bounds.un_rotated());

         if (direction.empty() || ray_disabled)
            return std::optional<Vec2f>();

         const float rad = -bounds.r * (M_PIf / 180.f);
         const Vec2f r_origin = (origin - bounds.get_center()).rotate(rad);
         const Vec2f r_direction = direction.rotate(rad).normalize();

         if (r_direction.empty())
            return std::optional<Vec2f>();

         constexpr float inf = std::numeric_limits<float>::infinity();
         const Vec2f inverted_dir (
            (r_direction.x == 0.f ? inf : 1.f / r_direction.x),
            (r_direction.y == 0.f ? inf : 1.f / r_direction.y)
         );

         const Vec2f local_pos = bounds.get_top_left() - bounds.get_center();

         float tmin_x = (local_pos.x - r_origin.x) * inverted_dir.x;
         float tmax_x = (local_pos.x + bounds.w - r_origin.x) * inverted_dir.x;
         if (inverted_dir.x < 0.f)
            std::swap(tmin_x, tmax_x);
         
         float tmin_y = (local_pos.y - r_origin.y) * inverted_dir.y;
         float tmax_y = (local_pos.y + bounds.h - r_origin.y) * inverted_dir.y;
         if (inverted_dir.y < 0.f)
            std::swap(tmin_y, tmax_y);

         const float tmin = std::max(tmin_x, tmin_y);
         const float tmax = std::min(tmax_x, tmax_y);

         if (tmin > tmax || tmax < 0.f || tmin < 0.f || tmin > length)
            return std::optional<Vec2f>();

         Vec2f l_collision = r_origin + r_direction * tmin;
         return std::optional<Vec2f>(l_collision.rotate(-rad) + bounds.get_center());
      }

      /// @brief Get collision point if colliding.
      /// @param other Ray to check collision against.
      /// @return Collision point if colliding.
      constexpr std::optional<Vec2f> collision_point(const Ray& other) const
      {
         const Vec2f delta = other.origin - origin;
         const float det = direction.cross(other.direction);

         if (std::abs(det) < .001f)
            return std::optional<Vec2f>();

         const float t1 = delta.cross(other.direction) / det;
         const float t2 = delta.cross(direction) / det;

         if (t1 < 0.f || t2 < 0.f || t1 > length || t2 > other.length)
            return std::optional<Vec2f>();

         return std::optional<Vec2f>(origin + direction * t1);
      }

      /// @brief Get collision point if colliding.
      /// @param element Element to check collision against.
      /// @return Collision point if colliding.
      constexpr std::optional<Vec2f> collision_point(const UIElement& element) const
      {
         return collision_point(element.get_bounds());
      }

      /// @brief Get ray exit point if colliding.
      /// @param bounds Boundaries to check collision against.
      /// @return Exit point if colliding.
      constexpr std::optional<Vec2f> exit_point(const Vec4f& bounds) const
      {
         if (direction.empty() || ray_disabled)
            return std::optional<Vec2f>();

         constexpr float inf = std::numeric_limits<float>::infinity();
         const Vec2f inverted_dir (
            (direction.x == 0.f ? inf : 1.f / direction.x),
            (direction.y == 0.f ? inf : 1.f / direction.y)
         );

         float tmin_x = (bounds.x - origin.x) * inverted_dir.x;
         float tmax_x = (bounds.x + bounds.w - origin.x) * inverted_dir.x;
         if (inverted_dir.x < 0.f)
            std::swap(tmin_x, tmax_x);
         
         float tmin_y = (bounds.y - origin.y) * inverted_dir.y;
         float tmax_y = (bounds.y + bounds.h - origin.y) * inverted_dir.y;
         if (inverted_dir.y < 0.f)
            std::swap(tmin_y, tmax_y);

         const float tmin = std::max(tmin_x, tmin_y);
         const float tmax = std::min(tmax_x, tmax_y);

         if (tmin > tmax || tmax < 0.f || tmin > length || tmax > length)
            return std::optional<Vec2f>();

         return std::optional<Vec2f>(origin + direction * tmax);
      }
      
      /// @brief Get ray exit point if colliding.
      /// @param bounds Boundaries to check collision against.
      /// @return Exit point if colliding.
      constexpr std::optional<Vec2f> exit_point(const Vec5f& bounds) const
      {
         if (!bounds.is_rotated())
            return exit_point(bounds.un_rotated());

         if (direction.empty() || ray_disabled)
            return std::optional<Vec2f>();

         const float rad = -bounds.r * (M_PIf / 180.f);
         const Vec2f r_origin = (origin - bounds.get_center()).rotate(rad);
         const Vec2f r_direction = direction.rotate(rad).normalize();

         if (r_direction.empty())
            return std::optional<Vec2f>();

         constexpr float inf = std::numeric_limits<float>::infinity();
         const Vec2f inverted_dir (
            (r_direction.x == 0.f ? inf : 1.f / r_direction.x),
            (r_direction.y == 0.f ? inf : 1.f / r_direction.y)
         );

         const Vec2f local_pos = bounds.get_top_left() - bounds.get_center();

         float tmin_x = (local_pos.x - r_origin.x) * inverted_dir.x;
         float tmax_x = (local_pos.x + bounds.w - r_origin.x) * inverted_dir.x;
         if (inverted_dir.x < 0.f)
            std::swap(tmin_x, tmax_x);
         
         float tmin_y = (local_pos.y - r_origin.y) * inverted_dir.y;
         float tmax_y = (local_pos.y + bounds.h - r_origin.y) * inverted_dir.y;
         if (inverted_dir.y < 0.f)
            std::swap(tmin_y, tmax_y);

         const float tmin = std::max(tmin_x, tmin_y);
         const float tmax = std::min(tmax_x, tmax_y);

         if (tmin > tmax || tmax < 0.f || tmin > length || tmax > length)
            return std::optional<Vec2f>();

         Vec2f l_collision = r_origin + r_direction * tmax;
         return std::optional<Vec2f>(l_collision.rotate(-rad) + bounds.get_center());
      }

      /// @brief Get exit point if colliding.
      /// @param Exit Ray to check collision against.
      /// @return Collision point if colliding.
      constexpr std::optional<Vec2f> exit_point(const Ray& other) const
      {
         const Vec2f delta = other.origin - origin;
         const float det = direction.cross(other.direction);

         if (std::abs(det) < .001f)
            return std::optional<Vec2f>();

         const float t1 = delta.cross(other.direction) / det;
         const float t2 = delta.cross(direction) / det;

         if (t1 < 0.f || t2 < 0.f || t1 > length || t2 > other.length)
            return std::optional<Vec2f>();

         return std::optional<Vec2f>(other.origin + other.direction * t2);
      }

      /// @brief Get ray exit point if colliding.
      /// @param element Element to check collision against.
      /// @return Exit point if colliding.
      constexpr std::optional<Vec2f> exit_point(const UIElement& element) const
      {
         return exit_point(element.get_bounds());
      }

      /// @brief Reflect ray off of collision point if colliding.
      /// @param bounds Boundaries to check collision against.
      /// @return Reflected ray.
      constexpr std::optional<Ray> reflect(const Vec4f& bounds) const
      {
         if (direction.empty() || ray_disabled)
            return std::optional<Ray>();

         constexpr float inf = std::numeric_limits<float>::infinity();
         const Vec2f inverted_dir (
            (direction.x == 0.f ? inf : 1.f / direction.x),
            (direction.y == 0.f ? inf : 1.f / direction.y)
         );

         float tmin_x = (bounds.x - origin.x) * inverted_dir.x;
         float tmax_x = (bounds.x + bounds.w - origin.x) * inverted_dir.x;
         if (inverted_dir.x < 0.f)
            std::swap(tmin_x, tmax_x);
         
         float tmin_y = (bounds.y - origin.y) * inverted_dir.y;
         float tmax_y = (bounds.y + bounds.h - origin.y) * inverted_dir.y;
         if (inverted_dir.y < 0.f)
            std::swap(tmin_y, tmax_y);

         const float tmin = std::max(tmin_x, tmin_y);
         const float tmax = std::min(tmax_x, tmax_y);

         if (tmin > tmax || tmax < 0.f || tmin > length || tmin < 0.f)
            return std::optional<Ray>();

         const Vec2f collision_p = origin + direction * tmin;

         Vec2f normal;
         if (std::abs(collision_p.x - bounds.x) < .001f)
            normal = Vec2f(-1.f, 0.f); // Left
         else if (std::abs(collision_p.x - (bounds.x + bounds.w)) < .001f)
            normal = Vec2f(1.f, 0.f);  // Right
         else if (std::abs(collision_p.y - bounds.y) < .001f)
            normal = Vec2f(0.f, -1.f); // Top
         else if (std::abs(collision_p.y - (bounds.y + bounds.h)) < .001f)
            normal = Vec2f(0.f, 1.f);  // Bottom

         const Vec2f dir = direction - normal * direction.dot(normal) * 2.f;
         return std::optional<Ray>(Ray(collision_p, dir.normalize(), length));
      }

      /// @brief Reflect ray off of collision point if colliding.
      /// @param bounds Boundaries to check collision against.
      /// @return Reflected ray.
      constexpr std::optional<Ray> reflect(const Vec5f& bounds) const
      {
         if (!bounds.is_rotated())
            return reflect(bounds.un_rotated());

         if (direction.empty() || ray_disabled)
            return std::optional<Ray>();

         const float rad = -bounds.r * (M_PIf / 180.f);
         const Vec2f r_origin = (origin - bounds.get_center()).rotate(rad);
         const Vec2f r_direction = direction.rotate(rad).normalize();

         if (r_direction.empty())
            return std::optional<Ray>();

         constexpr float inf = std::numeric_limits<float>::infinity();
         const Vec2f inverted_dir (
            (r_direction.x == 0.f ? inf : 1.f / r_direction.x),
            (r_direction.y == 0.f ? inf : 1.f / r_direction.y)
         );

         const Vec2f local_pos = bounds.get_top_left() - bounds.get_center();

         float tmin_x = (local_pos.x - r_origin.x) * inverted_dir.x;
         float tmax_x = (local_pos.x + bounds.w - r_origin.x) * inverted_dir.x;
         if (inverted_dir.x < 0.f)
            std::swap(tmin_x, tmax_x);
         
         float tmin_y = (local_pos.y - r_origin.y) * inverted_dir.y;
         float tmax_y = (local_pos.y + bounds.h - r_origin.y) * inverted_dir.y;
         if (inverted_dir.y < 0.f)
            std::swap(tmin_y, tmax_y);

         const float tmin = std::max(tmin_x, tmin_y);
         const float tmax = std::min(tmax_x, tmax_y);

         if (tmin > tmax || tmax < 0.f || tmin < 0.f || tmin > length)
            return std::optional<Ray>();

         const Vec2f l_collision = r_origin + r_direction * tmin;
         const Vec2f collision_p = l_collision.rotate(-rad) + bounds.get_center();

         Vec2f normal;
         if (std::abs(l_collision.x - local_pos.x) < .001f)
            normal = Vec2f(-1.f, 0.f); // Left
         else if (std::abs(l_collision.x - (local_pos.x + bounds.w)) < .001f)
            normal = Vec2f(1.f, 0.f);  // Right
         else if (std::abs(l_collision.y - local_pos.y) < .001f)
            normal = Vec2f(0.f, -1.f); // Top
         else if (std::abs(l_collision.y - (local_pos.y + bounds.h)) < .001f)
            normal = Vec2f(0.f, 1.f);  // Bottom

         normal = normal.rotate(-rad).normalize();

         const Vec2f dir = direction - normal * direction.dot(normal) * 2.f;
         return std::optional<Ray>(Ray(collision_p, dir.normalize(), length));
      }

      /// @brief Reflect ray off of collision point if colliding.
      /// @param other Ray to check collision against.
      /// @return Reflected ray.
      constexpr std::optional<Ray> reflect(const Ray& other) const
      {
         const Vec2f delta = other.origin - origin;
         const float det = direction.cross(other.direction);

         if (std::abs(det) < .001f)
            return std::optional<Ray>();

         const float t1 = delta.cross(other.direction) / det;
         const float t2 = delta.cross(direction) / det;

         if (t1 < 0.f || t2 < 0.f || t1 > length || t2 > other.length)
            return std::optional<Ray>();

         const Vec2f normal = Vec2f(-other.direction.y, other.direction.x)
            * (det > 0.f ? 1.f : -1.f);

         const Vec2f dir = direction - normal * direction.dot(normal) * 2.f;
         return std::optional<Ray>(Ray(origin + direction * t1, dir.normalize(), length));
      }

      /// @brief Reflect ray off of collision point if colliding.
      /// @param element Element to check collision against.
      /// @return Reflected ray.
      constexpr std::optional<Ray> reflect(const UIElement& element) const
      {
         return reflect(element.get_bounds());
      }

      /// @brief Raycast against boundaries and get all info possible.
      /// @param bounds Boundaries to check collision against.
      /// @return Raycast result.
      constexpr RaycastResult raycast(const Vec4f& bounds) const
      {
         if (direction.empty() || ray_disabled)
            return RaycastResult{};

         constexpr float inf = std::numeric_limits<float>::infinity();
         const Vec2f inverted_dir (
            (direction.x == 0.f ? inf : 1.f / direction.x),
            (direction.y == 0.f ? inf : 1.f / direction.y)
         );

         float tmin_x = (bounds.x - origin.x) * inverted_dir.x;
         float tmax_x = (bounds.x + bounds.w - origin.x) * inverted_dir.x;
         if (inverted_dir.x < 0.f)
            std::swap(tmin_x, tmax_x);
         
         float tmin_y = (bounds.y - origin.y) * inverted_dir.y;
         float tmax_y = (bounds.y + bounds.h - origin.y) * inverted_dir.y;
         if (inverted_dir.y < 0.f)
            std::swap(tmin_y, tmax_y);

         const float tmin = std::max(tmin_x, tmin_y);
         const float tmax = std::min(tmax_x, tmax_y);

         if (tmin > tmax || tmax < 0.f || tmin > length)
            return RaycastResult{};

         std::optional<Vec2f> coll;
         if (tmin > 0.f) coll.emplace(origin + direction * tmin);

         std::optional<Vec2f> exit;
         if (tmax < length) exit.emplace(origin + direction * tmax);

         const float distance = ((coll.has_value() ? tmin : 0.f));
         const float penetration = (coll.has_value() ? (exit.has_value()
            ? exit->distance(*coll) : coll->distance(origin + direction
            * length)) : (exit.has_value() ? origin.distance(*exit) : 0.f)); 

         std::optional<Vec2f> normal;
         if (coll.has_value())
         {
            const float dx_left   = std::abs(coll->x - bounds.x);
            const float dx_right  = std::abs(coll->x - (bounds.x + bounds.w));
            const float dy_top    = std::abs(coll->y - bounds.y);
            const float dy_bottom = std::abs(coll->y - (bounds.y + bounds.h));

            if (dx_left < .001f || dx_right < .001f)
               normal.emplace(Vec2f((dx_left < dx_right ? -1.f : 1.f), 0.f));
            else if (dy_top < .001f || dy_bottom < .001f)
               normal.emplace(Vec2f(0.f, (dy_top < dy_bottom ? -1.f : 1.f)));
         }

         std::optional<Vec2f> dir;
         if (normal.has_value())
            dir.emplace(direction - *normal * direction.dot(*normal) * 2.f);
         
         return RaycastResult{true, distance, penetration, coll, exit, normal, dir};
      }

      /// @brief Raycast against boundaries and get all info possible.
      /// @param bounds Boundaries to check collision against.
      /// @return Raycast result.
      constexpr RaycastResult raycast(const Vec5f& bounds) const
      {
         if (!bounds.is_rotated())
            return raycast(bounds.un_rotated());

         if (direction.empty() || ray_disabled)
            return RaycastResult{};

         const float rad = cx::Radians::convert(-bounds.r);
         const Vec2f r_origin = (origin - bounds.get_center()).rotate(rad);
         const Vec2f r_direction = direction.rotate(rad).normalize();

         if (r_direction.empty())
            return RaycastResult{};

         constexpr float inf = std::numeric_limits<float>::infinity();
         const Vec2f inverted_dir (
            (r_direction.x == 0.f ? inf : 1.f / r_direction.x),
            (r_direction.y == 0.f ? inf : 1.f / r_direction.y)
         );

         const Vec2f local_pos = bounds.get_top_left() - bounds.get_center();

         float tmin_x = (local_pos.x - r_origin.x) * inverted_dir.x;
         float tmax_x = (local_pos.x + bounds.w - r_origin.x) * inverted_dir.x;
         if (inverted_dir.x < 0.f)
            std::swap(tmin_x, tmax_x);
         
         float tmin_y = (local_pos.y - r_origin.y) * inverted_dir.y;
         float tmax_y = (local_pos.y + bounds.h - r_origin.y) * inverted_dir.y;
         if (inverted_dir.y < 0.f)
            std::swap(tmin_y, tmax_y);

         const float tmin = std::max(tmin_x, tmin_y);
         const float tmax = std::min(tmax_x, tmax_y);

         if (tmin > tmax || tmax < 0.f || tmin > length)
            return RaycastResult{};

         const Vec2f l_collision = r_origin + r_direction * tmin;
         std::optional<Vec2f> coll;
         if (tmin > 0.f) coll.emplace(l_collision.rotate(-rad)+ bounds.get_center());

         std::optional<Vec2f> exit;
         if (tmax < length) exit.emplace((r_origin + r_direction * tmax)
            .rotate(-rad) + bounds.get_center());

         const float distance = ((coll.has_value() ? tmin : 0.f));
         const float penetration = (coll.has_value() ? (exit.has_value()
            ? exit->distance(*coll) : coll->distance(origin + direction
            * length)) : (exit.has_value() ? origin.distance(*exit) : 0.f));
         
         std::optional<Vec2f> normal;
         if (coll.has_value())
         {
            const float dx_left   = std::abs(l_collision.x - local_pos.x);
            const float dx_right  = std::abs(l_collision.x - (local_pos.x + bounds.w));
            const float dy_top    = std::abs(l_collision.y - local_pos.y);
            const float dy_bottom = std::abs(l_collision.y - (local_pos.y + bounds.h));

            if (dx_left < .001f || dx_right < .001f)
               normal.emplace(Vec2f((dx_left < dx_right ? -1.f : 1.f), 0.f));
            else if (dy_top < .001f || dy_bottom < .001f)
               normal.emplace(Vec2f(0.f, (dy_top < dy_bottom ? -1.f : 1.f)));
            normal = normal->rotate(-rad).normalize();
         }

         std::optional<Vec2f> dir;
         if (normal.has_value()) 
            dir.emplace(direction - *normal * direction.dot(*normal) * 2.f);

         return RaycastResult{true, distance, penetration, coll, exit, normal, dir};
      }

      /// @brief Raycast against a ray and get all info possible.
      /// @param other Ray to check collision against.
      /// @return Raycast result.
      constexpr RaycastResult raycast(const Ray& other) const
      {
         const Vec2f delta = other.origin - origin;
         const float det = direction.cross(other.direction);

         if (std::abs(det) < .001f)
            return RaycastResult{};

         const float t1 = delta.cross(other.direction) / det;
         const float t2 = delta.cross(direction) / det;

         if (t1 < 0.f || t2 < 0.f || t1 > length || t2 > other.length)
            return RaycastResult{};

         const Vec2f collision = origin + direction * t1;
         const Vec2f normal = Vec2f(-other.direction.y, other.direction.x)
            * (det > 0.f ? 1.f : -1.f);

         const Vec2f dir = direction - normal * direction.dot(normal) * 2.f;
         return RaycastResult{true, t1, 0.f, collision, collision, normal, dir.normalize()};
      }

      /// @brief Raycast against an element and get all info possible.
      /// @param element Element to check collision against.
      /// @return Raycast result.
      constexpr RaycastResult raycast(const UIElement& element) const
      {
         return raycast(element.get_bounds());
      }

      // Setter functions

      /// @brief Set origin of the ray.
      /// @param new_origin New origin.
      constexpr void set_origin(const Vec2f& new_origin)
      {
         origin = new_origin;
      }

      /// @brief Set origin of the ray.
      /// @param origin_x New X origin.
      /// @param origin_y New Y origin.
      constexpr void set_origin(float origin_x, float origin_y)
      {
         origin = Vec2f(origin_x, origin_y);
      }

      /// @brief Set origin of the ray.
      /// @param new_origin New origin.
      constexpr void set_origin(float new_origin)
      {
         origin = Vec2f(new_origin);
      }

      /// @brief Set direction of the ray.
      /// @param new_direction New direction.
      constexpr void set_direction(const Vec2f& new_direction)
      {
         direction = new_direction.normalize();
      }

      /// @brief Set direction of the ray.
      /// @param direction_x New X direction.
      /// @param direction_y New Y direction.
      constexpr void set_direction(float direction_x, float direction_y)
      {
         direction = Vec2f(direction_x, direction_y).normalize();
      }

      /// @brief Set direction of the ray.
      /// @param new_direction New direction.
      constexpr void set_direction(float new_direction)
      {
         direction = Vec2f(new_direction).normalize();
      }

      /// @brief Set end point of the ray.
      /// @param end_point New end point.
      constexpr void set_end_point(const Vec2f& end_point)
      {
         direction = origin.direction_to(end_point);
         length = origin.distance(end_point);
      }

      /// @brief Set end point of the ray.
      /// @param end_x New end X.
      /// @param end_y New end Y.
      constexpr void set_end_point(float end_x, float end_y)
      {
         direction = origin.direction_to(Vec2f(end_x, end_y));
         length = origin.distance(Vec2f(end_x, end_y));
      }

      /// @brief Set end point of the ray.
      /// @param end_point New end point.
      constexpr void set_end_point(float end_point)
      {
         direction = origin.direction_to(Vec2f(end_point));
         length = origin.distance(Vec2f(end_point));
      }

      /// @brief Set length of the ray.
      /// @param new_length New length.
      constexpr void set_length(float new_length)
      {
         length = new_length;
      }

      /// @brief Set rotation of the ray.
      /// @param angle New rotation in degrees.
      constexpr void set_rotation(float angle)
      {
         const float rad = cx::Radians::convert(angle);
         const float last = origin.angle(origin + direction);
         direction = direction.rotate(rad - last).normalize();
      }

      /// @brief Set disabled or enabled for the ray.
      /// @param disabled Should ray be disabled.
      constexpr void set_disabled(bool disabled)
      {
         ray_disabled = disabled;
      }

      /// @brief Toggle ray disabled property.
      constexpr void toggle_disabled()
      {
         ray_disabled = !ray_disabled;
      }

      // Getter functions

      /// @brief Get ray origin.
      /// @return Origin.
      constexpr const Vec2f& get_origin() const
      {
         return origin;
      }

      /// @brief Get ray direction.
      /// @return Direction.
      constexpr const Vec2f& get_direction() const
      {
         return direction;
      }

      /// @brief Get ray length.
      /// @return Length.
      constexpr float get_length() const
      {
         return length;
      }

      /// @brief Get ray end point.
      /// @return End point.
      constexpr Vec2f get_end_point() const
      {
         return origin + direction * length;
      }

      /// @brief Get ray rotation.
      /// @return Rotation in degrees.
      constexpr float get_rotation() const
      {
         return origin.angle(origin + direction).degrees();
      }

      /// @brief Check if ray is disabled.
      /// @return True if disabled.
      constexpr bool is_disabled() const
      {
         return ray_disabled;
      }

      // Update functions

      /// @brief Move the ray.
      /// @param offset Amount to move by.
      constexpr void move(const Vec2f& offset)
      {
         origin += offset;
      }

      /// @brief Move the ray.
      /// @param offset_x Amount to move by horizontally.
      /// @param offset_y Amount to move by vertically.
      constexpr void move(float offset_x, float offset_y)
      {
         origin += Vec2f(offset_x, offset_y);
      }

      /// @brief Move the ray.
      /// @param offset Amount to move by.
      constexpr void move(float offset)
      {
         origin += Vec2f(offset);
      }

      /// @brief Rotate ray.
      /// @param angle Amount to rotate by in degrees.
      constexpr void rotate(float angle)
      {
         direction = direction.rotate(angle).normalize();
      }

      /// @brief Extend ray's length.
      /// @param amount Amount to extend by.
      constexpr void extend(float amount)
      {
         length += amount;
      }

      /// @brief Shrink ray's length.
      /// @param amount Amount to shrink by.
      constexpr void shrink(float amount)
      {
         length = std::max(0.f, length - amount);
      }

      // Operator overload functions
      
      /// @brief Copy a ray.
      /// @param other Ray to copy.
      /// @return Ray.
      constexpr const Ray& operator=(const Ray& other)
      {
         origin = other.origin;
         direction = other.direction;
         length = other.length;
         ray_disabled = other.ray_disabled;
         return *this;
      }

      // Render functions

      /// @brief Render ray and origin.
      /// @param window Window to draw to.
      /// @param color Color of ray and origin.
      inline void render(sf::RenderWindow& window,
                         const Color& color = Color(255)) const
      {
         sf::VertexArray line (sf::LineStrip, 2);

         line[0].position = origin;
         line[0].color = color;
         line[1].position = get_end_point();
         line[1].color = color;

         sf::RectangleShape point (Vec2f(10.f));
         point.setOrigin(5.f, 5.f);
         point.setPosition(origin);
         point.setRotation(get_rotation());
         point.setFillColor(color);

         window.draw(point);

         if (!ray_disabled)
            window.draw(line);
      }

   private:
      Vec2f origin;
      Vec2f direction;
      float length = 0.f;
      bool ray_disabled = false;
   };
}

#endif
