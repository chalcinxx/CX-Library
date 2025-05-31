#ifndef CX_SLIDER_SLIDER_HPP
#define CX_SLIDER_SLIDER_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Shader.hpp>
#include "CX/Slider/SliderStyle.hpp"
#include "CX/UIElement/UIElement.hpp"

namespace cx
{
   /// @brief Modify and display sliders.
   class Slider : public UIElement
   {
   public:
      // Constructors

      /// @brief Create a default slider.
      Slider();
      ~Slider() = default;

      /// @brief Create a new slider.
      /// @param style Style of the slider.
      /// @param step Step of the slider.
      /// @param min_value Minimum slider value.
      /// @param max_value Maximum slider value.
      /// @param progress Progress of the slider.
      Slider(const SliderStyle& style,
             float step = 1.f,
             float min_value = 0.f,
             float max_value = 100.f,
             float progress = .5f);

      /// @brief Create a new slider.
      /// @param background_size Size of the background.
      /// @param knob_size Size of the knob.
      /// @param position Slider position.
      /// @param step Step of the slider.
      /// @param min_value Minimum slider value.
      /// @param max_value Maximum slider value.
      /// @param progress Progress of the slider.
      Slider(const Vec2f& background_size,
             const Vec2f& knob_size,
             const Vec2f& position = Vec2f(),
             float step = 1.f,
             float min_value = 0.f,
             float max_value = 100.f,
             float progress = .5f);
   
      // Constructors after creation

      /// @brief Create a new slider.
      /// @param style Style of the slider.
      /// @param step Step of the slider.
      /// @param min_value Minimum slider value.
      /// @param max_value Maximum slider value.
      /// @param progress Progress of the slider.
      void create(const SliderStyle& style,
                  float step = 1.f,
                  float min_value = 0.f,
                  float max_value = 100.f,
                  float progress = .5f);

      /// @brief Create a new slider.
      /// @param background_size Size of the background.
      /// @param knob_size Size of the knob.
      /// @param position Slider position.
      /// @param step Step of the slider.
      /// @param min_value Minimum slider value.
      /// @param max_value Maximum slider value.
      /// @param progress Progress of the slider.
      void create(const Vec2f& background_size,
                  const Vec2f& knob_size,
                  const Vec2f& position = Vec2f(),
                  float step = 1.f,
                  float min_value = 0.f,
                  float max_value = 100.f,
                  float progress = .5f);
   
      // Setter functions

      /// @brief Import UIElement functions to not override them.
      using UIElement::set_center;
      using UIElement::set_top_left;
      using UIElement::set_bottom_right;
      using UIElement::set_scale;
      using UIElement::set_size;
      using UIElement::set_rotation;

      /// @brief Change center position of the slider.
      /// @param center New center.
      void set_center(const Vec2f& center) override;

      /// @brief Change top-left position of the slider.
      /// @param position New position.
      void set_top_left(const Vec2f& position) override;

      /// @brief Change bottom-right position of the slider.
      /// @param position New position.
      void set_bottom_right(const Vec2f& position) override;

      /// @brief Change scale of the slider.
      /// @param scale New scale.
      void set_scale(const Vec2f& scale) override;

      /// @brief Change size of the background.
      /// @param size New size.
      void set_size(const Vec2f& size) override;

      /// @brief Change size of the knob.
      /// @param size New size.
      void set_knob_size(const Vec2f& size);

      /// @brief Change size of the knob.
      /// @param width New X size.
      /// @param height New Y size.
      void set_knob_size(float width, float height);

      /// @brief Change size of the knob.
      /// @param size New size.
      void set_knob_size(float size);

      /// @brief Change width of the knob.
      /// @param width New width.
      void set_knob_width(float width);

      /// @brief Change height of the knob.
      /// @param height New height.
      void set_knob_height(float height);

      /// @brief Change rotation of the slider.
      /// @param angle New rotation in degrees.
      void set_rotation(float angle) override;

      /// @brief Change texture of the background.
      /// @param texture New texture.
      void set_texture(const sf::Texture* texture);

