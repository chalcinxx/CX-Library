#ifndef CX_RECT_RECT_HPP
#define CX_RECT_RECT_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include "CX/Rect/RectStyle.hpp"
#include "CX/UIElement/UIElement.hpp"

namespace cx
{
   /// @brief Modify and display rectangles.
   class Rect : public UIElement
   {
   public:
      // Constructors
      
      /// @brief Create a default rectangle.
      Rect();
      ~Rect() = default;

      /// @brief Create a new rectangle.
      /// @param style Style of the rectangle.
      Rect(const RectStyle& style);

      /// @brief Create a new rectangle.
      /// @param size Size of the rectangle.
      /// @param position Center position of the rectangle.
      /// @param color Color of the rectangle.
      Rect(const Vec2f& size,
           const Vec2f& position = {},
           const Color& color = Color(255));

      // Constructors after creation

      /// @brief Create a new rectangle.
      /// @param style Style of the rectangle.
      void create(const RectStyle& style);

      /// @brief Create a new rectangle.
      /// @param size Size of the rectangle.
      /// @param position Center position of the rectangle.
      /// @param color Color of the rectangle.
      void create(const Vec2f& size,
                  const Vec2f& position = {},
                  const Color& color = Color(255));

      // Setter functions

      /// @brief Import UIElement functions to not override them.
      using UIElement::set_center;
      using UIElement::set_scale;
      using UIElement::set_size;
      using UIElement::set_rotation;

      /// @brief Change center position of the rectangle.
      /// @param position New center.
      void set_center(const Vec2f& position) override;

      /// @brief Change scale of the rectangle.
      /// @param scale New scale.
      void set_scale(const Vec2f& scale) override;

      /// @brief Change size of the rectangle.
      /// @param size New size.
      void set_size(const Vec2f& size) override;

      /// @brief Change rotation of the rectangle.
      /// @param angle New rotation in degrees.
      void set_rotation(float angle) override;

      /// @brief Change texture of the rectangle.
      /// @param texture New texture.
      void set_texture(const sf::Texture* texture);

      /// @brief Change texture rectangle of the rectangle.
      /// @param rect New texture rectangle.
      void set_texture_rect(const Vec4i& rect);

      /// @brief Change color of the rectangle.
      /// @param color New color.
      void set_color(const Color& color) override;

      // Getter functions

      /// @brief Get rectangle type.
      /// @return Type.
      ElementType get_element_type() const override;

      /// @brief Get center position of the rectangle.
      /// @return Center.
      Vec2f get_center() const override;

      /// @brief Get scale of the rectangle.
      /// @return Scale.
      Vec2f get_scale() const override;

      /// @brief Get size of the rectangle.
      /// @return Size.
      Vec2f get_size() const override;

      /// @brief Get origin of the rectangle.
      /// @return Origin.
      Vec2f get_origin() const override;

      /// @brief Get rotation of the rectangle.
      /// @return Rotation in degrees.
      Deg get_rotation() const override;

      /// @brief Get texture of the rectangle.
      /// @return Texture.
      const sf::Texture* get_texture() const;

      /// @brief Get texture rectangle of the rectangle.
      /// @return Texture rectangle.
      Vec4i get_texture_rect() const;

      /// @brief Get color of the rectangle.
      /// @return Color.
      Color get_color() const override;

      // Update functions

      /// @brief Update the rectangle's state and functions.
      /// @param state Mouse state.
      /// @param local Should local boundaries be used.
      void update(const MouseState& state, bool local = false) override;

      // Render functions

      /// @brief Render the rectangle.
      /// @param window Window to draw to.
      void render(sf::RenderWindow& window) const override;

      /// @brief Render the rectangle.
      /// @param window Window to draw to.
      /// @param shader Shader.
      void render(sf::RenderWindow& window, const sf::Shader* shader) const override;

      // Access functions

      /// @brief Get the rectangle.
      /// @return Rectangle.
      sf::RectangleShape& get_rectangle();

   private:
      sf::RectangleShape rect;
   };
}

#endif
