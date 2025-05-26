#ifndef CX_TEXT_FONT_STYLE_HPP
#define CX_TEXT_FONT_STYLE_HPP

namespace cx
{
   /// @brief Font styles.
   enum class FontStyle : char
   {
      regular = 0,       ///< @brief No style.
      bold = 1,          ///< @brief Bold.
      italic = 2,        ///< @brief Italic.
      underlined = 4,    ///< @brief Underlined.
      strikeThrough = 8, ///< @brief Strike through.
   };
}

#endif
