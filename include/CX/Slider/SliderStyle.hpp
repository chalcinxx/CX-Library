#ifndef CX_SLIDER_SLIDER_STYLE_HPP
#define CX_SLIDER_SLIDER_STYLE_HPP

#include "CX/Color.hpp"
#include "CX/Vector/Vec2.hpp"
#include <memory>

namespace sf
{
   class Texture;
}

namespace cx
{
   /// @brief Save styles between slides.
   struct SliderStyle
   {
   private:
      /// @brief Global overridable styles.
      static std::unique_ptr<SliderStyle> style1_t, style2_t, style3_t;
   public:

      /// @brief Size of the slider.
      Vec2f size = Vec2f(250.f, 25.f);

      /// @brief Size of the knob.
      Vec2f knob_size = Vec2f(25.f);

      /// @brief Color of the foreground.
      Color fg_color = Color(255);

      /// @brief Color of the background.
      Color bg_color = Color(0);

      /// @brief Color of the knob.
      Color knob_color = Color(125);

      /// @brief Outline color of the foreground.
      Color fg_outline_color = Color(0);

      /// @brief Outline color of the background.
      Color bg_outline_color = Color(0);

      /// @brief Outline color of the knob.
      Color knob_outline_color = Color(0);

      /// @brief Outline thickness of the foreground.
      float fg_outline_thickness = 0.f;
      
      /// @brief Outline thickness of the background.
      float bg_outline_thickness = 0.f;

      /// @brief Outline thickness of the knob.
      float knob_outline_thickness = 0.f;

      /// @brief Texture of the foreground.
      std::shared_ptr<sf::Texture> fg_texture;

      /// @brief Texture of the background.
      std::shared_ptr<sf::Texture> bg_texture;

      /// @brief Texture of the knob.
      std::shared_ptr<sf::Texture> knob_texture;

      /// @brief Access first style.
      /// @return First style.
      static SliderStyle& style1()
      {
         if (!style1_t)
            style1_t = std::make_unique<SliderStyle>();
         return *style1_t;
      }

      /// @brief Access second style.
      /// @return Second style.
      static SliderStyle& style2()
      {
         if (!style2_t)
            style2_t = std::make_unique<SliderStyle>();
         return *style2_t;
      }

      /// @brief Access third style.
      /// @return Third style.
      static SliderStyle& style3()
      {
         if (!style3_t)
            style3_t = std::make_unique<SliderStyle>();
         return *style3_t;
      }
   };
}

#endif
