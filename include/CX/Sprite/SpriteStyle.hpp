#ifndef CX_SPRITE_SPRITE_STYLE_HPP
#define CX_SPRITE_SPRITE_STYLE_HPP

#include "CX/Color.hpp"
#include "CX/Vector/Vec4.hpp"
#include <memory>

namespace sf
{
   class Texture;
}

namespace cx
{
   /// @brief Save styles between sprites.
   struct SpriteStyle
   {
   private:
      /// @brief Global overridable styles.
      static std::unique_ptr<SpriteStyle> style1_t, style2_t, style3_t;
   public:

      /// @brief Size of the sprite.
      Vec2f size = Vec2f(50.f);

      /// @brief Texture of the sprite.
      std::shared_ptr<sf::Texture> texture;

      /// @brief Texture rect of the sprite.
      Vec4i texture_rect;

      /// @brief Color of the sprite.
      Color color = Color(255);

      /// @brief Access first style.
      /// @return First style.
      static SpriteStyle& style1()
      {
         if (!style1_t)
            style1_t = std::make_unique<SpriteStyle>();
         return *style1_t;
      }

      /// @brief Access second style.
      /// @return Second style.
      static SpriteStyle& style2()
      {
         if (!style2_t)
            style2_t = std::make_unique<SpriteStyle>();
         return *style2_t;
      }

      /// @brief Access third style.
      /// @return Third style.
      static SpriteStyle& style3()
      {
         if (!style3_t)
            style3_t = std::make_unique<SpriteStyle>();
         return *style3_t;
      }
   };
}

#endif
