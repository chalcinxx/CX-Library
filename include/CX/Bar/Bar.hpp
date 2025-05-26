#ifndef CX_BAR_BAR_HPP
#define CX_BAR_BAR_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Shader.hpp>
#include "CX/Bar/BarStyle.hpp"
#include "CX/UIElement/UIElement.hpp"

namespace cx
{
   /// @brief Modify and display progress bars.
   class Bar : public UIElement
   {
   public:
      // Constructors

      /// @brief Create a default bar.
      Bar();
      ~Bar() = default;

      /// @brief Create a new bar.
      /// @param style Style of the bar.
      /// @param progress Progress of the bar 0 to 1.
      /// @param functions Functions of the bar.
      Bar(const BarStyle& style,
          float progress = 1.f,
          const Functions& functions = {});

      /// @brief Create a new bar.
      /// @param size Size of the bar.
      /// @param position Center position of the bar.
      /// @param progress Progress of the bar 0 to 1.
      /// @param fg_color Foreground color.
      /// @param bg_color Background color.
      /// @param functions Functions of the bar.
      Bar(const Vec2f& size,
          const Vec2f& position = Vec2f(),
          float progress = 1.f,
          const Color& fg_color = Color(255),
          const Color& bg_color = Color(0),
          const Functions& functions = {});

      // Constructors after creation

      /// @brief Create a new bar.
      /// @param style Style of the bar.
      /// @param progress Progress of the bar 0 to 1.
      /// @param functions Functions of the bar.
      void create(const BarStyle& style,
                  float progress = 1.f,
                  const Functions& functions = {});

      /// @brief Create a new bar.
      /// @param size Size of the bar.
      /// @param position Center position of the bar.
      /// @param progress Progress of the bar 0 to 1.
      /// @param fg_color Foreground color.
      /// @param bg_color Background color.
      /// @param functions Functions of the bar.
      void create(const Vec2f& size,
                  const Vec2f& position = Vec2f(),
                  float progress = 1.f,
                  const Color& fg_color = Color(255),
                  const Color& bg_color = Color(0),
                  const Functions& functions = {});

      // Setter functions

      /// @brief Change center position of the bar.
      /// @param position New center.
      void set_center(const Vec2f& position) override;

      /// @brief Change top-left position of the bar.
      /// @param position New position.
      void set_top_left(const Vec2f& position) override;

      /// @brief Change bottom-right position of the bar.
      /// @param position New position.
      void set_bottom_right(const Vec2f& position) override;

      /// @brief Change scale of the bar.
      /// @param scale New scale.
      void set_scale(const Vec2f& scale) override;

      /// @brief Change size of the bar.
      /// @param size New size.
      void set_size(const Vec2f& size) override;

      /// @brief Change rotation of the bar.
      /// @param angle New rotation in degrees.
      void set_rotation(float angle) override;

      /// @brief Change texture of the foreground.
      /// @param texture New texture.
      void set_texture(const sf::Texture* texture);

      /// @brief Change texture of the background.
      /// @param texture New texture.
      void set_bg_texture(const sf::Texture* texture);

      /// @brief Change textures of the foreground and background.
      /// @param fg_texture New foreground texture.
      /// @param bg_texture New background texture.
      void set_texture(const sf::Texture* fg_texture,
                       const sf::Texture* bg_texture);

      /// @brief Change texture rectangle of the foreground.
      /// @param texture_rect New texture rectangle.
      void set_texture_rect(const Vec4i& texture_rect);

      /// @brief Change texture rectangle of the background.
      /// @param texture_rect New texture rectangle.
      void set_bg_texture_rect(const Vec4i& texture_rect);

      /// @brief Change texture rectangle of the foreground and background.
      /// @param fg_texture_rect New foreground texture.
      /// @param bg_texture_rect New background texture.
      void set_texture_rect(const Vec4i& fg_texture_rect,
                            const Vec4i& bg_texture_rect);

      /// @brief Change color of the foreground.
      /// @param color New color.
      void set_color(const Color& color) override;

      /// @brief Change color of the background.
      /// @param color Nnew color.
      void set_bg_color(const Color& color);

      /// @brief Change color of the foreground and background.
      /// @param fg_color New foreground color.
      /// @param bg_color New background color.
      void set_color(const Color& fg_color, const Color& bg_color);

      /// @brief Change outline color of the foreground.
      /// @param color New color.
      void set_outline_color(const Color& color) override;

      /// @brief Change outline color of the background.
      /// @param color New color.
      void set_bg_outline_color(const Color& color);

      /// @brief Change outline color of the foreground and background.
      /// @param fg_color New foreground outline color.
      /// @param bg_color New background outline color.
      void set_outline_color(const Color& fg_color, const Color& bg_color);

      /// @brief Change outline thickness of the foreground.
      /// @param thickness New thickness.
      void set_outline_thickness(float thickness) override;

