#include "CX/Camera.hpp"

#include "CX/Math/Math.hpp"
#include "CX/Math/Random.hpp"
#include "CX/Math/Trigonometry.hpp"

namespace cx
{
   // Constructors

   Camera::Camera(const Vec4f& viewport)
   {
      camera.setViewport(viewport);
      original_pos = camera.getCenter();
   }

   Camera::Camera(const Vec5f& viewport)
   {
      camera.setViewport(viewport.un_rotated());
      camera.setRotation(viewport.r);
      original_pos = camera.getCenter();
   }

   Camera::Camera(const Vec2f& center, const Vec2f& size)
   {
      camera.setCenter(center);
      camera.setSize(size);
      original_pos = center;
   }

   Camera::Camera(const sf::RenderWindow& window)
   {
      camera.setCenter(Vec2f(window.getSize()) / 2.f);
      camera.setSize(Vec2f(window.getSize()));
      original_pos = camera.getCenter();
   }

   Camera::Camera(UIElement& element, const Vec2f& size)
   {
      target = &element;
      camera.setCenter(target->get_center());
      camera.setSize(size);
      original_pos = camera.getCenter();
   }

   Camera::Camera(const Camera& other)
   {
      target = &other.get_target();
      camera.setViewport(other.get_viewport());
      camera.setRotation(other.get_rotation());
      original_pos = camera.getCenter();
   }

   // Constructors after creation

   void Camera::create(const Vec4f& viewport)
   {
      camera.setViewport(viewport);
      original_pos = camera.getCenter();
   }

   void Camera::create(const Vec5f& viewport)
   {
      camera.setViewport(viewport.un_rotated());
      camera.setRotation(viewport.r);
      original_pos = camera.getCenter();
   }

   void Camera::create(const Vec2f& center, const Vec2f& size)
   {
      camera.setCenter(center);
      camera.setSize(size);
      original_pos = center;
   }

   void Camera::create(const sf::RenderWindow& window)
   {
      camera.setCenter(Vec2f(window.getSize()) / 2.f);
      camera.setSize(Vec2f(window.getSize()));
      original_pos = camera.getCenter();
   }

   void Camera::create(UIElement& element, const Vec2f& size)
   {
      target = &element;
      camera.setCenter(target->get_center());
      camera.setSize(size);
      original_pos = camera.getCenter();
   }

   void Camera::create(const Camera& other)
   {
      target = &other.get_target();
      camera.setViewport(other.get_viewport());
      camera.setRotation(other.get_rotation());
      original_pos = camera.getCenter();
   }

   // Setter functions

   void Camera::set_center(const Vec2f& center)
   {
      original_pos = center;
   }

   void Camera::set_center(float center_x, float center_y)
   {
      original_pos = Vec2f(center_x, center_y);
   }

   void Camera::set_center(float center)
   {
      original_pos = Vec2f(center);
   }

   void Camera::set_top_left(const Vec2f& position)
   {
      original_pos = position - camera.getSize() * .5f;
   }

   void Camera::set_top_left(float left, float top)
   {
      original_pos = Vec2f(left, top) - camera.getSize() * .5f;
   }

   void Camera::set_top_left(float position)
   {
      original_pos = Vec2f(position) - camera.getSize() * .5f;
   }

   void Camera::set_bottom_right(const Vec2f& position)
   {
      original_pos = position + camera.getSize() * .5f;
   }

   void Camera::set_bottom_right(float right, float bottom)
   {
      original_pos = Vec2f(right, bottom) + camera.getSize() * .5f;
   }

   void Camera::set_bottom_right(float position)
   {
      original_pos = Vec2f(position) + camera.getSize() * .5f;
   }

   void Camera::set_size(const Vec2f& size)
   {
      camera.setSize(size);
   }

   void Camera::set_size(float width, float height)
   {
      camera.setSize(Vec2f(width, height));
   }

   void Camera::set_size(float size)
   {
      camera.setSize(Vec2f(size));
   }

   void Camera::set_width(float width)
   {
      camera.setSize(Vec2f(width, camera.getSize().y));
   }

   void Camera::set_height(float height)
   {
      camera.setSize(Vec2f(camera.getSize().x, height));
   }

   void Camera::set_rotation(float angle)
   {
      camera.setRotation(angle);
   }

   void Camera::set_zoom(float zoom)
   {
      target_zoom = zoom;
   }

   void Camera::set_viewport(const Vec4f& viewport)
   {
      camera.setViewport(viewport);
      original_pos = camera.getCenter();
   }

   void Camera::set_viewport(const Vec5f& viewport)
   {
      camera.setViewport(viewport.un_rotated());
      camera.setRotation(viewport.r);
      original_pos = camera.getCenter();
   }

   void Camera::set_target(UIElement& element)
   {
      target = &element;
   }

   void Camera::set_bounds(const Vec4f& bounds)
   {
      cbounds = bounds;
   }

   void Camera::set_smooth_speed(float speed)
   {
      lerp_speed = speed;
   }

   void Camera::set_smooth_zoom_speed(float speed)
   {
      zoom_speed = speed;
   }

   void Camera::set_zoom_bounds(float min, float max)
   {
      zoom_min = min;
      zoom_max = max;
   }

   // Getter functions

   const Vec2f& Camera::get_velocity() const
   {
      return velocity;
   }

   UIElement& Camera::get_target() const
   {
      return *target;
   }

   const Vec4f& Camera::get_camera_bounds() const
   {
      return cbounds;
   }

   Vec5f Camera::get_bounds() const
   {
      return Vec5f(camera.getCenter() - camera.getSize() * .5f,
         camera.getSize(), camera.getRotation());
   }

   Vec4f Camera::get_simple_bounds() const
   {
      return Vec4f(camera.getCenter() - camera.getSize() * .5f,
         camera.getSize());
   }