      /// @brief Change texture of the foreground.
      /// @param texture New texture.
      void set_fg_texture(const sf::Texture* texture);

      /// @brief Change texture of the knob.
      /// @param texture New texture.
      void set_knob_texture(const sf::Texture* texture);

      /// @brief Change texture of the background, foreground and the knob.
      /// @param bg_texture New background texture.
      /// @param fg_texture New foreground texture.
      /// @param knob_texture New knob texture.
      void set_texture(const sf::Texture* bg_texture,
                       const sf::Texture* fg_texture,
                       const sf::Texture* knob_texture);
      
      /// @brief Change texture rectangle of the background.
      /// @param rect New texture rectangle.
      void set_texture_rect(const Vec4i& rect);

      /// @brief Change texture rectangle of the foreground.
      /// @param rect New texture rectangle.
      void set_fg_texture_rect(const Vec4i& rect);

      /// @brief Change texture rectangle of the knob.
      /// @param rect New texture rectangle.
      void set_knob_texture_rect(const Vec4i& rect);

      /// @brief Change texture rectangle of the background, foreground and the knob.
      /// @param bg_rect New background texture rectangle.
      /// @param fg_rect New foreground texture rectangle.
      /// @param knob_rect New knob texture rectangle.
      void set_texture_rect(const Vec4i& bg_rect,
                            const Vec4i& fg_rect,
                            const Vec4i& knob_rect);

      /// @brief Change color of the background.
      /// @param color New color.
      void set_color(const Color& color) override;

      /// @brief Change color of the foreground.
      /// @param color New color.
      void set_fg_color(const Color& color);

      /// @brief Change color of the knob.
      /// @param color New color.
      void set_knob_color(const Color& color);

      /// @brief Change color of the background, foreground and the knob.
      /// @param bg_color New background color.
      /// @param fg_color New foreground color.
      /// @param knob_color New knob color.
      void set_color(const Color& bg_color,
                     const Color& fg_color,
                     const Color& knob_color);

      /// @brief Change outline color of the background.
      /// @param color New color.
      void set_outline_color(const Color& color) override;

      /// @brief Change outline color of the foreground.
      /// @param color New color.
      void set_fg_outline_color(const Color& color);

      /// @brief Change outline color of the knob.
      /// @param color New color.
      void set_knob_outline_color(const Color& color);

      /// @brief Change outline color of the background, foreground and the knob.
      /// @param bg_color New background color.
      /// @param fg_color New foreground color.
      /// @param knob_color New knob color.
      void set_outline_color(const Color& bg_color,
                             const Color& fg_color,
                             const Color& knob_color);

      /// @brief Change outline thickness of the background.
      /// @param thickness New thickness.
      void set_outline_thickness(float thickness) override;

      /// @brief Change outline thickness of the foreground.
      /// @param thickness New thickness.
      void set_fg_outline_thickness(float thickness);

      /// @brief Change outline thickness of the knob.
      /// @param thickness New thickness.
      void set_knob_outline_thickness(float thickness);

      /// @brief Change outline thickness of the background, foreground and the knob.
      /// @param bg_thickness New background thickness.
      /// @param fg_thickness New foreground thickness.
      /// @param knob_thickness New knob thickness.
      void set_outline_thickness(float bg_thickness,
                                 float fg_thickness,
                                 float knob_thickness);

      /// @brief Set slider step.
      /// @param step New step.
      void set_step(float step);

      /// @brief Set minimum slider value.
      /// @param min Minimum value.
      void set_minimum_value(float min);

      /// @brief Set maximum slider value.
      /// @param max maximum value.
      void set_maximum_value(float max);

      /// @brief Set minimum and maximum slider values.
      /// @param min Minimum value.
      /// @param max Maximum value.
      void set_value_bounds(float min, float max);

      /// @brief Set slider value.
      /// @param value New value.
      void set_value(float value);

      /// @brief Set slider progress.
      /// @param progress New progress 0 to 1.
      void set_progress(float progress);

      /// @brief Set slider progress in percent.
      /// @param percent Progress 0 to 100.
      void set_progress_percent(char percent);

