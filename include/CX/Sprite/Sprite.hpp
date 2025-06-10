#ifndef CX_SPRITE_SPRITE_HPP
#define CX_SPRITE_SPRITE_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include "CX/Sprite/Animation.hpp"
#include "CX/Sprite/SpriteStyle.hpp"
#include "CX/UIElement/UIElement.hpp"

namespace cx
{
   /// @brief Play animations and display sprites.
   class Sprite : public UIElement
   {
   public:
      // Constructors

      /// @brief Create a default sprite.
      Sprite();
      ~Sprite() = default;

      /// @brief Create a new sprite.
      /// @param style Style of the sprite.
      Sprite(const SpriteStyle& style);

      /// @brief Create a new sprite.
      /// @param size Size of the sprite.
      /// @param position Center position of the sprite.
      /// @param texture Texture of the sprite.
      /// @param texture_rect Texture rect of the sprite.
      Sprite(const Vec2f& size,
             const Vec2f& position,
             const sf::Texture* texture,
             const Vec4i& texture_rect = Vec4i());

      // Constructors after creation

      /// @brief Create a new sprite.
      /// @param style Style of the sprite.
      void create(const SpriteStyle& style);

      /// @brief Create a new sprite.
      /// @param size Size of the sprite.
      /// @param position Center position of the sprite.
      /// @param texture Texture of the sprite.
      /// @param texture_rect Texture rect of the sprite.
      void create(const Vec2f& size,
                  const Vec2f& position,
                  const sf::Texture* texture,
                  const Vec4i& texture_rect = Vec4i());

      // Setter functions

      /// @brief Import UIElement functions to not override them.
      using UIElement::set_center;
      using UIElement::set_scale;
      using UIElement::set_size;
      using UIElement::set_rotation;

      /// @brief Change center position of the sprite.
      /// @param position New center.
      void set_center(const Vec2f& position) override;

      /// @brief Change scale of the sprite.
      /// @param scale New scale.
      void set_scale(const Vec2f& scale) override;

      /// @brief Change size of the sprite.
      /// @param size New size.
      void set_size(const Vec2f& size) override;

      /// @brief Change rotation of the sprite.
      /// @param angle New rotation in degrees.
      void set_rotation(float angle) override;

      /// @brief Change texture of the sprite.
      /// @param texture New texture.
      void set_texture(const sf::Texture* texture);

      /// @brief Change texture rectangle of the sprite.
      /// @param rect New texture rectangle.
      void set_texture_rect(const Vec4i& rect);

      /// @brief Change color of the sprite.
      /// @param color New color.
      void set_color(const Color& color) override;

      // Getter functions

      /// @brief Get sprite type.
      /// @return Type.
      ElementType get_element_type() const override;

      /// @brief Get center position of the sprite.
      /// @return Center.
      Vec2f get_center() const override;

      /// @brief Get scale of the sprite.
      /// @return Scale.
      Vec2f get_scale() const override;

      /// @brief Get size of the sprite.
      /// @return Size.
      Vec2f get_size() const override;

      /// @brief Get origin of the sprite.
      /// @return Origin.
      Vec2f get_origin() const override;

      /// @brief Get rotation of the sprite.
      /// @return Rotation in degrees.
      Deg get_rotation() const override;

      /// @brief Get texture of the sprite.
      /// @return Texture.
      const sf::Texture* get_texture() const;

      /// @brief Get texture rectangle of the sprite.
      /// @return Texture rectangle.
      Vec4i get_texture_rect() const;

      /// @brief Get color of the sprite.
      /// @return Color.
      Color get_color() const override;

      // Update functions

      /// @brief Update sprite's state and functions.
      /// @param state Mouse state.
      /// @param local Should local boundaries be used.
      void update(const MouseState& state, bool local = false) override;

      /// @brief Update sprite's state, functions and animation.
      /// @param dt Delta time.
      /// @param state Mouse state.
      /// @param local Should local boundaries be used.
      void update_all(float dt, const MouseState& state, bool local = false);

      /// @brief Update sprite's animation.
      /// @param dt Delta time.
      void update_animation(float dt);

      // Animation functions

      /// @brief Resume animation.
      void play();

      /// @brief Pause animation.
      void pause();

      /// @brief Reset animation.
      void reset();

      /// @brief Advance frame by one.
      void advance_frame();

      /// @brief Add new animation to the list.
      /// @param identifier Animation identifier.
      /// @param animation Animation.
      /// @param default_animation Should animation be default.
      void add_animation(const std::string& identifier,
                         const Animation& animation,
                         bool default_animation = false);

      /// @brief Set default animation.
      /// @param identifier Animation identifier.
      void set_default_animation(const std::string& identifier);

      /// @brief Play animation.
      /// @param identifier Animation identifier.
      /// @param reset Should it reset if animation is already playing.
      void play_animation(const std::string& identifier, bool reset = false);

      /// @brief Check if animation is finished.
      /// @return True if finished.
      bool is_animation_finished() const;

      /// @brief Check if default animation is playing.
      /// @return True if default is playing.
      bool is_default_playing() const;

      /// @brief Check if an animation is playing.
      /// @return True if playing.
      bool is_playing() const;

      /// @brief Check if the animation is paused.
      /// @return True if paused.
      bool is_paused() const;

      /// @brief Set speed multiplier.
      /// @param multiplier Speed multiplier.
      void set_speed_multiplier(float multiplier);

      /// @brief Get frame index.
      /// @return Frame index.
      size_t get_frame_index() const;

      /// @brief Get speed multiplier.
      /// @return Speed multiplier.
      float get_speed_multiplier() const;

      /// @brief Get name of the playing animation.
      /// @return Name.
      const std::string& get_playing_animation() const;

      /// @brief Get name of the default animation.
      /// @return Name.
      const std::string& get_default_animation() const;

      /// @brief Clear all animations.
      void clear_animations();

      // Render functions

      /// @brief Render the sprite.
      /// @param window Window to draw to.
      void render(sf::RenderWindow& window) const override;

      /// @brief Render the sprite.
      /// @param window Window to draw to.
      /// @param shader Shader.
      void render(sf::RenderWindow& window,
                  const sf::Shader* shader) const override;

      // Access functions

      /// @brief Get sprite.
      /// @return Sprite.
      sf::RectangleShape& get_sprite();

      /// @brief Get animations.
      /// @return Animations.
      std::unordered_map<std::string, Animation>& get_animations();

   private:
      sf::RectangleShape rect;

      std::unordered_map<std::string, Animation> animations;
      std::string current_animation;
      std::string idle;

      bool playing      = false;
      size_t index      = 0;
      float elapsedTime = 0.f;
      float speedMult   = 1.f;
   };
}

#endif
