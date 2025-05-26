#ifndef CX_EVENTHANDLER_CONTROLLER_HPP
#define CX_EVENTHANDLER_CONTROLLER_HPP

namespace cx
{
   /// @brief Xbox controller buttons.
   enum class Controller : char
   {
      a,            ///< @brief A button.
      b,            ///< @brief B button.
      x,            ///< @brief X button.
      y,            ///< @brief Y button.
      lb,           ///< @brief `lb` button.
      rb,           ///< @brief `rb` button.
      back,         ///< @brief Button left to `xbox` button.
      menu,         ///< @brief Button right to `xbox` button.
      guide,        ///< @brief `home` or `xbox` button.
      home = guide, ///< @brief `home` or `xbox` button.
      xbox = guide, ///< @brief `home` or `xbox` button.
      ls,           ///< @brief Left joystick.
      rs,           ///< @brief Right joystick.
      left,         ///< @brief `left` Dpad button.
      right,        ///< @brief `right` Dpad button.
      up,           ///< @brief `up` Dpad button.
      down,         ///< @brief `down` Dpad button.
      unknown,      ///< @brief Unknown button.
      total         ///< @brief Button count.
   };

   /// @brief Controller axes.
   enum class ControllerAxis : char
   {
      ls_x,     ///< @brief Left joystick X axis.
      ls_y,     ///< @brief Left joystick Y axis.
      lt,       ///< @brief `lt` trigger.
      rt,       ///< @brief `rt` trigger.
      rs_x,     ///< @brief Right joystick X axis.
      rs_y,     ///< @brief Right joystick Y axis.
      dpad_x,   ///< @brief Dpad `left` and `right` buttons.
      dpad_y,   ///< @brief Dpad `up` and `down` buttons.
      unknown,  ///< @brief Unknown axis.
      total     ///< @brief Axis count.
   };

   /// @brief Controller vectors.
   enum class ControllerVector : char
   {
      ls,       ///< @brief Left joystick.
      triggers, ///< @brief Triggers `lt` and `rt`.
      rs,       ///< @brief Right joystick.
      dpad,     ///< @brief Dpad.
      unknown,  ///< @brief Unknown vector.
      total     ///< @brief Vector count.
   };

   /// @brief State of a controller button.
   struct ControllerState
   {
      Controller key;           ///< @brief Controller button.
      bool is_pressed  = false; ///< @brief Was button just pressed.
      bool is_released = false; ///< @brief Was button just released.
      bool is_down     = false; ///< @brief Is button down.
   };
}

#endif
