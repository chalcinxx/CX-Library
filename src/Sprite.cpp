#include "CX/Sprite/Sprite.hpp"

namespace cx
{
   /// Set default styles

   std::unique_ptr<SpriteStyle> SpriteStyle::style1_t;
   std::unique_ptr<SpriteStyle> SpriteStyle::style2_t;
   std::unique_ptr<SpriteStyle> SpriteStyle::style3_t;

   static const std::string empty_string;

   // Constructors

   Sprite::Sprite()
   {
      rect.setOutlineColor(Color(0));
   }

   Sprite::Sprite(const SpriteStyle& style,
                  const Functions& functions)
   {
      rect.setSize(style.size);
      rect.setOrigin(style.size * .5f);
      rect.setFillColor(style.color);
      rect.setOutlineColor(style.outline_color);
      rect.setOutlineThickness(style.outline_thickness);
      rect.setTexture(style.texture.get());

      if (!style.texture_rect.empty())
         rect.setTextureRect(style.texture_rect);
      set_functions(functions);
   }

   Sprite::Sprite(const Vec2f& size,
                  const Vec2f& position,
                  const sf::Texture* texture,
                  const Vec4i& texture_rect,
                  const Functions& functions)
   {
      rect.setPosition(position);
      rect.setSize(size);
      rect.setOrigin(size * .5f);
      rect.setTexture(texture);
      rect.setOutlineColor(Color(0));

      if (!texture_rect.empty())
         rect.setTextureRect(texture_rect);
      set_functions(functions);
   }

   // Constructors after creation

   void Sprite::create(const SpriteStyle& style,
                       const Functions& functions)
   {
      rect.setSize(style.size);
      rect.setOrigin(style.size * .5f);
      rect.setFillColor(style.color);
      rect.setOutlineColor(style.outline_color);
      rect.setOutlineThickness(style.outline_thickness);
      rect.setTexture(style.texture.get());

      if (!style.texture_rect.empty())
         rect.setTextureRect(style.texture_rect);
      set_functions(functions);
   }

   void Sprite::create(const Vec2f& size,
                       const Vec2f& position,
                       const sf::Texture* texture,
                       const Vec4i& textureRect,
                       const Functions& functions)
   {
      rect.setPosition(position);
      rect.setSize(size);
      rect.setOrigin(size * .5f);
      rect.setTexture(texture);
      rect.setOutlineColor(Color(0));

      if (!textureRect.empty())
         rect.setTextureRect(textureRect);
      set_functions(functions);
   }

   // Setter functions

   void Sprite::set_center(const Vec2f& position)
   {
      rect.setPosition(position);   
   }

   void Sprite::set_top_left(const Vec2f& position)
   {
      rect.setPosition(position + rect.getOrigin());
   }

   void Sprite::set_bottom_right(const Vec2f& position)
   {
      rect.setPosition(position - rect.getOrigin());
   }

   void Sprite::set_scale(const Vec2f& scale)
   {
      rect.setScale(scale);
   }

   void Sprite::set_size(const Vec2f& size)
   {
      rect.setSize(size);
      rect.setOrigin(size * .5f);
   }

   void Sprite::set_rotation(float angle)
   {
      rect.setRotation(angle);
   }

   void Sprite::set_texture(const sf::Texture* texture)
   {
      rect.setTexture(texture);
   }

   void Sprite::set_texture_rect(const Vec4i& rect_)
   {
      rect.setTextureRect(rect_);
   }

   void Sprite::set_color(const Color& color)
   {
      rect.setFillColor(color);
   }

   void Sprite::set_outline_color(const Color& color)
   {
      rect.setOutlineColor(color);
   }

   void Sprite::set_outline_thickness(float thickness)
   {
      rect.setOutlineThickness(thickness);
   }

   // Getter functions

   ElementType Sprite::get_element_type() const
   {
      return ElementType::sprite;
   }

   Vec2f Sprite::get_center() const
   {
      return rect.getPosition();
   }

   Vec2f Sprite::get_top_left() const
   {
      return rect.getPosition() - rect.getOrigin();
   }

   Vec2f Sprite::get_bottom_right() const
   {
      return rect.getPosition() + rect.getOrigin();
   }

   Vec2f Sprite::get_scale() const
   {
      return rect.getScale();
   }

   Vec2f Sprite::get_size() const
   {
      return rect.getSize();
   }

   Vec2f Sprite::get_origin() const
   {
      return rect.getOrigin();
   }

   Degrees Sprite::get_rotation() const
   {
      return rect.getRotation();
   }

   const sf::Texture* Sprite::get_texture() const
   {
      return rect.getTexture();
   }