   Vec4f Camera::get_viewport() const
   {
      return camera.getViewport();
   }

   Vec2f Camera::get_center() const
   {
      return camera.getCenter();
   }

   Vec2f Camera::get_top_left() const
   {
      return camera.getCenter() + camera.getSize() * .5f;
   }

   Vec2f Camera::get_bottom_right() const
   {
      return camera.getCenter() - camera.getSize() * .5f;
   }

   Vec2f Camera::get_size() const
   {
      return camera.getSize();
   }

   float Camera::get_center_x() const
   {
      return camera.getCenter().x;
   }

   float Camera::get_center_y() const
   {
      return camera.getCenter().y;
   }

   float Camera::get_width() const
   {
      return camera.getSize().x;
   }

   float Camera::get_height() const
   {
      return camera.getSize().y;
   }

   float Camera::get_left() const
   {
      return camera.getCenter().x + camera.getSize().x * .5f;
   }

   float Camera::get_top() const
   {
      return camera.getCenter().y + camera.getSize().y * .5f;
   }

   float Camera::get_right() const
   {
      return camera.getCenter().x - camera.getSize().x * .5f;
   }

   float Camera::get_bottom() const
   {
      return camera.getCenter().y - camera.getSize().y * .5f;
   }

   float Camera::get_rotation() const
   {
      return camera.getRotation();
   }

   float Camera::get_zoom() const
   {
      return zoom_factor;
   }

   float Camera::get_smooth_speed() const
   {
      return lerp_speed;
   }

   float Camera::get_smooth_zoom_speed() const
   {
      return zoom_speed;
   }

   bool Camera::is_shaking() const
   {
      return shake_timer > 0.f;
   }

   bool Camera::is_moving() const
   {
      return abs(velocity.x) > .001f && abs(velocity.y) > .001f;
   }

   // Collision functions

   bool Camera::on_screen(const Vec2f& point) const
   {
      return get_bounds().contains(point);
   }

   bool Camera::on_screen(const Vec4f& bounds) const
   {
      return get_simple_bounds().colliding(bounds);
   }

   bool Camera::on_screen(const Vec5f& bounds) const
   {
      return get_bounds().colliding(bounds);
   }

   bool Camera::on_screen(const UIElement& element) const
   {
      return element.colliding(get_bounds());
   }

   // Update functions

   Vec2f Camera::translate_point(const sf::RenderWindow& window, const Vec2f& point)
   {
      return window.mapPixelToCoords(point, camera);
   }

   void Camera::discard_target()
   {
      target = nullptr;
   }

   void Camera::shake(float strength2, float length, float frequency2)
   {
      strength = strength2;
      frequency = 1.f / frequency2;
      shake_timer = length;
   }

   void Camera::move(const Vec2f& offset)
   {
      original_pos += offset;
   }

   void Camera::move(float offsetX, float offsetY)
   {
      original_pos += Vec2f(offsetX, offsetY);
   }

   void Camera::move(float offset)
   {
      original_pos += Vec2f(offset);
   }

   void Camera::rotate(float angle)
   {
      camera.rotate(angle);
   }

   void Camera::zoom(float factor)
   {
      target_zoom *= factor;
   }

   void Camera::update(float dt)
   {
      Vec2f pos = original_pos;

      // Follow the target
      if (target && lerp_speed > 0.f)
      {
         original_pos = target->get_center();
         pos = Vec2f(camera.getCenter()).lerp(original_pos, lerp_speed * dt);
      }
      else if (target)
      {
         original_pos = target->get_center();
         pos = original_pos;
      }

      // Camera boundaries
      if (!cbounds.empty())
      {
         Vec2f s = camera.getSize() * .5f;

         if (camera.getSize().x >= cbounds.w)
            pos.x = cbounds.x + cbounds.w * .5f;
         else
            pos.x = clamp(pos.x, cbounds.x + s.x, cbounds.x + cbounds.w - s.x);

         if (camera.getSize().y >= cbounds.h)
            pos.y = cbounds.y + cbounds.h * .5f;
         else
            pos.y = clamp(pos.y, cbounds.y + s.y, cbounds.y + cbounds.h - s.y);
      }

      // Camera shake
      if (shake_timer > 0.f)
      {
         shake_timer -= dt;
         last_update += dt;

         if (last_update >= frequency)
         {
            last_update = 0.f;
            pos.x += sin(randfu(0.f, 6.28f)) * strength * shake_timer;
            pos.y += cos(randfu(0.f, 6.28f)) * strength * shake_timer;
         }
      }

      velocity = pos - camera.getCenter();
      camera.setCenter(pos);

      target_zoom = (zoom_speed == 0.f ? target_zoom : cx::clamp(target_zoom, zoom_min, zoom_max));
      float newZoom = zoom_factor;

      // Zoom the camera
      if (zoom_factor != target_zoom && zoom_speed != 0.f)
         newZoom = lerp(zoom_factor, target_zoom, zoom_speed * dt);
      else if (zoom_factor != target_zoom)
         newZoom = target_zoom;

      if (newZoom != zoom_factor)
      {
         if (zoom_min != 0.f && zoom_max != 0.f)
            newZoom = clamp(newZoom, zoom_min, zoom_max);
         else if (zoom_min != 0.f)
            newZoom = max(newZoom, zoom_min);
         else if (zoom_max != 0.f)
            newZoom = min(newZoom, zoom_max);

         camera.zoom(newZoom / zoom_factor);
         zoom_factor = newZoom;
      }
   }

   void Camera::apply(sf::RenderWindow& window)
   {
      window.setView(camera);
   }

   // Access functions

   sf::View& Camera::get_camera()
   {
      return camera;
   }
}
