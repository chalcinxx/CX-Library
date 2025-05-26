#ifndef CX_CAMERA_HPP
#define CX_CAMERA_HPP

#include <SFML/Graphics/View.hpp>
#include "CX/UIElement/UIElement.hpp"

namespace cx
{
   /// @brief Manage the camera.
   class Camera
   {
   public:
      // Constructors

      /// @brief Create a default camera.
      Camera() = default;

      /// @brief Create a camera.
      /// @param viewport Camera viewport.
      Camera(const Vec4f& viewport);

      /// @brief Create a camera.
      /// @param viewport Camera viewport.
      Camera(const Vec5f& viewport);

      /// @brief Create a camera.
      /// @param center Camera center.
      /// @param size Size of camera.
      Camera(const Vec2f& center, const Vec2f& size);

      /// @brief Create a camera.
      /// @param window Window to fit in.
      Camera(const sf::RenderWindow& window);

      /// @brief Create a camera.
      /// @param element Target to follow.
      Camera(UIElement& element, const Vec2f& size);

      /// @brief Copy a camera.
      /// @param other Other camera.
      Camera(const Camera& other);

      // Constructors after creation

      /// @brief Create a camera.
      /// @param viewPort Camera viewport.
      void create(const Vec4f& viewport);

      /// @brief Create a camera.
      /// @param viewport Camera viewport.
      void create(const Vec5f& viewport);

      /// @brief Create a camera.
      /// @param center Camera center.
      /// @param size Size of camera.
      void create(const Vec2f& center, const Vec2f& size);

      /// @brief Create a camera.
      /// @param window Window to fit in.
      void create(const sf::RenderWindow& window);

      /// @brief Create a camera.
      /// @param element Target to follow.
      void create(UIElement& element, const Vec2f& size);

      /// @brief Copy a camera.
      /// @param other Other camera.
      void create(const Camera& other);


      // Setter functions

      /// @brief Set center of the camera.
      /// @param center New center.
      void set_center(const Vec2f& center);

      /// @brief Set center of the camera.
      /// @param center_x New X center.
      /// @param center_y New Y center.
      void set_center(float center_x, float center_y);

      /// @brief Set center of the camera.
      /// @param center New center.
      void set_center(float center);

      /// @brief Set top-left position of the camera.
      /// @param position New position.
      void set_top_left(const Vec2f& position);
      
      /// @brief Set top-left position of the camera.
      /// @param left New X position.
      /// @param top New Y position.
      void set_top_left(float left, float top);

      /// @brief Set top-left position of the camera.
      /// @param position New position.
      void set_top_left(float position);

      /// @brief Set bottom-right position of the camera.
      /// @param position New position.
      void set_bottom_right(const Vec2f& position);
      
      /// @brief Set bottom-right position of the camera.
      /// @param right New right position.
      /// @param bottom New bottom position.
      void set_bottom_right(float right, float bottom);

      /// @brief Set bottom-right position of the camera.
      /// @param position New position.
      void set_bottom_right(float position);

      /// @brief Set size of the camera.
      /// @param size New size.
      void set_size(const Vec2f& size);

      /// @brief Set size of the camera.
      /// @param width New X size.
      /// @param height New Y size.
      void set_size(float width, float height);

      /// @brief Set size of the camera.
      /// @param size New size.
      void set_size(float size);

      /// @brief Set width of the camera.
      /// @param width New width.
      void set_width(float width);

      /// @brief Set height of the camera.
      /// @param height New height.
      void set_height(float height);

      /// @brief Set rotation of the camera.
      /// @param angle New rotation in degrees.
      void set_rotation(float angle);

      /// @brief Set zoom of the camera.
      /// @param zoom New zoom.
      void set_zoom(float zoom);

      //// @brief Set viewport of the camera.
      /// @param viewport New viewport.
      void set_viewport(const Vec4f& viewport);

      /// @brief Set viewport of the camera.
      /// @param viewport New viewport.
      void set_viewport(const Vec5f& viewport);

      /// @brief Set target of the camera.
      /// @param element New target.
      void set_target(UIElement& element);

      /// @brief Set camera boundaries.
      /// @param bounds Camera boundaries.
      void set_bounds(const Vec4f& bounds);

      /// @brief Set camera speed.
      /// @param speed Speed of camera, 0 to disable.
      void set_smooth_speed(float speed);

      /// @brief Set camera zoom speed.
      /// @param speed Zoom speed of camera, 0 to disable.
      void set_smooth_zoom_speed(float speed);

      /// @brief Set camera zoom constraints.
      /// @param min Minimum zoom allowed.
      /// @param max Maximum zoom allowed.
      void set_zoom_bounds(float min, float max);

      // Getter functions

      /// @brief Get velocity of the camera.
      /// @return Velocity.
      const Vec2f& get_velocity() const;

