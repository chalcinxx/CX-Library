#include "CX/Bar/Bar.hpp"

#include "CX/Config.hpp" // IWYU pragma: export

namespace cx
{
   // Set default styles

   std::unique_ptr<BarStyle> BarStyle::style1_t;
   std::unique_ptr<BarStyle> BarStyle::style2_t;
   std::unique_ptr<BarStyle> BarStyle::style3_t;

   // Constructors

   Bar::Bar()
   {
      if (!clip_shader.loadFromFile(CX_SHADER_PATH "clipping_shader.frag", sf::Shader::Fragment))
         throw std::runtime_error("Could not load clipping_shader.frag!");

      clip_shader.setUniform("texture", sf::Shader::CurrentTexture);
      clip_shader.setUniform("progress", bar_progress);
   }

   Bar::Bar(const BarStyle& style,
            float progress)
   {
      if (!clip_shader.loadFromFile(CX_SHADER_PATH "clipping_shader.frag", sf::Shader::Fragment))
         throw std::runtime_error("Could not load clipping_shader.frag!");

      background.setSize(style.size);
      background.setOrigin(style.size * .5f);
      background.setFillColor(style.bg_color);
      background.setTexture(style.bg_texture.get());

      foreground.setFillColor(style.fg_color);
      foreground.setTexture(style.fg_texture.get());
      foreground.setOrigin(background.getOrigin());

      bar_progress = std::clamp(progress, 0.f, 1.f);
      updateBar();
   }

   Bar::Bar(const Vec2f& size,
            const Vec2f& position,
            float progress,
            const Color& fg_color,
            const Color& bg_color)
   {
      if (!clip_shader.loadFromFile(CX_SHADER_PATH "clipping_shader.frag", sf::Shader::Fragment))
         throw std::runtime_error("Could not load clipping_shader.frag!");

      background.setSize(size);
      background.setOrigin(size * .5f);
      background.setPosition(position);
      background.setFillColor(bg_color);

      foreground.setPosition(position);
      foreground.setFillColor(fg_color);
      foreground.setOrigin(background.getOrigin());
      
      bar_progress = std::clamp(progress, 0.f, 1.f);
      updateBar();
   }

   // Constructors after creation

   void Bar::create(const BarStyle& style,
                    float progress)
   {
      if (!clip_shader.loadFromFile(CX_SHADER_PATH "clipping_shader.frag", sf::Shader::Fragment))
         throw std::runtime_error("Could not load clipping_shader.frag!");

      background.setSize(style.size);
      background.setOrigin(style.size * .5f);
      background.setFillColor(style.bg_color);
      background.setTexture(style.bg_texture.get());

      foreground.setFillColor(style.fg_color);
      foreground.setTexture(style.fg_texture.get());
      foreground.setOrigin(background.getOrigin());

      bar_progress = std::clamp(progress, 0.f, 1.f);
      updateBar();
   }

   void Bar::create(const Vec2f& size,
                    const Vec2f& position,
                    float progress,
                    const Color& fg_color,
                    const Color& bg_color)
   {
      if (!clip_shader.loadFromFile(CX_SHADER_PATH "clipping_shader.frag", sf::Shader::Fragment))
         throw std::runtime_error("Could not load clipping_shader.frag!");

      background.setSize(size);
      background.setOrigin(size * .5f);
      background.setPosition(position);
      background.setFillColor(bg_color);

      foreground.setPosition(position);
      foreground.setFillColor(fg_color);
      foreground.setOrigin(background.getOrigin());
      
      bar_progress = std::clamp(progress, 0.f, 1.f);
      updateBar();
   }

   // Setter functions

   void Bar::set_center(const Vec2f& position)
   {
      background.setPosition(position);
      foreground.setPosition(position);
   }

   void Bar::set_scale(const Vec2f& scale)
   {
      background.setScale(scale);
      foreground.setScale(scale);
   }

   void Bar::set_size(const Vec2f& size)
   {
      background.setSize(size);
      updateBar();
   }

   void Bar::set_rotation(float angle)
   {
      background.setRotation(angle);
      foreground.setRotation(angle);
   }

   void Bar::set_texture(const sf::Texture* texture)
   {
      foreground.setTexture(texture);
      updateBar();
   }

   void Bar::set_bg_texture(const sf::Texture* texture)
   {
      background.setTexture(texture);
      updateBar();
   }

   void Bar::set_texture(const sf::Texture* fg_texture,
                         const sf::Texture* bg_texture)
   {
      foreground.setTexture(fg_texture);
      background.setTexture(bg_texture);
      updateBar();
   }

   void Bar::set_texture_rect(const Vec4i& texture_rect)
   {
      foreground.setTextureRect(texture_rect);
   }

   void Bar::set_bg_texture_rect(const Vec4i& texture_rect)
   {
      background.setTextureRect(texture_rect);
   }

   void Bar::set_texture_rect(const Vec4i& fg_texture_rect,
                              const Vec4i& bg_texture_rect)
   {
      foreground.setTextureRect(fg_texture_rect);
      background.setTextureRect(bg_texture_rect);
   }

