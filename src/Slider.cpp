#include "CX/Slider/Slider.hpp"

#include "CX/Config.hpp" // IWYU pragma: export

namespace cx
{
   // Set default styles

   std::unique_ptr<SliderStyle> SliderStyle::style1_t;
   std::unique_ptr<SliderStyle> SliderStyle::style2_t;
   std::unique_ptr<SliderStyle> SliderStyle::style3_t;

   // Constructors

   Slider::Slider()
   {
      if (!clip_shader.loadFromFile(CX_SHADER_PATH "clipping_shader.frag", sf::Shader::Fragment))
         throw std::runtime_error(errors::slider::could_not_load_shader);

      clip_shader.setUniform("texture", sf::Shader::CurrentTexture);
      clip_shader.setUniform("progress", slider_progress);

      foreground.setOutlineColor(Color(0));
      background.setOutlineColor(Color(0));
      knob.setOutlineColor(Color(0));
   }

   Slider::Slider(const SliderStyle& style,
                  float step,
                  float min_value,
                  float max_value,
                  float progress)
   {
      if (!clip_shader.loadFromFile(CX_SHADER_PATH "clipping_shader.frag", sf::Shader::Fragment))
         throw std::runtime_error(errors::slider::could_not_load_shader);

      slider_step = step;
      slider_min = min_value;
      slider_max = max_value;
      slider_progress = std::clamp(progress, 0.f, 1.f);
      calculate_value();

      background.setSize(style.size);
      background.setOrigin(style.size * .5f);
      background.setFillColor(style.bg_color);
      background.setOutlineColor(style.bg_outline_color);
      background.setOutlineThickness(style.bg_outline_thickness);
      background.setTexture(style.bg_texture.get());

      foreground.setSize(style.size);
      foreground.setOrigin(background.getOrigin());
      foreground.setFillColor(style.fg_color);
      foreground.setOutlineColor(style.fg_outline_color);
      foreground.setOutlineThickness(style.fg_outline_thickness);
      foreground.setTexture(style.fg_texture.get());

      knob.setSize(style.knob_size);
      knob.setOrigin(style.knob_size * .5f);
      knob.setFillColor(style.knob_color);
      knob.setOutlineColor(style.knob_outline_color);
      knob.setOutlineThickness(style.knob_outline_thickness);
      knob.setTexture(style.knob_texture.get());

      reposition_knob();
   }

   Slider::Slider(const Vec2f& background_size,
                  const Vec2f& knob_size,
                  const Vec2f& position,
                  float step,
                  float min_value,
                  float max_value,
                  float progress)
   {
      if (!clip_shader.loadFromFile(CX_SHADER_PATH "clipping_shader.frag", sf::Shader::Fragment))
         throw std::runtime_error(errors::slider::could_not_load_shader);

      slider_step = step;
      slider_min = min_value;
      slider_max = max_value;
      slider_progress = std::clamp(progress, 0.f, 1.f);
      calculate_value();

      background.setSize(background_size);
      background.setOrigin(background_size * .5f);
      background.setPosition(position);
      background.setFillColor(Color(0));
      background.setOutlineColor(Color(0));

      foreground.setSize(background_size);
      foreground.setOrigin(background.getOrigin());
      foreground.setPosition(position);
      foreground.setFillColor(Color(255));
      foreground.setOutlineColor(Color(0));

      knob.setSize(knob_size);
      knob.setOrigin(knob_size * .5f);
      knob.setFillColor(Color(125));
      knob.setOutlineColor(Color(0));

      reposition_knob();
   }

   // Constructors after creation

   void Slider::create(const SliderStyle& style,
                       float step,
                       float min_value,
                       float max_value,
                       float progress)
   {
      if (!clip_shader.loadFromFile(CX_SHADER_PATH "clipping_shader.frag", sf::Shader::Fragment))
         throw std::runtime_error(errors::slider::could_not_load_shader);

      slider_step = step;
      slider_min = min_value;
      slider_max = max_value;
      slider_progress = std::clamp(progress, 0.f, 1.f);
      calculate_value();

      background.setSize(style.size);
      background.setOrigin(style.size * .5f);
      background.setFillColor(style.bg_color);
      background.setOutlineColor(style.bg_outline_color);
      background.setOutlineThickness(style.bg_outline_thickness);
      background.setTexture(style.bg_texture.get());

      foreground.setSize(style.size);
      foreground.setOrigin(background.getOrigin());
      foreground.setFillColor(style.fg_color);
      foreground.setOutlineColor(style.fg_outline_color);
      foreground.setOutlineThickness(style.fg_outline_thickness);
      foreground.setTexture(style.fg_texture.get());

      knob.setSize(style.knob_size);
      knob.setOrigin(style.knob_size * .5f);
      knob.setFillColor(style.knob_color);
      knob.setOutlineColor(style.knob_outline_color);
      knob.setOutlineThickness(style.knob_outline_thickness);
      knob.setTexture(style.knob_texture.get());

      reposition_knob();
   }

