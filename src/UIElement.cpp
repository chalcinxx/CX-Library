#include "CX/UIElement/UIElement.hpp"

#include "CX/Circle/Circle.hpp"

namespace cx
{
   // Set default styles

   std::unique_ptr<Functions> Functions::style1_t;
   std::unique_ptr<Functions> Functions::style2_t;
   std::unique_ptr<Functions> Functions::style3_t;

   // Constructors

   UIElement::~UIElement() {};

   // Constructors after creation

   void UIElement::from_bounds(const Vec4f& bounds)
   {
      set_top_left(bounds.get_top_left());
      set_size(bounds.get_size());
      set_scale(Vec2f(1.f));
      set_rotation(0.f);
   }

   void UIElement::from_bounds(const Vec5f& bounds)
   {
      set_top_left(bounds.get_top_left());
      set_size(bounds.get_size());
      set_scale(Vec2f(1.f));
      set_rotation(bounds.r);
   }

   // Collision functions

   bool UIElement::colliding(const Vec4f& bounds) const
   {
      if (get_element_type() == ElementType::circle)
         return static_cast<const Circle*>(this)->get_circle_bounds().colliding(bounds);
      return bounds.colliding(get_simple_bounds());
   }

   bool UIElement::colliding(const Vec5f& bounds) const
   {
      if (get_element_type() == ElementType::circle)
         return static_cast<const Circle*>(this)->get_circle_bounds().colliding(bounds);
      return bounds.colliding(get_bounds());
   }

   bool UIElement::colliding(const UIElement& other) const
   {
      if (get_element_type() == ElementType::circle && other.get_element_type() == ElementType::circle)
         return static_cast<const Circle*>(this)->get_circle_bounds().colliding(static_cast<const Circle*>(this)->get_circle_bounds());
      else if (get_element_type() == ElementType::circle)
         return static_cast<const Circle*>(this)->get_circle_bounds().colliding(other.get_bounds());
      else if (other.get_element_type() == ElementType::circle)
         return static_cast<const Circle&>(other).get_circle_bounds().colliding(get_bounds());
      return other.get_bounds().colliding(get_bounds());
   }

   bool UIElement::contains(const Vec2f& point) const
   {
      if (get_element_type() == ElementType::circle)
         return static_cast<const Circle*>(this)->get_circle_bounds().contains(point);
      return get_bounds().contains(point);
   }

   float UIElement::distance(const Vec2f& point) const
   {
      return get_center().distance(point);
   }

   float UIElement::distance(const UIElement& other) const
   {
      return get_center().distance(other.get_center());
   }

   // Setter functions

   void UIElement::set_center(float center_x, float center_y)
   {
      set_center(Vec2f(center_x, center_y));
   }

   void UIElement::set_center(float center)
   {
      set_center(Vec2f(center));
   }

   void UIElement::set_center_x(float center_x)
   {
      set_center(Vec2f(center_x, get_center_y()));
   }

   void UIElement::set_center_y(float center_y)
   {
      set_center(Vec2f(get_center_x(), center_y));
   }

   void UIElement::set_top_left(float left, float top)
   {
      set_top_left(Vec2f(left, top));
   }

   void UIElement::set_top_left(float position)
   {
      set_top_left(Vec2f(position));
   }

   void UIElement::set_left(float left)
   {
      set_top_left(Vec2f(left, get_top()));
   }

   void UIElement::set_top(float top)
   {
      set_top_left(Vec2f(get_left(), top));
   }

   void UIElement::set_bottom_right(float right, float bottom)
   {
      set_bottom_right(Vec2f(right, bottom));
   }

   void UIElement::set_bottom_right(float position)
   {
      set_bottom_right(Vec2f(position));
   }

   void UIElement::set_right(float right)
   {
      set_bottom_right(Vec2f(right, get_bottom()));
   }

   void UIElement::set_bottom(float bottom)
   {
      set_bottom_right(Vec2f(get_right(), bottom));
   }

   void UIElement::set_scale(float scale_x, float scale_y)
   {
      set_scale(Vec2f(scale_x, scale_y));
   }

   void UIElement::set_scale(float scale)
   {
      set_scale(Vec2f(scale));
   }

   void UIElement::set_scale_x(float scale_x)
   {
      set_scale(Vec2f(scale_x, get_scale_y()));
   }

   void UIElement::set_scale_y(float scale_y)
   {
      set_scale(Vec2f(get_scale_x(), scale_y));
   }

