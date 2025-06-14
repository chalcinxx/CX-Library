#include "CX/Rect/Rect.hpp"

namespace cx
{
   // Set default styles

   std::unique_ptr<RectStyle> RectStyle::style1_t;
   std::unique_ptr<RectStyle> RectStyle::style2_t;
   std::unique_ptr<RectStyle> RectStyle::style3_t;

   // Constructors

   Rect::Rect() {}

   Rect::Rect(const RectStyle& style)
   {
      rect.setSize(style.size);
      rect.setOrigin(style.size * .5f);
      rect.setFillColor(style.color);
      rect.setTexture(style.texture.get());
   }

   Rect::Rect(const Vec2f& size,
              const Vec2f& position,
              const Color& color)
   {
      rect.setPosition(position);
      rect.setSize(size);
      rect.setOrigin(size * .5f);
      rect.setFillColor(color);
   }

   // Constructors after creation

   void Rect::create(const RectStyle& style)
   {
      rect.setSize(style.size);
      rect.setOrigin(style.size * .5f);
      rect.setFillColor(style.color);
      rect.setTexture(style.texture.get());
   }

   void Rect::create(const Vec2f& size,
                     const Vec2f& position,
                     const Color& color)
   {
      rect.setPosition(position);
      rect.setSize(size);
      rect.setOrigin(size * .5f);
      rect.setFillColor(color);
   }

   // Setter functions

   void Rect::set_center(const Vec2f& position)
   {
      rect.setPosition(position);
   }

   void Rect::set_scale(const Vec2f& scale)
   {
      rect.setScale(scale);
   }

   void Rect::set_size(const Vec2f& size)
   {
      rect.setSize(size);
      rect.setOrigin(size * .5f);
   }

   void Rect::set_rotation(float angle)
   {
      rect.setRotation(angle);
   }

   void Rect::set_texture(const sf::Texture* texture)
   {
      rect.setTexture(texture);
   }

   void Rect::set_texture_rect(const Vec4i& rect_)
   {
      rect.setTextureRect(rect_);
   }

   void Rect::set_color(const Color& color)
   {
      rect.setFillColor(color);
   }

   // Getter functions

   ElementType Rect::get_element_type() const
   {
      return ElementType::rect;
   }

   Vec2f Rect::get_center() const
   {
      return rect.getPosition();
   }

   Vec2f Rect::get_scale() const
   {
      return rect.getScale();
   }

   Vec2f Rect::get_size() const
   {
      return get_scale().abs() * rect.getSize();
   }

   Vec2f Rect::get_origin() const
   {
      return get_scale().abs() * rect.getOrigin();
   }

   Deg Rect::get_rotation() const
   {
      return rect.getRotation();
   }

   const sf::Texture* Rect::get_texture() const
   {
      return rect.getTexture();
   }

   Vec4i Rect::get_texture_rect() const
   {
      return rect.getTextureRect();
   }

   Color Rect::get_color() const
   {
      return rect.getFillColor();
   }

   // Update functions

   void Rect::update(const MouseState& state, bool local)
   {
      update_state(state, local);
   }

   // Render functions

   void Rect::render(sf::RenderWindow& window) const
   {
      window.draw(rect);
   }

   void Rect::render(sf::RenderWindow& window, const sf::Shader* shader) const
   {
      window.draw(rect, shader);
   }

   // Access functions

   sf::RectangleShape& Rect::get_rectangle()
   {
      return rect;
   }
}