   void Bar::set_color(const Color& color)
   {
      foreground.setFillColor(color);
   }

   void Bar::set_bg_color(const Color& color)
   {
      background.setFillColor(color);
   }

   void Bar::set_color(const Color& fg_color, const Color& bg_color)
   {
      foreground.setFillColor(fg_color);
      background.setFillColor(bg_color);
   }

   void Bar::set_bg_opacity(unsigned char opacity)
   {
      background.setFillColor(Color(get_bg_color(), opacity));
   }

   void Bar::set_progress(float progress)
   {
      bar_progress = std::clamp(progress, 0.f, 1.f);
      updateBar();
   }

   void Bar::set_progress_percent(char percent)
   {
      bar_progress = std::clamp(float(percent) * .01f, 0.f, 1.f);
      updateBar();
   }

   // Getter functions

   ElementType Bar::get_element_type() const
   {
      return ElementType::bar;
   }

   Vec2f Bar::get_center() const
   {
      return background.getPosition();
   }

   Vec2f Bar::get_scale() const
   {
      return background.getScale();
   }

   Vec2f Bar::get_size() const
   {
      return get_scale().abs() * background.getSize();
   }

   Vec2f Bar::get_origin() const
   {
      return get_scale().abs() * background.getOrigin();
   }

   Deg Bar::get_rotation() const
   {
      return background.getRotation();
   }

   const sf::Texture* Bar::get_texture() const
   {
      return foreground.getTexture();
   }

   const sf::Texture* Bar::get_bg_texture() const
   {
      return background.getTexture();
   }

   Vec4i Bar::get_texture_rect() const
   {
      return foreground.getTextureRect();
   }

   Vec4i Bar::get_bg_texture_rect() const
   {
      return background.getTextureRect();
   }

   Color Bar::get_color() const
   {
      return foreground.getFillColor();
   }

   Color Bar::get_bg_color() const
   {
      return background.getFillColor();
   }

   unsigned char Bar::get_bg_opacity() const
   {
      return background.getFillColor().a;
   }

   float Bar::get_progress() const
   {
      return bar_progress;
   }

   char Bar::get_progress_percent() const
   {
      return char(bar_progress * 100.f);
   }

   // Update functions

   void Bar::increment_progress(float value)
   {
      bar_progress = std::clamp(bar_progress + value, 0.f, 1.f);
      updateBar();
   }

   void Bar::increment_progress_percent(char percent)
   {
      bar_progress = std::clamp(bar_progress + float(percent) * .01f, 0.f, 1.f);
      updateBar();
   }

   void Bar::decrement_progress(float value)
   {
      bar_progress = std::clamp(bar_progress - value, 0.f, 1.f);
      updateBar();
   }

   void Bar::decrement_progress_percent(char percent)
   {
      bar_progress = std::clamp(bar_progress - float(percent) * .01f, 0.f, 1.f);
      updateBar();
   }

   void Bar::update_progress(float value, bool condition)
   {
      bar_progress = std::clamp(bar_progress + (condition ? value : -value), 0.f, 1.f);
      updateBar();
   }

   void Bar::update_progress_percent(char percent, bool condition)
   {
      bar_progress = std::clamp(bar_progress + float(condition ? percent : -percent) * .01f, 0.f, 1.f);
      updateBar();
   }

   void Bar::update_progress(float positive, float negative, bool condition)
   {
      bar_progress = std::clamp(bar_progress + (condition ? positive : -negative), 0.f, 1.f);
      updateBar();
   }

   void Bar::update_progress_percent(char positive, char negative, bool condition)
   {
      bar_progress = std::clamp(bar_progress + float(condition ? positive : -negative) * .01f, 0.f, 1.f);
      updateBar();
   }

   void Bar::update(const MouseState& state, bool local)
   {
      update_state(state, local);
   }

   // Render functions

   void Bar::render(sf::RenderWindow& window) const
   {
      window.draw(background);

      if (bar_progress > 0.f && foreground.getTexture() != nullptr)
         window.draw(foreground, &clip_shader);
      else if (bar_progress > 0.f)
         window.draw(foreground);
   }

   void Bar::render(sf::RenderWindow& window, const sf::Shader* shader) const
   {
      window.draw(background, shader);

      if (bar_progress > 0.f && foreground.getTexture() != nullptr)
         window.draw(foreground, &clip_shader);
      else if (bar_progress > 0.f)
         window.draw(foreground, shader);
   }

   // Access functions
   
   sf::RectangleShape& Bar::get_foreground()
   {
      return foreground;
   }

   sf::RectangleShape& Bar::get_background()
   {
      return background;
   }

   // Private functions

   void Bar::updateBar()
   {
      clip_shader.setUniform("progress", bar_progress);
      clip_shader.setUniform("texture", sf::Shader::CurrentTexture);

      if (foreground.getTexture() == nullptr)
         foreground.setSize(Vec2f(background.getSize().x * bar_progress, background.getSize().y));
      else
         foreground.setSize(background.getSize());
      
      background.setOrigin(background.getSize() * .5f);
      foreground.setOrigin(background.getOrigin());
   }
}