      // Getter functions

      /// @brief Get slider type.
      /// @return Type.
      ElementType get_element_type() const override;

      /// @brief Get center position of the slider.
      /// @return Center.
      Vec2f get_center() const override;

      /// @brief Get center position of the knob.
      /// @return Center.
      Vec2f get_knob_center() const;

      /// @brief Get top-left position of the knob.
      /// @return Position.
      Vec2f get_knob_top_left() const;

      /// @brief Get bottom-right position of the knob.
      /// @return Position.
      Vec2f get_knob_bottom_right() const;

      /// @brief Get scale of the slider.
      /// @return Scale.
      Vec2f get_scale() const override;

      /// @brief Get size of the background.
      /// @return Background size.
      Vec2f get_size() const override;

      /// @brief Get size of the knob.
      /// @return Knob size.
      Vec2f get_knob_size() const;

      /// @brief Get origin.
      /// @return Origin.
      Vec2f get_origin() const override;

      /// @brief Get knob origin.
      /// @return Knob origin.
      Vec2f get_knob_origin() const;

      /// @brief Get knob origin X.
      /// @return Knob origin X.
      float get_knob_origin_x() const;

      /// @brief Get knob origin Y.
      /// @return Knob origin Y.
      float get_knob_origin_y() const;

      /// @brief Get global boundaries of the knob.
      /// @return Global boundaries.
      Vec5f get_knob_bounds() const;

      /// @brief Get local boundaries of the knob.
      /// @return Local boundaries.
      Vec5f get_knob_local_bounds() const;

      /// @brief Get global boundaries of the knob without rotation.
      /// @return Simple boundaries.
      Vec4f get_knob_simple_bounds() const;

      /// @brief Get rotation of the slider.
      /// @return Rotation in degrees.
      Deg get_rotation() const override;

      /// @brief Get texture of the background.
      /// @return Texture.
      const sf::Texture* get_texture() const;

      /// @brief Get texture of the foreground.
      /// @return Texture.
      const sf::Texture* get_fg_texture() const;

      /// @brief Get texture of the knob.
      /// @return Texture.
      const sf::Texture* get_knob_texture() const;

      /// @brief Get texture rectangle of the background.
      /// @return Texture rectangle.
      Vec4i get_texture_rect() const;

      /// @brief Get texture rectangle of the foreground.
      /// @return Texture rectangle.
      Vec4i get_fg_texture_rect() const;

      /// @brief Get texture rectangle of the knob.
      /// @return Texture rectangle.
      Vec4i get_knob_texture_rect() const;

      /// @brief Get color of the background.
      /// @return Color.
      Color get_color() const override;

      /// @brief Get color of the foreground.
      /// @return Color.
      Color get_fg_color() const;

      /// @brief Get color of the knob.
      /// @return Color.
      Color get_knob_color() const;

      /// @brief Get outline color of the background.
      /// @return Outline color.
      Color get_outline_color() const override;

      /// @brief Get outline color of the foreground.
      /// @return Outline color.
      Color get_fg_outline_color() const;

      /// @brief Get outline color of the knob.
      /// @return Outline color.
      Color get_knob_outline_color() const;

      /// @brief Get outline thickness of the background.
      /// @return Outline thickness.
      float get_outline_thickness() const override;

      /// @brief Get outline thickness of the foreground.
      /// @return Outline thickness.
      float get_fg_outline_thickness() const;

      /// @brief Get outline thickness of the knob.
      /// @return Outline thickness.
      float get_knob_outline_thickness() const;

      /// @brief Get width of the knob.
      /// @return Width.
      float get_knob_width() const;

      /// @brief Get height of the knob.
      /// @return Height.
      float get_knob_height() const;

      /// @brief Get X center of the knob.
      /// @return X center.
      float get_knob_center_x() const;

      /// @brief Get Y center of the knob.
      /// @return Y center.
      float get_knob_center_y() const;

      /// @brief Get X position of the knob.
      /// @return X position.
      float get_knob_left() const;

      /// @brief Get Y position of the knob.
      /// @return Y position.
      float get_knob_top() const;
      