   void Slider::create(const Vec2f& background_size,
                       const Vec2f& knob_size,
                       const Vec2f& position,
                       float step,
                       float min_value,
                       float max_value,
                       float progress)
   {
      if (!clip_shader.loadFromFile(CX_SHADER_PATH "clipping_shader.frag", sf::Shader::Fragment))
         throw std::runtime_error(errors::slider::could_not_load_shader);

      slider_step = step;
      slider_min = min_value;
      slider_max = max_value;
      slider_progress = std::clamp(progress, 0.f, 1.f);
      calculate_value();

      background.setSize(background_size);
      background.setOrigin(background_size * .5f);
      background.setPosition(position);
      background.setFillColor(Color(0));
      background.setOutlineColor(Color(0));

      foreground.setSize(background_size);
      foreground.setOrigin(background.getOrigin());
      foreground.setPosition(position);
      foreground.setFillColor(Color(255));
      foreground.setOutlineColor(Color(0));

      knob.setSize(knob_size);
      knob.setOrigin(knob_size * .5f);
      knob.setFillColor(Color(125));
      knob.setOutlineColor(Color(0));

      reposition_knob();
   }

   // Setter functions

   void Slider::set_center(const Vec2f& center)
   {
      background.setPosition(center);
      foreground.setPosition(center);
      reposition_knob();
   }

   void Slider::set_top_left(const Vec2f& position)
   {
      background.setPosition(position + background.getOrigin());
      foreground.setPosition(background.getPosition());
      reposition_knob();
   }

   void Slider::set_bottom_right(const Vec2f& position)
   {
      background.setPosition(position - background.getOrigin());
      foreground.setPosition(background.getPosition());
      reposition_knob();
   }

   void Slider::set_scale(const Vec2f& scale)
   {
      background.setScale(scale);
      foreground.setScale(scale);
      knob.setScale(scale);
      reposition_knob();
   }

   void Slider::set_size(const Vec2f& size)
   {
      background.setSize(size);
      reposition_knob();
   }

   void Slider::set_knob_size(const Vec2f& size)
   {
      knob.setSize(size);
   }

   void Slider::set_knob_size(float width, float height)
   {
      knob.setSize(Vec2f(width, height));
   }

   void Slider::set_knob_size(float size)
   {
      knob.setSize(Vec2f(size));
   }

   void Slider::set_knob_width(float width)
   {
      knob.setSize(Vec2f(width, knob.getSize().y));
   }

   void Slider::set_knob_height(float height)
   {
      knob.setSize(Vec2f(knob.getSize().x, height));
   }

   void Slider::set_rotation(float angle)
   {
      background.setRotation(angle);
      foreground.setRotation(angle);
      knob.setRotation(angle);
      reposition_knob();
   }

   void Slider::set_texture(const sf::Texture* texture)
   {
      background.setTexture(texture);
      reposition_knob();
   }

   void Slider::set_fg_texture(const sf::Texture* texture)
   {
      foreground.setTexture(texture);
      reposition_knob();
   }

   void Slider::set_knob_texture(const sf::Texture* texture)
   {
      knob.setTexture(texture);
      reposition_knob();
   }

   void Slider::set_texture(const sf::Texture* bg_texture,
                            const sf::Texture* fg_texture,
                            const sf::Texture* knob_texture)
   {
      background.setTexture(bg_texture);
      foreground.setTexture(fg_texture);
      knob.setTexture(knob_texture);
      reposition_knob();
   }

   void Slider::set_texture_rect(const Vec4i& rect)
   {
      background.setTextureRect(rect);
   }

   void Slider::set_fg_texture_rect(const Vec4i& rect)
   {
      foreground.setTextureRect(rect);
   }

   void Slider::set_knob_texture_rect(const Vec4i& rect)
   {
      knob.setTextureRect(rect);
   }