      /// @brief Get target of the camera.
      /// @return Target.
      UIElement& get_target() const;

      /// @brief Get camera boundaries.
      /// @return Camera boundaries.
      const Vec4f& get_camera_bounds() const;

      /// @brief Get camera global boundaries.
      /// @return Global boundaries.
      Vec5f get_bounds() const;

      /// @brief Get camera un-rotated boundaries.
      /// @return Simple boundaries.
      Vec4f get_simple_bounds() const;

      /// @brief Get camera viewport.
      /// @return Viewport.
      Vec4f get_viewport() const;

      /// @brief Get camera center.
      /// @return Center.
      Vec2f get_center() const;

      /// @brief Get camera top-left position.
      /// @return Position.
      Vec2f get_top_left() const;

      /// @brief Get camera bottom-right position.
      /// @return Position.
      Vec2f get_bottom_right() const;

      /// @brief Get camera size.
      /// @return Size.
      Vec2f get_size() const;

      /// @brief Get camera X center.
      /// @return X center.
      float get_center_x() const;

      /// @brief Get camera Y center.
      /// @return Y center.
      float get_center_y() const;

      /// @brief Get camera width.
      /// @return Width.
      float get_width() const;

      /// @brief Get camera height.
      /// @return Height.
      float get_height() const;

      /// @brief Get camera X position.
      /// @return X position.
      float get_left() const;

      /// @brief Get camera Y position.
      /// @return Y position.
      float get_top() const;

      /// @brief Get camera right position.
      /// @return Right position.
      float get_right() const;

      /// @brief Get camera bottom position.
      /// @return Bottom position.
      float get_bottom() const;

      /// @brief Get camera rotation.
      /// @return Rotation in degrees.
      float get_rotation() const;
      
      /// @brief Get camera zoom.
      /// @return Zoom.
      float get_zoom() const;

      /// @brief Get smooth camera speed.
      /// @return Speed.
      float get_smooth_speed() const;

      /// @brief Get smooth camera zoom speed.
      /// @return Speed.
      float get_smooth_zoom_speed() const;

      /// @brief Check if camera is shaking.
      /// @return True if shaking.
      bool is_shaking() const;

      /// @brief Check if camera is moving.
      /// @return True if moving.
      bool is_moving() const;

      // Collision functions

      /// @brief Check if point is on screen.
      /// @param point Point.
      /// @return True if on screen.
      bool on_screen(const Vec2f& point) const;

      /// @brief Check if boundaries are on screen.
      /// @param bounds Boundaries.
      /// @return True if on screen.
      bool on_screen(const Vec4f& bounds) const;

      /// @brief Check if boundaries are on screen.
      /// @param bounds Boundaries.
      /// @return True if on screen.
      bool on_screen(const Vec5f& bounds) const;

      /// @brief Check if element is on screen.
      /// @param element Element.
      /// @return True if on screen.
      bool on_screen(const UIElement& element) const;

      // Update functions

      /// @brief Convert window position to camera position.
      /// @param window Window.
      /// @param point Position in window space.
      Vec2f translate_point(const sf::RenderWindow& window, const Vec2f& point);

      /// @brief Discard the target.
      void discard_target();

      /// @brief Shake the camera.
      /// @param strength Strength of the shake.
      /// @param length Length of the shake.
      void shake(float strength, float length, float frequency = 20.f);

      /// @brief Move the camera.
      /// @param offset Amount to move by.
      void move(const Vec2f& offset);

      /// @brief Move the camera.
      /// @param offset_x Amount to move by horizontally.
      /// @param offset_y Amount to move by vertically.
      void move(float offset_x, float offset_y);

      /// @brief Move the camera.
      /// @param offset Amount to move by.
      void move(float offset);

      /// @brief Rotate the camera.
      /// @param angle Amount to rotate by in degrees.
      void rotate(float angle);

      /// @brief Zoom the camera.
      /// @param factor Amount to zoom by.
      void zoom(float factor);

      /// @brief Update the camera target and shake functions.
      /// @param dt Delta time.
      void update(float dt);

      /// @brief Apply the camera to the window.
      /// @param window Window to apply to.
      void apply(sf::RenderWindow& window);

      // Access functions

      /// @brief Get camera.
      /// @return Camera.
      sf::View& get_camera();

   private:
      sf::View camera;

      float zoom_factor = 1.f;
      float target_zoom = 1.f;
      float strength    = 0.f;
      float shake_timer = 0.f;
      float frequency   = 0.f;
      float last_update = 0.f;
      float lerp_speed  = 0.f;
      float zoom_speed  = 0.f;
      float zoom_min    = 0.f;
      float zoom_max    = 0.f;

      Vec4f cbounds;
      Vec2f original_pos;
      Vec2f velocity;
      UIElement* target = nullptr;
   };
}

#endif
