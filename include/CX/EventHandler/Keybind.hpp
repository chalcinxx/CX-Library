#ifndef CX_EVENTHANDLER_KEYBIND_HPP
#define CX_EVENTHANDLER_KEYBIND_HPP

#include "CX/EventHandler/Key.hpp"
#include <vector>

namespace cx
{
   /// @brief Keybind for combining key input.
   struct Keybind
   {
      std::vector<Key> hold_keys; ///< @brief Keys that must be held down.
      Key key;                    ///< @brief Main key.

      // Constructors

      /// @brief Create a default keybind.
      constexpr Keybind() = default;

      /// @brief Create a keybind.
      /// @param hold_keys Keys that must be held down.
      /// @param key Main key.
      constexpr Keybind(const std::vector<Key>& hold_keys, Key key)
         : hold_keys(hold_keys), key(key) {}

      /// @brief Create a keybind.
      /// @param hold_key Key that must be held down.
      /// @param key Main key.
      constexpr Keybind(Key hold_key, Key key)
         : hold_keys({hold_key}), key(key) {}

      ~Keybind() = default;
   };
}

#endif