   void Slider::set_texture_rect(const Vec4i& bg_rect,
                                 const Vec4i& fg_rect,
                                 const Vec4i& knob_rect)
   {
      background.setTextureRect(bg_rect);
      foreground.setTextureRect(fg_rect);
      knob.setTextureRect(knob_rect);
   }

   void Slider::set_color(const Color& color)
   {
      background.setFillColor(color);
   }

   void Slider::set_fg_color(const Color& color)
   {
      foreground.setFillColor(color);
   }

   void Slider::set_knob_color(const Color& color)
   {
      knob.setFillColor(color);
   }

   void Slider::set_color(const Color& bg_color,
                          const Color& fg_color,
                          const Color& knob_color)
   {
      background.setFillColor(bg_color);
      foreground.setFillColor(fg_color);
      knob.setFillColor(knob_color);
   }

   void Slider::set_outline_color(const Color& color)
   {
      background.setOutlineColor(color);
   }

   void Slider::set_fg_outline_color(const Color& color)
   {
      foreground.setOutlineColor(color);
   }

   void Slider::set_knob_outline_color(const Color& color)
   {
      knob.setOutlineColor(color);
   }

   void Slider::set_outline_color(const Color& bg_color,
                                  const Color& fg_color,
                                  const Color& knob_color)
   {
      background.setOutlineColor(bg_color);
      foreground.setOutlineColor(fg_color);
      knob.setOutlineColor(knob_color);
   }

   void Slider::set_outline_thickness(float thickness)
   {
      background.setOutlineThickness(thickness);
   }

   void Slider::set_fg_outline_thickness(float thickness)
   {
      foreground.setOutlineThickness(thickness);
   }

   void Slider::set_knob_outline_thickness(float thickness)
   {
      knob.setOutlineThickness(thickness);
   }

   void Slider::set_outline_thickness(float bg_thickness,
                                      float fg_thickness,
                                      float knob_thickness)
   {
      background.setOutlineThickness(bg_thickness);
      foreground.setOutlineThickness(fg_thickness);
      knob.setOutlineThickness(knob_thickness);
   }

   void Slider::set_step(float step)
   {
      slider_step = step;
   }

   void Slider::set_minimum_value(float min)
   {
      slider_min = min;
   }

   void Slider::set_maximum_value(float max)
   {
      slider_max = max;
   }

   void Slider::set_value_bounds(float min, float max)
   {
      slider_min = min;
      slider_max = max;
   }

   void Slider::set_value(float value)
   {
      slider_value = value;
      calculate_progress();
      reposition_knob();
   }

   void Slider::set_progress(float progress)
   {
      slider_progress = progress;
      calculate_value();
      reposition_knob();
   }

   void Slider::set_progress_percent(char percent)
   {
      slider_progress = static_cast<float>(percent) * .01f;
      calculate_value();
      reposition_knob();
   }

   // Getter functions

   ElementType Slider::get_element_type() const
   {
      return ElementType::slider;
   }

   Vec2f Slider::get_center() const
   {
      return background.getPosition();
   }

   Vec2f Slider::get_knob_center() const
   {
      return knob.getPosition();
   }

   Vec2f Slider::get_knob_top_left() const
   {
      return knob.getPosition() - get_knob_origin().sfml();
   }

   Vec2f Slider::get_knob_bottom_right() const
   {
      return knob.getPosition() + get_knob_origin().sfml();
   }

   Vec2f Slider::get_scale() const
   {
      return background.getScale();
   }

   Vec2f Slider::get_size() const
   {
      return get_scale().abs() * background.getSize();
   }

   Vec2f Slider::get_knob_size() const
   {
      return get_scale().abs() * knob.getSize();
   }

   Vec2f Slider::get_origin() const
   {
      return get_scale().abs() * background.getOrigin();
   }

   Vec2f Slider::get_knob_origin() const
   {
      return get_scale().abs() * knob.getOrigin();
   }

   float Slider::get_knob_origin_x() const
   {
      return knob.getOrigin().x;
   }

   float Slider::get_knob_origin_y() const
   {
      return knob.getOrigin().y;
   }

   Vec5f Slider::get_knob_bounds() const
   {
      return {get_knob_top_left(), get_knob_size(), get_rotation().degrees()};
   }

   Vec5f Slider::get_knob_local_bounds() const
   {
      return {get_knob_center() - get_knob_origin() / get_scale().abs(), get_knob_size() / get_scale().abs(), get_rotation().degrees()};
   }

