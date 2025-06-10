#ifndef CX_UI_ELEMENT_UI_ELEMENT_HPP
#define CX_UI_ELEMENT_UI_ELEMENT_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include "CX/Color.hpp"
#include "CX/EventHandler/Mouse.hpp"
#include "CX/UIElement/ElementType.hpp"
#include "CX/UIElement/Functions.hpp"
#include "CX/Vector/Vec5.hpp"

namespace cx
{
   /// @brief Modify and display UI elements.
   class UIElement
   {
   public:
      // Constructors

      /// @brief Create a default element.
      UIElement() = default;
      virtual ~UIElement();

      // Constructors after creation

      /// @brief Create a element from boundaries.
      /// @param bounds Boundaries.
      void from_bounds(const Vec4f& bounds);

      /// @brief Create a element from boundaries.
      /// @param bounds Boundaries.
      void from_bounds(const Vec5f& bounds);

      // Collision functions

      /// @brief Check for collision against boundaries.
      /// @param bounds Boundaries to check collision against.
      /// @return True if colliding.
      bool colliding(const Vec4f& bounds) const;

      /// @brief Check for collision against boundaries.
      /// @param bounds Boundaries to check collision against.
      /// @return True if colliding.
      bool colliding(const Vec5f& bounds) const;

      /// @brief Check for collision against an element.
      /// @param other Element to check collision against.
      /// @return True if colliding.
      bool colliding(const UIElement& other) const;

      /// @brief Check for collision against a point.
      /// @param point Point to check collision against.
      /// @return True if colliding.
      bool contains(const Vec2f& point) const;

      /// @brief Check distance to given point.
      /// @param point Point.
      /// @return Distance.
      float distance(const Vec2f& point) const;

      /// @brief Check distance to another element.
      /// @param other Element.
      /// @return Distance.
      float distance(const UIElement& other) const;

      // Setter functions

      /// @brief Change center position of the element.
      /// @param position New center.
      virtual void set_center(const Vec2f& position) = 0;

      /// @brief Change center position of the element.
      /// @param center_x New X center.
      /// @param center_y New Y center.
      void set_center(float center_x, float center_y);

      /// @brief Change center position of the element.
      /// @param center New center.
      void set_center(float center);

      /// @brief Change center X position of the element.
      /// @param center_x New center X.
      void set_center_x(float center_x);

      /// @brief Change center Y position of the element.
      /// @param center_y New center Y.
      void set_center_y(float center_y);

      /// @brief Change top-left position of the element.
      /// @param position New position.
      void set_top_left(const Vec2f& position);

      /// @brief Change top-left position of the element.
      /// @param left New X position.
      /// @param top New Y position.
      void set_top_left(float left, float top);

      /// @brief Change top-left position of the element.
      /// @param position New position.
      void set_top_left(float position);

      /// @brief Change left position of the element.
      /// @param left New X position.
      void set_left(float left);

      /// @brief Change top position of the element.
      /// @param top New Y position.
      void set_top(float top);

      /// @brief Change bottom-right position of the element.
      /// @param position New position.
      void set_bottom_right(const Vec2f& position);

      /// @brief Change bottom-right position of the element.
      /// @param right New right position.
      /// @param bottom New bottom position.
      void set_bottom_right(float right, float bottom);

      /// @brief Change bottom-right position of the element.
      /// @param position New position.
      void set_bottom_right(float position);

      /// @brief Change right position of the element.
      /// @param right New X position.
      void set_right(float right);

      /// @brief Change bottom position of the element.
      /// @param bottom New Y position.
      void set_bottom(float bottom);

      /// @brief Change scale of the element.
      /// @param scale New scale.
      virtual void set_scale(const Vec2f& scale) = 0; 

      /// @brief Change scale of the element.
      /// @param scale_x New X scale.
      /// @param scale_y New Y scale.
      void set_scale(float scale_x, float scale_y);

      /// @brief Change scale of the element.
      /// @param scale New X and Y scale.
      void set_scale(float scale);

      /// @brief Change X scale of the element.
      /// @param scale_x New X scale.
      void set_scale_x(float scale_x);

      /// @brief Change Y scale of the element.
      /// @param scale_y New Y scale.
      void set_scale_y(float scale_y); 

      /// @brief Change size of the element.
      /// @param size New size.
      virtual void set_size(const Vec2f& size) = 0;

      /// @brief Change size of the element.
      /// @param width New X size.
      /// @param height New Y size.
      void set_size(float width, float height);

      /// @brief Change size of the element.
      /// @param size New X and Y size.
      void set_size(float size);

      /// @brief Change the width of the element.
      /// @param width New X size.
      void set_width(float width);

      /// @brief Change the height of the element.
      /// @param height New Y size.
      void set_height(float height);

      /// @brief Change rotation of the element.
      /// @param angle New rotation in degrees.
      virtual void set_rotation(float angle) = 0;

      /// @brief Change rotation of the element.
      /// @param angle New angle.
      void set_rotation(const Angle& angle);

      /// @brief Change color of the element.
      /// @param color New color.
      virtual void set_color(const Color& color) = 0;

      /// @brief Change opacity of the element.
      /// @param opacity Opacity 0-255.
      void set_opacity(unsigned char opacity);

      // Getter functions
      
      /// @brief Get element type.
      /// @return Type.
      virtual ElementType get_element_type() const = 0;

      /// @brief Get center position of the element.
      /// @return Center position.
      virtual Vec2f get_center() const = 0;

      /// @brief Get element X center.
      /// @return X center.
      float get_center_x() const;

