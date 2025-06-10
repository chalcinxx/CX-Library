#ifndef CX_PLANE_PLANE_HPP
#define CX_PLANE_PLANE_HPP

#include <SFML/Graphics/VertexArray.hpp>
#include "CX/Plane/PlaneStyle.hpp"
#include "CX/UIElement/UIElement.hpp"

namespace cx
{
   /// @brief Modify and display planes.
   class Plane : public UIElement
   {
   public:
      // Constructors
      
      /// @brief Create a default plane.
      Plane();
      ~Plane() = default;

      /// @brief Create a new plane.
      /// @param style Style of the plane.
      Plane(const PlaneStyle& style);

      /// @brief Create a new plane.
      /// @param size Size of the plane.
      /// @param position Center position of the plane.
      /// @param color Color of the plane.
      Plane(const Vec2f& size,
            const Vec2f& position = {},
            const Color& color = Color(255));

      // Constructors after creation

      /// @brief Create a new plane.
      /// @param style Style of the plane.
      void create(const PlaneStyle& style);

      /// @brief Create a new plane.
      /// @param size Size of the plane.
      /// @param position Center position of the plane.
      /// @param color Color of the plane.
      void create(const Vec2f& size,
                  const Vec2f& position = {},
                  const Color& color = Color(255));

      // Setter functions

      /// @brief Import UIElement functions to not override them.
      using UIElement::set_center;
      using UIElement::set_scale;
      using UIElement::set_size;
      using UIElement::set_rotation;

      /// @brief Change center position of the plane.
      /// @param position New center.
      void set_center(const Vec2f& position) override;

      /// @brief Change scale of the plane.
      /// @param scale New scale.
      void set_scale(const Vec2f& scale) override;

      /// @brief Change size of the plane.
      /// @param size New size.
      void set_size(const Vec2f& size) override;

      /// @brief Change rotation of the plane.
      /// @param angle New 2d rotation in degrees.
      void set_rotation(float angle) override;

      /// @brief Change rotation of the plane.
      /// @param angle New 3d rotation in degrees.
      void set_3d_rotation(const Vec3f& angle);

      /// @brief Change rotation of the plane.
      /// @param angle_x New X rotation in degrees.
      /// @param angle_y New Y rotation in degrees.
      /// @param angle_z New Z rotation in degrees.
      void set_3d_rotation(float angle_x, float angle_y, float angle_z);

      /// @brief Change rotation of the plane.
      /// @param angle New X, Y and Z rotation in degrees.
      void set_3d_rotation(float angle);

      /// @brief Change X rotation of the plane.
      /// @param angle New X rotation in degrees.
      void set_3d_rotation_x(float angle);

      /// @brief Change Y rotation of the plane.
      /// @param angle New Y rotation in degrees.
      void set_3d_rotation_y(float angle);

      /// @brief Change Z rotation of the plane.
      /// @param angle New Z rotation in degrees.
      void set_3d_rotation_z(float angle);

      /// @brief Change texture of the plane.
      /// @param texture New texture.
      void set_texture(const sf::Texture* texture);

      /// @brief Change texture plane of the plane.
      /// @param rect New texture plane.
      void set_texture_rect(const Vec4i& rect);

      /// @brief Change color of the plane.
      /// @param color New color.
      void set_color(const Color& color) override;

      /// @brief Change skew of the plane.
      /// @param skew New skew.
      void set_skew(const Vec2f& skew);

      /// @brief Change skew of the plane.
      /// @param skew_x New X skew.
      /// @param skew_y New Y skew.
      void set_skew(float skew_x, float skew_y);

      /// @brief Change skew of the plane.
      /// @param skew New X and Y skew.
      void set_skew(float skew);

      /// @brief Change X skew of the plane.
      /// @param skew New X skew.
      void set_skew_x(float skew);

      /// @brief Change Y skew of the plane.
      /// @param skew New Y skew.
      void set_skew_y(float skew);

      /// @brief Change 3d rotation offset of the plane.
      /// @param offset New offset.
      void set_3d_offset(const Vec3f& offset);

      /// @brief Change 3d rotation offset of the plane.
      /// @param offset_x New X offset.
      /// @param offset_y New Y offset.
      /// @param offset_z New Z offset.
      void set_3d_offset(float offset_x, float offset_y, float offset_z);

      /// @brief Change 3d rotation offset of the plane.
      /// @param offset New X, Y and Z offset.
      void set_3d_offset(float offset);

      /// @brief Change 3d rotation X offset of the plane.
      /// @param offset New Y offset.
      void set_3d_offset_x(float offset);

      /// @brief Change 3d rotation Y offset of the plane.
      /// @param offset New Y offset.
      void set_3d_offset_y(float offset);

