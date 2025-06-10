#include "CX/Plane/Plane.hpp"

#include <SFML/Graphics/Texture.hpp>
#include "CX/Vector/Vec3.hpp"

namespace cx
{
   // Set default styles

   std::unique_ptr<PlaneStyle> PlaneStyle::style1_t;
   std::unique_ptr<PlaneStyle> PlaneStyle::style2_t;
   std::unique_ptr<PlaneStyle> PlaneStyle::style3_t;

   // Constructors

   Plane::Plane()
   {
      rect.setPrimitiveType(sf::PrimitiveType::Quads);
      rect.resize(4);
   }

   Plane::Plane(const PlaneStyle& style)
   {
      rect.setPrimitiveType(sf::PrimitiveType::Quads);
      rect.resize(4);
      this->size = style.size;
      this->skew = style.skew;
      this->color = style.color;
      this->rotation = style.rotation;
      this->texture = style.texture.get();
      redraw();
      recolor();
   }

   Plane::Plane(const Vec2f& size,
                const Vec2f& position,
                const Color& color)
   {
      rect.setPrimitiveType(sf::PrimitiveType::Quads);
      rect.resize(4);
      this->size = size;
      this->center = position;
      this->color = color;
      redraw();
      recolor();
   }

   // Constructors after creation

   void Plane::create(const PlaneStyle& style)
   {
      rect.setPrimitiveType(sf::PrimitiveType::Quads);
      rect.resize(4);
      this->size = style.size;
      this->skew = style.skew;
      this->color = style.color;
      this->rotation = style.rotation;
      this->texture = style.texture.get();
      redraw();
      recolor();
   }

   void Plane::create(const Vec2f& size,
                      const Vec2f& position,
                      const Color& color)
   {
      rect.setPrimitiveType(sf::PrimitiveType::Quads);
      rect.resize(4);
      this->size = size;
      this->center = position;
      this->color = color;
      redraw();
      recolor();
   }

   // Setter functions

   void Plane::set_center(const Vec2f& center)
   {
      this->center = center;
      redraw();
   }

   void Plane::set_scale(const Vec2f& scale)
   {
      this->scale = scale.abs();
      redraw();
   }

   void Plane::set_size(const Vec2f& size)
   {
      this->size = size;
      this->origin = (size * .5f).abs();
      redraw();
   }

   void Plane::set_rotation(float angle)
   {
      this->rotation.z = angle;
      redraw();
   }

   void Plane::set_3d_rotation(const Vec3f& angle)
   {
      this->rotation = angle;
      redraw();
   }

   void Plane::set_3d_rotation(float angle_x, float angle_y, float angle_z)
   {
      set_3d_rotation({angle_x, angle_y, angle_z});
   }

   void Plane::set_3d_rotation(float angle)
   {
      set_3d_rotation({angle, angle, angle});
   }

   void Plane::set_3d_rotation_x(float angle)
   {
      set_3d_rotation({angle, this->rotation.y, this->rotation.z});
   }

   void Plane::set_3d_rotation_y(float angle)
   {
      set_3d_rotation({this->rotation.x, angle, this->rotation.z});
   }

   void Plane::set_3d_rotation_z(float angle)
   {
      set_3d_rotation({this->rotation.x, this->rotation.y, angle});
   }

   void Plane::set_texture(const sf::Texture* texture)
   {
      this->texture = texture;
      this->texture_rect = Vec4i(sf::Vector2u(), this->texture->getSize());
      bind_texture();
   }

   void Plane::set_texture_rect(const Vec4i& rect)
   {
      this->texture_rect = rect;
      bind_texture();
   }

   void Plane::set_color(const Color& color)
   {
      this->color = color;
      recolor();
   }

   void Plane::set_skew(const Vec2f& skew)
   {
      this->skew = skew;
      redraw();
   }

   void Plane::set_skew(float skew_x, float skew_y)
   {
      set_skew({skew_x, skew_y});
   }

   void Plane::set_skew(float skew)
   {
      set_skew({skew, skew});
   }

   void Plane::set_skew_x(float skew)
   {
      set_skew({skew, this->skew.y});
   }

   void Plane::set_skew_y(float skew)
   {
      set_skew({this->skew.x, skew});
   }

   void Plane::set_3d_offset(const Vec3f& offset)
   {
      this->offset = offset;
      redraw(); 
   }

   void Plane::set_3d_offset(float offset_x, float offset_y, float offset_z)
   {
      set_3d_offset({offset_x, offset_y, offset_z});
   }

   void Plane::set_3d_offset(float offset)
   {
      set_3d_offset({offset, offset, offset});
   }

   void Plane::set_3d_offset_x(float offset)
   {
      set_3d_offset({offset, this->offset.y, this->offset.z});
   }

   void Plane::set_3d_offset_y(float offset)
   {
      set_3d_offset({this->offset.x, offset, this->offset.z});
   }