      /// @brief Get element Y center.
      /// @return Y center.
      float get_center_y() const;

      /// @brief Get top-left position of the element.
      /// @return Position.
      Vec2f get_top_left() const;

      /// @brief Get X position of the element.
      /// @return X position.
      float get_left() const;

      /// @brief Get Y position of the element.
      /// @return Y position.
      float get_top() const;

      /// @brief Get right-bottom position of the element.
      /// @return Position.
      Vec2f get_bottom_right() const;

      /// @brief Get right position of the element.
      /// @return Right position.
      float get_right() const;

      /// @brief Get bottom position of the element.
      /// @return Bottom position.
      float get_bottom() const;

      /// @brief Get size of the element.
      /// @return Size.
      virtual Vec2f get_size() const = 0;

      /// @brief Get width of the element.
      /// @return Width.
      float get_width() const;

      /// @brief Get height of the element.
      /// @return Height.
      float get_height() const;

      /// @brief Get scale of the element.
      /// @return Scale.
      virtual Vec2f get_scale() const = 0;

      /// @brief Get X scale of the element.
      /// @return X scale.
      float get_scale_x() const;

      /// @brief Get Y scale of the element.
      /// @return Y scale.
      float get_scale_y() const;

      /// @brief Get origin of the element.
      /// @return Origin.
      virtual Vec2f get_origin() const = 0;

      /// @brief Get origin X of the element.
      /// @return Origin X.
      float get_origin_x() const;

      /// @brief Get origin Y of the element.
      /// @return Origin Y.
      float get_origin_y() const;

      /// @brief Get global boundaries of the element.
      /// @return Global boundaries.
      Vec5f get_bounds() const;

      /// @brief Get local boundaries of the element.
      /// @return Local boundaries.
      Vec5f get_local_bounds() const;

      /// @brief Get global boundaries of the element without rotation.
      /// @return Simple boundaries.
      Vec4f get_simple_bounds() const;

      /// @brief Get rotation of the element.
      /// @return Rotation in degrees.
      virtual Deg get_rotation() const = 0;

      /// @brief Get color of the element.
      /// @return Color.
      virtual Color get_color() const = 0;

      /// @brief Get opacity of the element.
      /// @return Opacity.
      unsigned char get_opacity() const;

      // Update functions

      /// @brief Flip the element horizontally.
      void flip_horizontally();

      /// @brief Flip the element vertically.
      void flip_vertically();

      /// @brief Move the element.
      /// @param offset Amount to move by.
      void move(const Vec2f& offset);

      /// @brief Move the element.
      /// @param offset_x Amount to move by horizontally.
      /// @param offset_y Amount to move by vertically.
      void move(float offset_x, float offset_y);

      /// @brief Move the element.
      /// @param offset Amount to move by.
      void move(float offset);
   
      /// @brief Scale the element.
      /// @param factor Amount to scale by.
      void scale(const Vec2f& factor);

      /// @brief Scale the element.
      /// @param factor_x Amount to scale by horizontally.
      /// @param factor_y Amount to scale by vertically.
      void scale(float factor_x, float factor_y);

      /// @brief Scale the element.
      /// @param factor Amount to scale by.
      void scale(float factor);

      /// @brief Rotate the element.
      /// @param angle Amount to rotate by in degrees.
      void rotate(float angle);

      /// @brief Rotate the element.
      /// @param angle AMount to rotate by.
      void rotate(const Angle& angle);

      /// @brief Update the element's state and functions.
      /// @param state Mouse state.
      /// @param local Should local boundaries be used.
      virtual void update(const MouseState& state, bool local = false) = 0;

      /// @brief Set the function that is called after updating the element.
      /// @param func Function.
      void on_update(const std::function<void(UIElement&)>& func);

      /// @brief Set the function that is called after updating the element.
      /// @param func Function.
      void on_update(const Functions& func);

      // Update getter functions

      /// @brief Check if element is being hovered on.
      /// @return True if being hovered on.
      bool is_hovering() const;

      /// @brief Check if element was being hovered on last frame.
      /// @return True if was hovered on last frame.
      bool was_hovering() const;

      /// @brief Check if element has stopped being hovered on.
      /// @return True if stopped hovering.
      bool stopped_hovering() const;

      /// @brief Check if element has started being hovered on.
      /// @return True if started hovering.
      bool started_hovering() const;

      /// @brief Check if element has been clicked this frame.
      /// @return True if clicked.
      bool is_clicked() const;

      /// @brief Check if mouse has been released on the element this frame.
      /// @return True if mouse has been released.
      bool is_mouse_up() const;

      /// @brief Check if mouse is being held down on the element.
      /// @return True if mouse is held down.
      bool is_mouse_down() const;

      // Render functions

      /// @brief Render the element.
      /// @param window Window to draw to.
      virtual void render(sf::RenderWindow& window) const = 0;

      /// @brief Render the element.
      /// @param window Window to draw to.
      /// @param shader Shader.
      virtual void render(sf::RenderWindow& window, const sf::Shader* shader) const = 0;

   protected:
      bool was_hover  = false;
      bool hovering   = false;
      bool clicked    = false;
      bool mouse_down = false;
      bool mouse_up   = false;

      using func = std::function<void(UIElement&)>;
      std::shared_ptr<func> on_update_func = std::make_shared<func>([](UIElement&){});

      /// @brief Update the element's state and functions.
      /// @param state Mouse state.
      /// @param local Should local boundaries be used.
      void update_state(const MouseState& state, bool local = false);
   };
}

#endif