   void UIElement::set_size(float width, float height)
   {
      set_size(Vec2f(width, height));
   }

   void UIElement::set_size(float size)
   {
      set_size(Vec2f(size));
   }

   void UIElement::set_width(float width)
   {
      set_size(Vec2f(width, get_height()));
   }

   void UIElement::set_height(float height)
   {
      set_size(Vec2f(get_width(), height));
   }

   void UIElement::set_rotation(const Angle& angle)
   {
      set_rotation(angle.degrees());
   }

   // Getter functions

   float UIElement::get_center_x() const
   {
      return get_center().x;
   }

   float UIElement::get_center_y() const
   {
      return get_center().y;
   }

   Vec2f UIElement::get_top_left() const
   {
      return get_center() - get_origin();
   }

   float UIElement::get_left() const
   {
      return get_top_left().x;
   }

   float UIElement::get_top() const
   {
      return get_top_left().y;
   }

   Vec2f UIElement::get_bottom_right() const
   {
      return get_center() + get_origin();
   }

   float UIElement::get_right() const
   {
      return get_bottom_right().x;
   }

   float UIElement::get_bottom() const
   {
      return get_bottom_right().y;
   }

   float UIElement::get_width() const
   {
      return get_size().x;
   }

   float UIElement::get_height() const
   {
      return get_size().y;
   }

   float UIElement::get_scale_x() const
   {
      return get_scale().x;
   }

   float UIElement::get_scale_y() const
   {
      return get_scale().y;
   }

   float UIElement::get_origin_x() const
   {
      return get_origin().x;
   }

   float UIElement::get_origin_y() const
   {
      return get_origin().y;
   }

   Vec5f UIElement::get_bounds() const
   {
      return {get_top_left(), get_size(), get_rotation().degrees()};
   }

   Vec5f UIElement::get_local_bounds() const
   {
      return {get_center() - get_origin() / get_scale().abs(), get_size() / get_scale().abs(), get_rotation().degrees()};
   }

   Vec4f UIElement::get_simple_bounds() const
   {
      return {get_top_left(), get_size()};
   }

   // Update functions

   void UIElement::flip_horizontally()
   {
      set_scale(-get_scale_x(), get_scale_y());
   }

   void UIElement::flip_vertically()
   {
      set_scale(get_scale_x(), -get_scale_y());
   }

   void UIElement::move(const Vec2f& offset)
   {
      set_top_left(get_top_left() + offset);
   }

   void UIElement::move(float offset_x, float offset_y)
   {
      move(Vec2f(offset_x, offset_y));
   }

   void UIElement::move(float offset)
   {
      move(Vec2f(offset));
   }

   void UIElement::scale(const Vec2f& factor)
   {
      set_scale(get_scale() * factor);
   }

   void UIElement::scale(float factor_x, float factor_y)
   {
      scale(Vec2f(factor_x, factor_y));
   }

   void UIElement::scale(float factor)
   {
      scale(Vec2f(factor));
   }

   void UIElement::rotate(float angle)
   {
      set_rotation(get_rotation() + angle);
   }

   void UIElement::rotate(const Angle& angle)
   {
      rotate(angle.degrees());
   }

   bool UIElement::is_hovering() const
   {
      return hovering;
   }

   bool UIElement::was_hovering() const
   {
      return was_hover;
   }

   bool UIElement::stopped_hovering() const
   {
      return was_hover && !hovering;
   }

   bool UIElement::started_hovering() const
   {
      return !was_hover && hovering;
   }

   bool UIElement::is_clicked() const
   {
      return clicked;
   }

   bool UIElement::is_mouse_up() const
   {
      return mouse_up;
   }

   bool UIElement::is_mouse_down() const
   {
      return mouse_down;
   }

   void UIElement::on_update(const std::function<void(UIElement&)>& func)
   {
      on_update_func = std::make_shared<std::function<void(UIElement&)>>(func ? func : [](UIElement&){});
   }

   void UIElement::on_update(const Functions& func)
   {
      on_update(*func.func);
   }

   // Update functions

   void UIElement::update_state(const MouseState& state, bool local)
   {
      was_hover = hovering;
      hovering = (local ? get_local_bounds().contains(state.position) : contains(state.position));

      const bool is_mouse_down = (hovering && state.is_down);
      mouse_up = !is_mouse_down && mouse_down && hovering;
      clicked = is_mouse_down && !mouse_down && hovering;
      mouse_down = is_mouse_down;

      (*on_update_func)(*this);
   }
}