   void Plane::set_3d_offset_z(float offset)
   {
      set_3d_offset({this->offset.x, this->offset.y, offset});
   }

   // Getter functions

   ElementType Plane::get_element_type() const
   {
      return ElementType::plane;
   }

   Vec2f Plane::get_center() const
   {
      return center;
   }

   Vec2f Plane::get_scale() const
   {
      return scale;
   }

   Vec2f Plane::get_size() const
   {
      return Vec2f(rect[2].position - rect[0].position) * scale;
   }

   Vec2f Plane::get_origin() const
   {
      return origin * scale;
   }

   Deg Plane::get_rotation() const
   {
      return rotation.z;
   }

   Vec3f Plane::get_3d_rotation() const
   {
      return rotation;
   }

   Deg Plane::get_3d_rotation_x() const
   {
      return rotation.x;
   }

   Deg Plane::get_3d_rotation_y() const
   {
      return rotation.y;
   }

   Deg Plane::get_3d_rotation_z() const
   {
      return rotation.z;
   }

   const sf::Texture* Plane::get_texture() const
   {
      return texture;
   }

   Vec4i Plane::get_texture_rect() const
   {
      return texture_rect;
   }

   Color Plane::get_color() const
   {
      return color;
   }

   Vec2f Plane::get_skew() const
   {
      return skew;
   }

   float Plane::get_skew_x() const
   {
      return skew.x;
   }

   float Plane::get_skew_y() const
   {
      return skew.y;
   }

   Vec3f Plane::get_3d_offset() const
   {
      return offset;
   }

   float Plane::get_3d_offset_x() const
   {
      return offset.x;
   }

   float Plane::get_3d_offset_y() const
   {
      return offset.y;
   }

   float Plane::get_3d_offset_z() const
   {
      return offset.z;
   }

   // Update functions

   void Plane::update(const MouseState& state, bool local)
   {
      update_state(state, local);
   }

   // Render functions

   void Plane::rotate_3d(const Vec3f& angle)
   {
      set_3d_rotation(rotation + angle);
   }

   void Plane::rotate_3d_x(float angle)
   {
      rotate_3d({angle, 0.f, 0.f});
   }

   void Plane::rotate_3d_y(float angle)
   {
      rotate_3d({0.f, angle, 0.f});
   }

   void Plane::rotate_3d_z(float angle)
   {
      rotate_3d({0.f, 0.f, angle});
   }

   void Plane::render(sf::RenderWindow& window) const
   {
      if (texture)
      {
         sf::RenderStates states;
         states.texture = texture;
         window.draw(rect, states);
      }
      else
         window.draw(rect);
   }

   void Plane::render(sf::RenderWindow& window, const sf::Shader* shader) const
   {
      sf::RenderStates states;
      states.shader = shader;
      if (texture)
         states.texture = texture;

      window.draw(rect, states);
   }

   // Access functions

   sf::VertexArray& Plane::get_plane()
   {
      return rect;
   }

   sf::Vertex& Plane::get_top_left_vertex()
   {
      return rect[0];
   }

   sf::Vertex& Plane::get_top_right_vertex()
   {
      return rect[1];
   }

   sf::Vertex& Plane::get_bottom_right_vertex()
   {
      return rect[2];
   }

   sf::Vertex& Plane::get_bottom_left_vertex()
   {
      return rect[3];
   }

   sf::Vertex& Plane::get_vertex(size_t index)
   {
      return rect[index];
   }

   // Private functions

   void Plane::redraw()
   {
      const auto origin = get_origin();

      Vec3f corners[4] = {
         {-origin.x, -origin.y, 0.f},
         {origin.x, -origin.y, 0.f},
         {origin.x, origin.y, 0.f},
         {-origin.x, origin.y, 0.f}
      };

      const auto radians = Vec3f(cx::Rad::convert(rotation.x), cx::Rad::convert(rotation.y), cx::Rad::convert(rotation.z));

      for (auto& c : corners)
      {
         c = c.rotate(radians) + offset;

         float new_x = c.x + c.y * skew.x;
         float new_y = c.y + c.x * skew.y;
         c.x = new_x;
         c.y = new_y;
      }

      for (size_t i = 0; i < 4; ++i)
         rect[i].position = corners[i].project() + center;
   }

   void Plane::recolor()
   {
      for (size_t i = 0; i < 4; ++i)
         rect[i].color = this->color;
   }

   void Plane::bind_texture()
   {
      rect[0].texCoords = Vec2f(texture_rect.x, texture_rect.y);
      rect[1].texCoords = Vec2f(texture_rect.w, texture_rect.y);
      rect[2].texCoords = Vec2f(texture_rect.w, texture_rect.h);
      rect[3].texCoords = Vec2f(texture_rect.x, texture_rect.h);
   }
}