   Vec4f Slider::get_knob_simple_bounds() const
   {
      return {get_knob_top_left(), get_knob_size()};
   }

   Deg Slider::get_rotation() const
   {
      return background.getRotation();
   }

   const sf::Texture* Slider::get_texture() const
   {
      return background.getTexture();
   }

   const sf::Texture* Slider::get_fg_texture() const
   {
      return foreground.getTexture();
   }

   const sf::Texture* Slider::get_knob_texture() const
   {
      return knob.getTexture();
   }

   Vec4i Slider::get_texture_rect() const
   {
      return background.getTextureRect();
   }

   Vec4i Slider::get_fg_texture_rect() const
   {
      return foreground.getTextureRect();
   }

   Vec4i Slider::get_knob_texture_rect() const
   {
      return knob.getTextureRect();
   }

   Color Slider::get_color() const
   {
      return background.getFillColor();
   }

   Color Slider::get_fg_color() const
   {
      return foreground.getFillColor();
   }

   Color Slider::get_knob_color() const
   {
      return knob.getFillColor();
   }

   Color Slider::get_outline_color() const
   {
      return background.getOutlineColor();
   }

   Color Slider::get_fg_outline_color() const
   {
      return foreground.getOutlineColor();
   }

   Color Slider::get_knob_outline_color() const
   {
      return knob.getOutlineColor();
   }

   float Slider::get_outline_thickness() const
   {
      return background.getOutlineThickness();
   }

   float Slider::get_fg_outline_thickness() const
   {
      return foreground.getOutlineThickness();
   }

   float Slider::get_knob_outline_thickness() const
   {
      return knob.getOutlineThickness();
   }

   float Slider::get_knob_width() const
   {
      return knob.getSize().x;
   }

   float Slider::get_knob_height() const
   {
      return knob.getSize().y;
   }

   float Slider::get_knob_center_x() const
   {
      return knob.getPosition().x;
   }

   float Slider::get_knob_center_y() const
   {
      return knob.getPosition().y;
   }

   float Slider::get_knob_left() const
   {
      return knob.getPosition().x - knob.getOrigin().x;
   }

   float Slider::get_knob_top() const
   {
      return knob.getPosition().y - knob.getOrigin().y;
   }

   float Slider::get_knob_right() const
   {
      return knob.getPosition().x + knob.getOrigin().x;
   }

   float Slider::get_knob_bottom() const
   {
      return knob.getPosition().y + knob.getOrigin().y;
   }

   float Slider::get_step() const
   {
      return slider_step;
   }

   float Slider::get_minimum_value() const
   {
      return slider_min;
   }

   float Slider::get_maximum_value() const
   {
      return slider_max;
   }

   float Slider::get_value() const
   {
      return slider_value;
   }

   float Slider::get_progress() const
   {
      return slider_progress;
   }

   char Slider::get_progress_percent() const
   {
      return static_cast<char>(slider_progress * 100.f);
   }

   // Update functions

   void Slider::increment_value(float value)
   {
      slider_value = std::clamp(slider_value + value, slider_min, slider_max);
      calculate_progress();
      reposition_knob();
   }

   void Slider::increment_progress(float value)
   {
      slider_progress = std::clamp(slider_progress + value, 0.f, 1.f);
      calculate_value();
      reposition_knob();
   }

   void Slider::increment_progress_percent(char percent)
   {
      slider_progress = std::clamp(slider_progress + static_cast<float>(percent) * .01f,
         0.f, 1.f);
      calculate_value();
      reposition_knob();
   }

   void Slider::decrement_value(float value)
   {
      slider_value = std::clamp(slider_value - value, slider_min, slider_max);
      calculate_progress();
      reposition_knob();
   }

   void Slider::decrement_progress(float value)
   {
      slider_progress = std::clamp(slider_progress - value, 0.f, 1.f);
      calculate_value();
      reposition_knob();
   }

   void Slider::decrement_progress_percent(char percent)
   {
      slider_progress = std::clamp(slider_progress - static_cast<float>(percent) * .01f,
         0.f, 1.f);
      calculate_value();
      reposition_knob();
   }

   void Slider::update_value(float value, bool condition)
   {
      slider_value = std::clamp(slider_value + (condition ? value : -value), slider_min, slider_max);
      calculate_progress();
      reposition_knob();
   }

   void Slider::update_progress(float value, bool condition)
   {
      slider_progress = std::clamp(slider_progress + (condition ? value : -value), 0.f, 1.f);
      calculate_value();
      reposition_knob();
   }

