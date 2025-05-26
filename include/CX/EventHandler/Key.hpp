#ifndef CX_EVENTHANDLER_KEY_HPP
#define CX_EVENTHANDLER_KEY_HPP

namespace cx
{
   /// @brief Keyboard key codes. 
   enum class Key : char
   {
      a,               ///< @brief `a` key.
      b,               ///< @brief `b` key.
      c,               ///< @brief `c` key.
      d,               ///< @brief `d` key.
      e,               ///< @brief `e` key.
      f,               ///< @brief `f` key.
      g,               ///< @brief `g` key.
      h,               ///< @brief `h` key.
      i,               ///< @brief `i` key.
      j,               ///< @brief `j` key.
      k,               ///< @brief `k` key.
      l,               ///< @brief `l` key.
      m,               ///< @brief `m` key.
      n,               ///< @brief `n` key.
      o,               ///< @brief `o` key.
      p,               ///< @brief `p` key.
      q,               ///< @brief `q` key.
      r,               ///< @brief `r` key.
      s,               ///< @brief `s` key.
      t,               ///< @brief `t` key.
      u,               ///< @brief `u` key.
      v,               ///< @brief `v` key.
      w,               ///< @brief `w` key.
      x,               ///< @brief `x` key.
      y,               ///< @brief `y` key.
      z,               ///< @brief `z` key.
      zero,            ///< @brief `0` key.
      one,             ///< @brief `1` key.
      two,             ///< @brief `2` key.
      three,           ///< @brief `3` key.
      four,            ///< @brief `4` key.
      five,            ///< @brief `5` key.
      six,             ///< @brief `6` key.
      seven,           ///< @brief `7` key.
      eight,           ///< @brief `8` key.
      nine,            ///< @brief `9` key.
      escape,          ///< @brief `esc` key.
      l_control,        ///< @brief Left control key.
      l_shift,          ///< @brief Left shift key.
      l_alt,            ///< @brief Left alt key.
      l_super,          ///< @brief Left OS specific key.
      esc = escape,    ///< @brief `esc` key.
      ctrl = l_control, ///< @brief Left control key.
      shift = l_shift,  ///< @brief Left shift key.
      alt = l_alt,      ///< @brief Left alt key.
      super = l_super,  ///< @brief Left OS specific key.
      r_control,        ///< @brief Right control key.
      r_shift,          ///< @brief Right shift key.
      r_alt,            ///< @brief Right alt key.
      r_super,          ///< @brief Right OS specific key.
      menu,            ///< @brief Menu key.
      l_bracket,        ///< @brief `[` key.
      r_bracket,        ///< @brief `]` key.
      semicolon,       ///< @brief `;` key.
      comma,           ///< @brief `,` key.
      period,          ///< @brief `.` key.
      dot = period,    ///< @brief `.` key.
      apostrophe,      ///< @brief `'` key.
      slash,           ///< @brief `/` key.
      backslash,       ///< @brief `\` key.
      grave,           ///< @brief `~` key.
      equal,           ///< @brief `=` key.
      hyphen,          ///< @brief `-` key.
      space,           ///< @brief Space key.
      enter,           ///< @brief `enter` key.
      backspace,       ///< @brief `backspace` key.
      tab,             ///< @brief `tab` key.
      pageup,          ///< @brief `pg up` key.
      pagedown,        ///< @brief `pg dn` key.
      end,             ///< @brief `end` key.
      home,            ///< @brief `home` key.
      insert,          ///< @brief `ins` key.
      del,             ///< @brief `delete` or `del` key.
      add,             ///< @brief `+` key on the numpad.
      subtract,        ///< @brief `-` key on the numpad.
      multiply,        ///< @brief `*` key on the numpad
      divide,          ///< @brief `/` key on the numpad
      left,            ///< @brief `left` arrow key.
      right,           ///< @brief `right` arrow key.
      up,              ///< @brief `up` arrow key.
      down,            ///< @brief `down` arrow key.
      num0,            ///< @brief `0` key on the numpad
      num1,            ///< @brief `1` key on the numpad
      num2,            ///< @brief `2` key on the numpad
      num3,            ///< @brief `3` key on the numpad
      num4,            ///< @brief `4` key on the numpad
      num5,            ///< @brief `5` key on the numpad
      num6,            ///< @brief `6` key on the numpad
      num7,            ///< @brief `7` key on the numpad
      num8,            ///< @brief `8` key on the numpad
      num9,            ///< @brief `9` key on the numpad
      f1,              ///< @brief `f1` key.
      f2,              ///< @brief `f2` key.
      f3,              ///< @brief `f3` key.
      f4,              ///< @brief `f4` key.
      f5,              ///< @brief `f5` key.
      f6,              ///< @brief `f6` key.
      f7,              ///< @brief `f7` key.
      f8,              ///< @brief `f8` key.
      f9,              ///< @brief `f9` key.
      f10,             ///< @brief `f10` key.
      f11,             ///< @brief `f11` key.
      f12,             ///< @brief `f12` key.
      f13,             ///< @brief `f13` key.
      f14,             ///< @brief `f14` key.
      f15,             ///< @brief `f15` key.
      pause,           ///< @brief Pause key.
      unknown,         ///< @brief Unknown key.
      total            ///< @brief Key count.
   };

   /// @brief State of a keyboard key.
   struct KeyState
   {
      Key key;                  ///< @brief Keyboard key.
      bool is_pressed  = false; ///< @brief Was key just pressed.
      bool is_released = false; ///< @brief Was key just released.
      bool is_down     = false; ///< @brief Is key down.
   };
}

#endif
