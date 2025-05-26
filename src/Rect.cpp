#include "CX/Rect/Rect.hpp"

namespace cx
{
   // Set default styles

   std::unique_ptr<RectStyle> RectStyle::style1_t;
   std::unique_ptr<RectStyle> RectStyle::style2_t;
   std::unique_ptr<RectStyle> RectStyle::style3_t;

   // Constructors

   Rect::Rect()
   {
      rect.setOutlineColor(Color(0));
   }

   Rect::Rect(const RectStyle& style,
              const Functions& functions)
   {
      rect.setSize(style.size);
      rect.setOrigin(style.size * .5f);
      rect.setFillColor(style.color);
      rect.setOutlineColor(style.outline_color);
      rect.setOutlineThickness(style.outline_thickness);
      rect.setTexture(style.texture.get());
      set_functions(functions);
   }

   Rect::Rect(const Vec2f& size,
              const Vec2f& position,
              const Color& color,
              const Functions& functions)
   {
      rect.setPosition(position);
      rect.setSize(size);
      rect.setOrigin(size * .5f);
      rect.setFillColor(color);
      rect.setOutlineColor(Color(0));
      set_functions(functions);
   }

   // Constructors after creation

   void Rect::create(const RectStyle& style,
                     const Functions& functions)
   {
      rect.setSize(style.size);
      rect.setOrigin(style.size * .5f);
      rect.setFillColor(style.color);
      rect.setOutlineColor(style.outline_color);
      rect.setOutlineThickness(style.outline_thickness);
      rect.setTexture(style.texture.get());
      set_functions(functions);
   }

   void Rect::create(const Vec2f& size,
                     const Vec2f& position,
                     const Color& color,
                     const Functions& functions)
   {
      rect.setPosition(position);
      rect.setSize(size);
      rect.setOrigin(size * .5f);
      rect.setFillColor(color);
      rect.setOutlineColor(Color(0));
      set_functions(functions);
   }

   // Setter functions

   void Rect::set_center(const Vec2f& position)
   {
      rect.setPosition(position);
   }

   void Rect::set_top_left(const Vec2f& position)
   {
      rect.setPosition(position + rect.getOrigin());
   }

   void Rect::set_bottom_right(const Vec2f& position)
   {
      rect.setPosition(position - rect.getOrigin());
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

   void Rect::set_outline_color(const Color& color)
   {
      rect.setOutlineColor(color);
   }

   void Rect::set_outline_thickness(float thickness)
   {
      rect.setOutlineThickness(thickness);
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

   Vec2f Rect::get_top_left() const
   {
      return rect.getPosition() - rect.getOrigin();
   }

   Vec2f Rect::get_bottom_right() const
   {
      return rect.getPosition() + rect.getOrigin();
   }

   Vec2f Rect::get_scale() const
   {
      return rect.getScale();
   }

   Vec2f Rect::get_size() const
   {
      return rect.getSize();
   }

   Vec2f Rect::get_origin() const
   {
      return rect.getOrigin();
   }

   Degrees Rect::get_rotation() const
   {
      return Degrees(rect.getRotation());
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

   Color Rect::get_outline_color() const
   {
      return rect.getOutlineColor();
   }

   float Rect::get_outline_thickness() const
   {
      return rect.getOutlineThickness();
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

   void Rect::render(sf::RenderWindow& window,
                     const sf::Shader* shader) const
   {
      window.draw(rect, shader);
   }

   // Access functions

   sf::RectangleShape& Rect::get_rectangle()
   {
      return rect;
   }
}