      /// @brief Change outline thickness of the background.
      /// @param thickness New thickness.
      void set_bg_outline_thickness(float thickness);

      /// @brief Change outline thickness of the foreground and background.
      /// @param fgThickness New foreground thickness.
      /// @param bgThickness New background thickness.
      void set_outline_thickness(float fg_thickness, float bg_thickness);

      /// @brief Change progress of the bar.
      /// @param progress Progress 0 to 1.
      void set_progress(float progress);

      /// @brief Change progress of the bar in percent.
      /// @param percent Progress 0 to 100.
      void set_progress_percent(char percent);

      // Getter functions

      /// @brief Get bar type.
      /// @return Type.
      ElementType get_element_type() const override;

      /// @brief Get center position of the bar.
      /// @return Center.
      Vec2f get_center() const override;

      /// @brief Get top-left position of the bar.
      /// @return Position.
      Vec2f get_top_left() const override;

      /// @brief Get bottom-right position of the bar.
      /// @return Position.
      Vec2f get_bottom_right() const override;

      /// @brief Get scale of the bar.
      /// @return Scale.
      Vec2f get_scale() const override;

      /// @brief Get size of the bar.
      /// @return Size.
      Vec2f get_size() const override;

      /// @brief Get origin of the bar.
      /// @return Origin.
      Vec2f get_origin() const override;

      /// @brief Get rotation of the bar.
      /// @return Rotation in degrees.
      Degrees get_rotation() const override;

      /// @brief Get texture of the foreground.
      /// @return Texture.
      const sf::Texture* get_texture() const;

      /// @brief Get texture of the background.
      /// @return Texture.
      const sf::Texture* get_bg_texture() const;

      /// @brief Get texture rectangle of the foreground.
      /// @return Texture rectangle.
      Vec4i get_texture_rect() const;

      /// @brief Get texture rectangle of the background.
      /// @return Texture rectangle.
      Vec4i get_bg_texture_rect() const;

      /// @brief Get color of the foreground.
      /// @return Color.
      Color get_color() const override;

      /// @brief Get color of the background.
      /// @return Color.
      Color get_bg_color() const;

      /// @brief Get outline color of the foreground.
      /// @return Outline color.
      Color get_outline_color() const override;

      /// @brief Get outline color of the background.
      /// @return Outline color.
      Color get_bg_outline_color() const;

      /// @brief Get outline thickness of the foreground.
      /// @return Outline thickness.
      float get_outline_thickness() const override;

      /// @brief Get outline thickness of the background.
      /// @return Outline thickness.
      float get_bg_outline_thickness() const;

      /// @brief Get progress of the bar.
      /// @return Progress.
      float get_progress() const;

      /// @brief Get progress of the bar in percent.
      /// @return Progress.
      char get_progress_percent() const;

      // Update functions

      /// @brief Increment bar progress.
      /// @param value Amount to increment by.
      void increment_progress(float value);

      /// @brief Increment bar progress in percent.
      /// @param percent Amount to increment by.
      void increment_progress_percent(char percent);

      /// @brief Decrement bar progress.
      /// @param value Amount to decrement by.
      void decrement_progress(float value);

      /// @brief Decrement bar progress.
      /// @param percent Amount to decrement by.
      void decrement_progress_percent(char value);

      /// @brief Update bar progress based on condition.
      /// @param value Amount to increment or decrement by.
      /// @param condition Condition.
      void update_progress(float value, bool condition);

      /// @brief Update bar progress in percent based on condition.
      /// @param value Amount to increment or decrement by.
      /// @param condition Condition.
      void update_progress_percent(char percent, bool condition);

      /// @brief Update bar progress based on condition.
      /// @param positive Amount to increment by.
      /// @param negative Amount to decrement by.
      /// @param condition Condition.
      void update_progress(float positive, float negative, bool condition);

      /// @brief Update bar progress in percent based on condition.
      /// @param positive Amount to increment by.
      /// @param negative Amount to decrement by.
      /// @param condition Condition.
      void update_progress_percent(char positive, char negative, bool condition);

      /// @brief Update bar's state and functions.
      /// @param state Mouse state.
      /// @param local Should local boundaries be used.
      void update(const MouseState& state, bool local = false) override;

      // Render functions

      /// @brief Render the bar.
      /// @param window Window to draw to.
      void render(sf::RenderWindow& window) const override;

      /// @brief Render the bar.
      /// @param window Window to draw to.
      /// @param shader Shader.
      void render(sf::RenderWindow& window, const sf::Shader* shader) const override;

      // Access functions

      /// @brief Get foreground.
      /// @return Foreground.
      sf::RectangleShape& get_foreground();

      /// @brief Get background.
      /// @return Background.
      sf::RectangleShape& get_background();

   private:
      sf::Shader clip_shader;
      sf::RectangleShape background;
      sf::RectangleShape foreground;
      float bar_progress = 1.f;

      /// @brief Update bar.
      void updateBar();
   };
}

#endif
