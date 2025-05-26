#ifndef CX_EVENTHANDLER_MOUSE_HPP
#define CX_EVENTHANDLER_MOUSE_HPP

#include "CX/Vector/Vec2.hpp"

namespace cx
{
   /// @brief Mouse button codes.
   enum class Mouse : char
   {
      left,    ///< @brief Left mouse button.
      right,   ///< @brief Right mouse button.
      middle,  ///< @brief Scrollwheel button.
      extra1,  ///< @brief First extra button.
      extra2,  ///< @brief Second extra button.
      unknown, ///< @brief Unknown button.
      total    ///< @brief Button count.
   };

   /// @brief The mouse mode.
   enum class MouseMode : char
   {
      free,    ///< @brief Free mouse.
      grabbed, ///< @brief Locked in the window.
      locked,  ///< @brief Locked in the center.
   };

   /// @brief State of the mouse.
   struct MouseState
   {
      Mouse button;             ///< @brief Mouse button.
      Vec2f position;           ///< @brief Mouse position.
      bool is_pressed  = false; ///< @brief Was button just pressed.
      bool is_released = false; ///< @brief Was button just released.
      bool is_down     = false; ///< @brief Is button down.
   };
}

#endif
