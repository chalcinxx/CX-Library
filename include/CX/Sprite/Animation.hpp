#ifndef CX_SPRITE_ANIMATION_HPP
#define CX_SPRITE_ANIMATION_HPP

namespace cx
{
   /// @brief Save animations for sprites.
   struct Animation
   {
      unsigned length {}; ///< @brief Animation length in frames.
      unsigned gap {};    ///< @brief Gap between frames.
      unsigned sizeX {};  ///< @brief Frame width.
      unsigned sizeY {};  ///< @brief Frame height.
      unsigned posX {};   ///< @brief Left position of first frame.
      unsigned posY {};   ///< @brief Top position of first frame.
      float speed {};     ///< @brief Time between frames.
      bool looping {};    ///< @brief Should animation loop.
      bool reversed {};   ///< @brief Should animation be reversed.
   };  
}

#endif