   Vec4i Sprite::get_texture_rect() const
   {
      return rect.getTextureRect();
   }

   Color Sprite::get_color() const
   {
      return rect.getFillColor();
   }

   Color Sprite::get_outline_color() const
   {
      return rect.getOutlineColor();
   }

   float Sprite::get_outline_thickness() const
   {
      return rect.getOutlineThickness();
   }

   // Update functions

   void Sprite::update(const MouseState& state, bool local)
   {
      update_state(state, local);
   }

   void Sprite::update_all(float dt, const MouseState& state, bool local)
   {
      update_state(state, local);
      update_animation(dt);
   }

   void Sprite::update_animation(float dt)
   {
      if (!playing || !animations.contains(current_animation))
         return;

      elapsedTime += dt;

      if (elapsedTime * speedMult >= animations.at(current_animation).speed)
         advance_frame();
   }

   void Sprite::play()
   {
      if (!current_animation.empty())
         playing = true;
   }

   void Sprite::pause()
   {
      if (!current_animation.empty())
         playing = false;
   }

   void Sprite::reset()
   {
      playing = !idle.empty();
      index = 0;
      elapsedTime = 0.f;

      if (!animations.contains(current_animation))
      {
         const Animation& anim {animations.at(current_animation)};
         rect.setTextureRect(Vec4i(anim.posX, anim.posY, anim.sizeX, anim.sizeY));
      }

      current_animation = idle;
   }

   void Sprite::advance_frame()
   {
      if (!animations.contains(current_animation))
         return;
      const Animation& anim {animations.at(current_animation)};

      elapsedTime = 0.f;

      if (anim.reversed)
         index = (index - 1 + anim.length) % anim.length;
      else
         index = (index + 1) % anim.length;

      rect.setTextureRect(Vec4i(
         anim.posX + (anim.gap * static_cast<unsigned>(index)) + (anim.sizeX * static_cast<unsigned>(index)),
         anim.posY,
         anim.sizeX,
         anim.sizeY
      ));

      if (!(index == anim.length - 1 && !anim.reversed) && !(index == 0 && anim.reversed))
         return;

      if (anim.looping)
         return;

      elapsedTime = 0.f;
      index = 0;

      rect.setTextureRect(Vec4i(anim.posX, anim.posY, anim.sizeX, anim.sizeY));

      if (animations.contains(idle))
         current_animation = idle;
      else
      {
         playing = false;
         current_animation = "";
      }
   }

   void Sprite::add_animation(const std::string& identifier,
                              const Animation& animation,
                              bool default_animation)
   {
      if (!animations.contains(identifier))
         animations.emplace(identifier, animation);

      if (default_animation)
      {
         current_animation = idle = identifier;
         playing = true;
      }
   }

   void Sprite::set_default_animation(const std::string& identifier)
   {
      current_animation = idle = identifier;
      playing = true;
   }

   void Sprite::play_animation(const std::string& identifier, bool reset)
   {
      if (!reset && identifier == current_animation)
         return;

      if (animations.contains(identifier) && (current_animation != identifier
         || !animations.at(identifier).looping))
      {
         index = 0;
         elapsedTime = 0.f;
      }

      current_animation = identifier;
      playing = true;
   }

   bool Sprite::is_animation_finished() const
   {
      return !playing && !animations.contains(current_animation);
   }

   bool Sprite::is_default_playing() const
   {
      return playing && animations.contains(current_animation) && current_animation == idle;
   }

   bool Sprite::is_playing() const
   {
      return playing && animations.contains(current_animation);
   }

   bool Sprite::is_paused() const
   {
      return !playing && animations.contains(current_animation);
   }

   void Sprite::set_speed_multiplier(float multiplier)
   {
      speedMult = multiplier;
   }

   size_t Sprite::get_frame_index() const
   {
      return index;
   }

   float Sprite::get_speed_multiplier() const
   {
      return speedMult;
   }

   const std::string& Sprite::get_playing_animation() const
   {
      return (is_playing() ? current_animation : empty_string);
   }

   const std::string& Sprite::get_default_animation() const
   {
      return idle;
   }

   void Sprite::clear_animations()
   {
      playing = false;
      index = 0;
      elapsedTime = 0.f;
      current_animation = idle = "";
      animations.clear();
   }

   // Render functions

   void Sprite::render(sf::RenderWindow& window) const
   {
      window.draw(rect);
   }

   void Sprite::render(sf::RenderWindow& window, const sf::Shader* shader) const
   {
      window.draw(rect, shader);
   }

   // Access functions

   sf::RectangleShape& Sprite::get_sprite()
   {
      return rect;
   }

   std::unordered_map<std::string, Animation>& Sprite::get_animations()
   {
      return animations;
   }
}