      /// @brief Get right position of the knob.
      /// @return Right position.
      float get_knob_right() const;
      
      /// @brief Get bottom position of the knob.
      /// @return Bottom position.
      float get_knob_bottom() const;

      /// @brief Get slider step.
      /// @return Step.
      float get_step() const;

      /// @brief Get slider minimum value.
      /// @return Minimum value.
      float get_minimum_value() const;

      /// @brief Get slider maximum value.
      /// @return Maximum value.
      float get_maximum_value() const;

      /// @brief Get slider value.
      /// @return Value.
      float get_value() const;

      /// @brief Get slider progress.
      /// @return Progress.
      float get_progress() const;

      /// @brief Get slider progress in percent.
      /// @return Progress.
      char get_progress_percent() const;

      // Update functions

      /// @brief Increment slider value.
      /// @param value Amount to increment by.
      void increment_value(float value);

      /// @brief Increment slider progress.
      /// @param value Amount to increment by.
      void increment_progress(float value);

      /// @brief Increment slider progress in percent.
      /// @param percent Amount to increment by.
      void increment_progress_percent(char percent);

      /// @brief Decrement slider value.
      /// @param value Amount to decrement by.
      void decrement_value(float value);

      /// @brief Decrement slider progress.
      /// @param value Amount to decrement by.
      void decrement_progress(float value);

      /// @brief Decrement var progress in percent.
      /// @param percent Amount to decrement by.
      void decrement_progress_percent(char percent);

      /// @brief Update slider value based on condition.
      /// @param value Amount to increment or decrement by.
      /// @param condition Condition.
      void update_value(float value, bool condition);

      /// @brief Update slider progress based on condition.
      /// @param value Amount to increment or decrement by.
      /// @param condition Condition.
      void update_progress(float value, bool condition);

      /// @brief Update slider progress in percent based on condition.
      /// @param value Amount to increment or decrement by.
      /// @param condition Condition.
      void update_progress_percent(char percent, bool condition);

      /// @brief Update slider value based on condition.
      /// @param positive Amount to increment by.
      /// @param negative Amount to decrement by.
      /// @param condition Condition.
      void update_value(float positive, float negative, bool condition);

      /// @brief Update slider progress based on condition.
      /// @param positive Amount to increment by.
      /// @param negative Amount to decrement by.
      /// @param condition Condition.
      void update_progress(float positive, float negative, bool condition);

      /// @brief Update slider progress in percent based on condition.
      /// @param positive Amount to increment by.
      /// @param negative Amount to decrement by.
      /// @param condition Condition.
      void update_progress_percent(char positive, char negative, bool condition);

      /// @brief Update slider's values, state and functions.
      /// @param state Mouse state.
      /// @param local Should local boundaries be used.
      void update(const MouseState& state, bool local = false) override;

      // Render functions

      /// @brief Render the slider.
      /// @param window Window to draw to.
      void render(sf::RenderWindow& window) const override;

      /// @brief Render the slider.
      /// @param window Window to draw to.
      /// @param shader Shader.
      void render(sf::RenderWindow& window, const sf::Shader* shader) const override;

      // Access functions

      /// @brief Get knob.
      /// @return Knob.
      sf::RectangleShape& get_knob();

      /// @brief Get foreground.
      /// @return Foreground.
      sf::RectangleShape& get_foreground();

      /// @brief Get background.
      /// @return Background.
      sf::RectangleShape& get_background();

   private:
      sf::Shader clip_shader;
      sf::RectangleShape knob;
      sf::RectangleShape foreground;
      sf::RectangleShape background;
      float slider_step     = 1.f;
      float slider_min      = 0.f;
      float slider_max      = 100.f;
      float slider_progress = .5f;
      float slider_value    = 50.f;
      bool slider_dragging  = false;

      /// @brief Calculate the slider value from the progress.
      void calculate_value();

      /// @brief Calculate the slider progress from the value.
      void calculate_progress();

      /// @brief Set the foreground and knob based on progress.
      void reposition_knob();
   };
}

#endif