   void Slider::update_progress_percent(char percent, bool condition)
   {
      slider_progress = std::clamp(slider_progress + static_cast<float>(percent)
         * (condition ? .01f : -.01f), 0.f, 1.f);
      calculate_value();
      reposition_knob();
   }

   void Slider::update_value(float positive, float negative, bool condition)
   {
      slider_value = std::clamp(slider_value + (condition ? positive : -negative),
         slider_min, slider_max);
      calculate_progress();
      reposition_knob();
   }

   void Slider::update_progress(float positive, float negative, bool condition)
   {
      slider_progress = std::clamp(slider_progress + (condition ? positive : -negative),
         0.f, 1.f);
      calculate_value();
      reposition_knob();
   }

   void Slider::update_progress_percent(char positive, char negative, bool condition)
   {
      slider_progress = std::clamp(slider_progress + (condition ? static_cast<float>(positive)
         * .01f : static_cast<float>(negative) * -.01f), 0.f, 1.f);
      calculate_value();
      reposition_knob();
   }

   void Slider::update(const MouseState& state, bool local)
   {
      update_state(state, local);

      const bool mouse_on_knob = (local ? get_knob_local_bounds() : get_knob_bounds()).contains(state.position);

      if (mouse_on_knob && !slider_dragging && state.is_down)
         slider_dragging = true;

      if (!state.is_down && slider_dragging)
         slider_dragging = false;

      if (slider_dragging)
      {
         const float local = state.position.x - (background.getPosition().x - background.getOrigin().x * background.getScale().x);
         
         float progress = local / (background.getSize().x * background.getScale().x);

         if (background.getRotation() > 90.f && background.getRotation() < 270.f)
            progress = 1.f - progress;

         const float steps = (slider_max - slider_min) / slider_step;
         slider_progress = std::round(std::clamp(progress, 0.f, 1.f) * steps) / steps;

         calculate_value();
         reposition_knob();
      }
   }

   // Render functions

   void Slider::render(sf::RenderWindow& window) const
   {
      window.draw(background);

      if (slider_progress > 0.f && foreground.getTexture() != nullptr)
         window.draw(foreground, &clip_shader);
      else if (slider_progress > 0.f)
         window.draw(foreground);

      window.draw(knob);
   }

   void Slider::render(sf::RenderWindow& window, const sf::Shader* shader) const
   {
      window.draw(background, shader);

      if (slider_progress > 0.f && foreground.getTexture() != nullptr)
         window.draw(foreground, &clip_shader);
      else if (slider_progress > 0.f)
         window.draw(foreground, shader);

      window.draw(knob, shader);
   }

   // Access functions

   sf::RectangleShape& Slider::get_knob()
   {
      return knob;
   }

   sf::RectangleShape& Slider::get_foreground()
   {
      return foreground;
   }

   sf::RectangleShape& Slider::get_background()
   {
      return background;
   }

   // Private functions

   void Slider::calculate_value()
   {
      slider_value = std::clamp(slider_min + std::round(slider_progress * (slider_max - slider_min)
         / slider_step) * slider_step, slider_min, slider_max);
   }

   void Slider::calculate_progress()
   {
      slider_progress = std::clamp((slider_value - slider_min) / (slider_max - slider_min), 0.f, 1.f);
   }

   void Slider::reposition_knob()
   {
      clip_shader.setUniform("progress", slider_progress);
      clip_shader.setUniform("texture", sf::Shader::CurrentTexture);

      if (foreground.getTexture() == nullptr)
         foreground.setSize(Vec2f(background.getSize().x * slider_progress, background.getSize().y));
      else
         foreground.setSize(background.getSize());

      knob.setPosition(foreground.getPosition().x - foreground.getOrigin().x
         * foreground.getScale().x + background.getSize().x * slider_progress
         * foreground.getScale().x, foreground.getPosition().y);

      knob.setPosition(std::clamp(knob.getPosition().x, background.getPosition().x - background.getOrigin().x
         * background.getScale().x + knob.getOrigin().x * knob.getScale().x, background.getPosition().x
         + background.getOrigin().x * background.getScale().x - knob.getOrigin().x * knob.getScale().x), knob.getPosition().y);

      knob.setPosition(Vec2f(knob.getPosition() - foreground.getPosition())
         .rotate(foreground.getRotation() * M_PIf / 180.f)
         + foreground.getPosition());
   }
}
