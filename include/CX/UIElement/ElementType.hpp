#ifndef CX_UI_ELEMENT_ELEMENT_TYPE_HPP
#define CX_UI_ELEMENT_ELEMENT_TYPE_HPP

namespace cx
{
   /// @brief Enumeration of all UIElements.
   enum class ElementType : char
   {
      rect,       ///< @brief Rectangle class.
      text,       ///< @brief Text class.
      sprite,     ///< @brief Sprite class.
      button,     ///< @brief Button class.
      bar,        ///< @brief Bar class.
      slider,     ///< @brief Slider class.
      text_input, ///< @brief Text input class.
      circle,     ///< @brief Circle class.
      plane       ///< @brief Plane class.
   };
}

#endif
