#ifndef CX_RAY_RAYCAST_RESULT_HPP
#define CX_RAY_RAYCAST_RESULT_HPP

#include "CX/Vector/Vec2.hpp"

namespace cx
{
   /// @brief Get ray info from raycasts.
   struct RaycastResult
   {
      /// @brief Is ray colliding.
      bool colliding = false;

      /// @brief Distance from origin to collision point.
      float distance = 0.f;

      /// @brief How far the ray traveled inside the object.
      float penetration = 0.f;

      /// @brief Ray collision point.
      std::optional<Vec2f> collision_point = std::optional<Vec2f>();

      /// @brief Ray exit point.
      std::optional<Vec2f> exit_point = std::optional<Vec2f>();

      /// @brief Normal of the hit surface.
      std::optional<Vec2f> normal = std::optional<Vec2f>();

      /// @brief Ray reflection direction.
      std::optional<Vec2f> reflected_dir = std::optional<Vec2f>();
   };
}

#endif
