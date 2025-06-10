#include "CX/Circle/Circle.hpp"

namespace cx
{
   // Set default styles

   std::unique_ptr<CircleStyle> CircleStyle::style1_t;
   std::unique_ptr<CircleStyle> CircleStyle::style2_t;
   std::unique_ptr<CircleStyle> CircleStyle::style3_t;

   // Constructors

   Circle::Circle() {}

   Circle::Circle(const CircleStyle& style)
   {
      circle.setRadius(style.radius);
      circle.setOrigin(Vec2f(style.radius));
      circle.setPointCount(style.point_count);
      circle.setFillColor(style.color);
      circle.setTexture(style.texture.get());
   }

   Circle::Circle(float radius,
                  const Vec2f& position,
                  const Color& color,
                  size_t point_count)
   {
      circle.setRadius(radius);
      circle.setOrigin(Vec2f(radius));
      circle.setPosition(position);
      circle.setPointCount(point_count);
      circle.setFillColor(color);
   }

   // Constructors after creation

   void Circle::create(const CircleStyle& style)
   {
      circle.setRadius(style.radius);
      circle.setOrigin(Vec2f(style.radius));
      circle.setPointCount(style.point_count);
      circle.setFillColor(style.color);
      circle.setTexture(style.texture.get());
   }

   void Circle::create(float radius,
                       const Vec2f& position,
                       const Color& color,
                       size_t point_count)
   {
      circle.setRadius(radius);
      circle.setOrigin(Vec2f(radius));
      circle.setPosition(position);
      circle.setPointCount(point_count);
      circle.setFillColor(color);
   }

   // Setter functions

   void Circle::set_center(const Vec2f& position)
   {
      circle.setPosition(position);
   }

   void Circle::set_scale(const Vec2f& scale)
   {
      circle.setScale(scale);
   }

   void Circle::set_size(const Vec2f& size)
   {
      circle.setScale(size / get_size());
   }

   void Circle::set_rotation(float angle)
   {
      circle.setRotation(angle);
   }

   void Circle::set_texture(const sf::Texture* texture)
   {
      circle.setTexture(texture);
   }

   void Circle::set_texture_rect(const Vec4i& rect)
   {
      circle.setTextureRect(rect);
   }

   void Circle::set_color(const Color& color)
   {
      circle.setFillColor(color);
   }

   void Circle::set_radius(float radius)
   {
      circle.setRadius(radius);
      circle.setOrigin(Vec2f(radius));
   }

   void Circle::set_point_count(size_t point_count)
   {
      circle.setPointCount(point_count);
   }

   // Getter functions

   ElementType Circle::get_element_type() const
   {
      return ElementType::circle;
   }

   Vec2f Circle::get_center() const
   {
      return circle.getPosition();
   }

   Vec2f Circle::get_scale() const
   {
      return circle.getScale();
   }

   Vec2f Circle::get_size() const
   {
      return get_scale().abs() * (circle.getRadius() * 2.f);
   }

   Vec2f Circle::get_origin() const
   {
      return get_scale().abs() * circle.getOrigin();
   }

   Deg Circle::get_rotation() const
   {
      return circle.getRotation();
   }

   Vec2f Circle::get_half_size() const
   {
      return get_scale().abs() * circle.getRadius();
   }

   // This function is defined in 'UIElement.cpp'
   // CircleBounds Circle::get_circle_bounds() const
   // {
   //    return ...;
   // }

   const sf::Texture* Circle::get_texture() const
   {
      return circle.getTexture();
   }

   Vec4i Circle::get_texture_rect() const
   {
      return circle.getTextureRect();
   }

   Color Circle::get_color() const
   {
      return circle.getFillColor();
   }

   float Circle::get_radius() const
   {
      return circle.getRadius();
   }

   size_t Circle::get_point_count() const
   {
      return circle.getPointCount();
   }

   // Update functions

   void Circle::update(const MouseState& state, bool local)
   {
      update_state(state, local);
   }

   // Render functions

   void Circle::render(sf::RenderWindow& window) const
   {
      window.draw(circle);
   }

   void Circle::render(sf::RenderWindow& window, const sf::Shader* shader) const
   {
      window.draw(circle, shader);
   }

   // Access functions

   sf::CircleShape& Circle::get_circle()
   {
      return circle;
   }
}
