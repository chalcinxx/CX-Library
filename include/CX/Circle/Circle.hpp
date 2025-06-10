#ifndef CX_CIRCLE_CIRCLE_HPP
#define CX_CIRCLE_CIRCLE_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include "CX/Circle/CircleBounds.hpp"
#include "CX/Circle/CircleStyle.hpp"
#include "CX/UIElement/UIElement.hpp"

namespace cx
{
   /// @brief Modify and display circles.
   class Circle : public UIElement
   {
   public:
      // Constructors

      /// @brief Create a default circle.
      Circle();
      ~Circle() = default;

      /// @brief Create a new circle.
      /// @param style Style of the circle.
      Circle(const CircleStyle& style);

      /// @brief Create a new circle.
      /// @param radius Radius of the circle.
      /// @param position Position of the circle.
      /// @param color Color of the circle.
      /// @param point_count Point count of the circle.
      Circle(float radius,
             const Vec2f& position = {},
             const Color& color = Color(255),
             size_t point_count = 30);

      // Constructors after creation

      /// @brief Create a new circle.
      /// @param style Style of the circle.
      void create(const CircleStyle& style);

      /// @brief Create a new circle.
      /// @param radius Radius of the circle.
      /// @param position Position of the circle.
      /// @param color Color of the circle.
      /// @param point_count Point count of the circle.
      void create(float radius,
                  const Vec2f& position = {},
                  const Color& color = Color(255),
                  size_t point_count = 30);

      // Setter functions

      /// @brief Import UIElement functions to not override them.
      using UIElement::set_center;
      using UIElement::set_scale;
      using UIElement::set_size;
      using UIElement::set_rotation;

      /// @brief Change center position of the circle.
      /// @param position New center.
      void set_center(const Vec2f& position) override;

      /// @brief Change scale of the circle.
      /// @param scale New scale.
      void set_scale(const Vec2f& scale) override;

      /// @brief Change size of the circle.
      /// @param size New size.
      void set_size(const Vec2f& size) override;

      /// @brief Change rotation of the circle.
      /// @param angle New rotation in degrees.
      void set_rotation(float rotation) override;

      /// @brief Change texture of the circle.
      /// @param texture New texture.
      void set_texture(const sf::Texture* texture);

      /// @brief Change texture rectangle of the circle.
      /// @param rect New texture rectangle.
      void set_texture_rect(const Vec4i& rect);

      /// @brief Change color of the circle.
      /// @param color New color.
      void set_color(const Color& color) override;

      /// @brief Change the radius of the circle.
      /// @param radius New radius.
      void set_radius(float radius);

      /// @brief Change the point count of the circle.
      /// @param point_count New point count.
      void set_point_count(size_t point_count);

      // Getter functions

      /// @brief Get circle type.
      /// @return Type.
      ElementType get_element_type() const override;

      /// @brief Get center position of the circle.
      /// @return Center.
      Vec2f get_center() const override;

      /// @brief Get scale of the circle.
      /// @return Scale.
      Vec2f get_scale() const override;

      /// @brief Get size of the circle.
      /// @return Size.
      Vec2f get_size() const override;

      /// @brief Get origin of the circle.
      /// @return Origin.
      Vec2f get_origin() const override;

      /// @brief Get rotation of the circle.
      /// @return Rotation in degrees.
      Deg get_rotation() const override;

      /// @brief Get half size of the circle.
      /// @return Half size.
      Vec2f get_half_size() const;

      /// @brief Get circle boundaries.
      /// @return Circle boundaries.
      CircleBounds get_circle_bounds() const;

      /// @brief Get texture of the circle.
      /// @return Texture.
      const sf::Texture* get_texture() const;

      /// @brief Get texture rectangle of the circle.
      /// @return Texture rectangle.
      Vec4i get_texture_rect() const;

      /// @brief Get color of the circle.
      /// @return Color.
      Color get_color() const override;

      /// @brief Get radius of the circle.
      /// @return Radius.
      float get_radius() const;

      /// @brief Get point count of the circle.
      /// @return Point count.
      size_t get_point_count() const;

      // Update functions

      /// @brief Update the circle's state and functions.
      /// @param state Mouse state.
      /// @param local Should local boundaries be used.
      void update(const MouseState& state, bool local = false) override;

      // Render functions

      /// @brief Render the circle.
      /// @param window Window to draw to.
      void render(sf::RenderWindow& window) const override;

      /// @brief Render the circle.
      /// @param window Window to draw to.
      /// @param shader Shader.
      void render(sf::RenderWindow& window, const sf::Shader* shader) const override;

      // Access functions

      /// @brief Get the circle.
      /// @return Circle.
      sf::CircleShape& get_circle();

   private:
      sf::CircleShape circle;
   };
}

#endif