      /// @brief Change 3d rotation Z offset of the plane.
      /// @param offset New Z offset.
      void set_3d_offset_z(float offset);

      // Getter functions

      /// @brief Get plane type.
      /// @return Type.
      ElementType get_element_type() const override;

      /// @brief Get center position of the plane.
      /// @return Center.
      Vec2f get_center() const override;

      /// @brief Get scale of the plane.
      /// @return Scale.
      Vec2f get_scale() const override;

      /// @brief Get size of the plane.
      /// @return Size.
      Vec2f get_size() const override;

      /// @brief Get origin of the plane.
      /// @return Origin.
      Vec2f get_origin() const override;

      /// @brief Get rotation of the plane.
      /// @return Rotation in degrees.
      Deg get_rotation() const override;

      /// @brief Get 3d rotation of the plane.
      /// @return 3d rotation in degrees.
      Vec3f get_3d_rotation() const;

      /// @brief Get X rotation of the plane.
      /// @return X rotation in degrees.
      Deg get_3d_rotation_x() const;

      /// @brief Get Y rotation of the plane.
      /// @return Y rotation in degrees.
      Deg get_3d_rotation_y() const;

      /// @brief Get Z rotation of the plane.
      /// @return Z rotation in degrees.
      Deg get_3d_rotation_z() const;

      /// @brief Get texture of the plane.
      /// @return Texture.
      const sf::Texture* get_texture() const;

      /// @brief Get texture plane of the plane.
      /// @return Texture plane.
      Vec4i get_texture_rect() const;

      /// @brief Get color of the plane.
      /// @return Color.
      Color get_color() const override;

      /// @brief Get skew of the plane.
      /// @return Skew.
      Vec2f get_skew() const;

      /// @brief Get X skew of the plane.
      /// @return X skew.
      float get_skew_x() const;

      /// @brief Get Y skew of the plane.
      /// @return Y skew.
      float get_skew_y() const;

      /// @brief Get 3d rotation offset of the plane.
      /// @return Offset.
      Vec3f get_3d_offset() const;

      /// @brief Get 3d rotation X offset of the plane.
      /// @return Offset.
      float get_3d_offset_x() const;

      /// @brief Get 3d rotation Y offset of the plane.
      /// @return Offset.
      float get_3d_offset_y() const;

      /// @brief Get 3d rotation Z offset of the plane.
      /// @return Offset.
      float get_3d_offset_z() const;

      // Update functions

      /// @brief Rotate the plane in 3d.
      /// @param angle Angle in degrees.
      void rotate_3d(const Vec3f& angle);

      /// @brief Rotate X axis in 3d.
      /// @param angle Angle in degrees.
      void rotate_3d_x(float angle);

      /// @brief Rotate Y axis in 3d.
      /// @param angle Angle in degrees.
      void rotate_3d_y(float angle);

      /// @brief Rotate Z axis in 3d.
      /// @param angle Angle in degrees.
      void rotate_3d_z(float angle);

      /// @brief Update the plane's state and functions.
      /// @param state Mouse state.
      /// @param local Should local boundaries be used.
      void update(const MouseState& state, bool local = false) override;

      // Render functions

      /// @brief Render the plane.
      /// @param window Window to draw to.
      void render(sf::RenderWindow& window) const override;

      /// @brief Render the plane.
      /// @param window Window to draw to.
      /// @param shader Shader.
      void render(sf::RenderWindow& window, const sf::Shader* shader) const override;

      // Access functions

      /// @brief Get plane.
      /// @return Plane.
      sf::VertexArray& get_plane();

      /// @brief Get top-left vertex.
      /// @return Top-left vertex.
      sf::Vertex& get_top_left_vertex();

      /// @brief Get top-right vertex.
      /// @return Top-right vertex.
      sf::Vertex& get_top_right_vertex();

      /// @brief Get bottom-right vertex.
      /// @return Bottom-right vertex.
      sf::Vertex& get_bottom_right_vertex();

      /// @brief Get bottom-left vertex.
      /// @return Bottom-left vertex.
      sf::Vertex& get_bottom_left_vertex();

      /// @brief Get vertex by index.
      /// @param index Index.
      /// @return Vertex.
      sf::Vertex& get_vertex(size_t index);

   private:
      sf::VertexArray rect;
      Vec2f center;
      Vec2f origin;
      Vec2f size;
      Vec2f scale {1.f};
      Vec2f skew;
      Vec3f offset;
      Vec3f rotation;
      Color color {255};

      const sf::Texture* texture = nullptr;
      Vec4i texture_rect;

      /// @brief Reposition and resize the plane.
      void redraw();

      /// @brief Color the plane.
      void recolor();

      /// @brief Bind texture.
      void bind_texture();
   };
}

#endif
