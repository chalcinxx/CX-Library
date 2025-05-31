#ifndef CX_BUTTON_BUTTON_HPP
#define CX_BUTTON_BUTTON_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "CX/Button/ButtonStyle.hpp"
#include "CX/Text/FontStyle.hpp"
#include "CX/UIElement/UIElement.hpp"

namespace cx
{
   /// @brief Modify and display buttons.
   class Button : public UIElement
   {
   public:
      // Constructors

      /// @brief Create a default button.
      Button();
      ~Button() = default;

      /// @brief Create a new button.
      /// @param style Style of the button.
      /// @param string String of the text.
      Button(const ButtonStyle& style,
             const std::string& string);

      /// @brief Create a new button.
      /// @param color Color of the button.
      /// @param string String of the text.
      /// @param font Font of the text.
      /// @param size Size of the button.
      /// @param position Position of the button.
      /// @param char_size Character size of the text.
      Button(const Color& color,
             const std::string& string,
             const sf::Font& font,
             const Vec2f& size,
             const Vec2f& position = Vec2f(),
             unsigned char_size = 32);

      // Constructors after creation

      /// @brief Create a new button.
      /// @param style Style of the button.
      /// @param string String of the text.
      void create(const ButtonStyle& style,
                  const std::string& string);

      /// @brief Create a new button.
      /// @param color Color of the button.
      /// @param string String of the text.
      /// @param font Font of the text.
      /// @param size Size of the button.
      /// @param position Position of the button.
      /// @param char_size Character size of the text.
      void create(const Color& color,
                  const std::string& string,
                  const sf::Font& font,
                  const Vec2f& size,
                  const Vec2f& position = Vec2f(),
                  unsigned char_size = 32);

      // Setter functions

      /// @brief Import UIElement functions to not override them.
      using UIElement::set_center;
      using UIElement::set_top_left;
      using UIElement::set_bottom_right;
      using UIElement::set_scale;
      using UIElement::set_size;
      using UIElement::set_rotation;

      /// @brief Change center position of the button.
      /// @param position New center.
      void set_center(const Vec2f& position) override;

      /// @brief Change top-left position of the button.
      /// @param position New position.
      void set_top_left(const Vec2f& position) override;

      /// @brief Change bottom-right position of the button.
      /// @param position New position.
      void set_bottom_right(const Vec2f& position) override;

      /// @brief Change scale of the button.
      /// @param scale New scale.
      void set_scale(const Vec2f& scale) override;

      /// @brief Change size of the button.
      /// @param size New size.
      void set_size(const Vec2f& size) override;

      /// @brief Change rotation of the button.
      /// @param angle New rotation in degrees.
      void set_rotation(float angle) override;

      /// @brief Change texture of the button.
      /// @param texture New texture.
      void set_texture(const sf::Texture* texture);

      /// @brief Change texture rectangle of the button.
      /// @param texture_rect New texture rectangle.
      void set_texture_rect(const Vec4i& texture_rect);

      /// @brief Change color of the button.
      /// @param color New color.
      void set_color(const Color& color) override;

      /// @brief Change outline color of the button.
      /// @param color New color.
      void set_outline_color(const Color& color) override;

      /// @brief Change outline thickness of the button.
      /// @param thickness New thickness.
      void set_outline_thickness(float thickness) override;

      /// @brief Change string of the text.
      /// @param string New string.
      void set_string(const std::string& string);

      /// @brief Change font of the text.
      /// @param font New font.
      void set_font(const sf::Font& font);

      /// @brief Change character size of the text.
      /// @param char_size New character size.
      void set_char_size(unsigned char_size);

      /// @brief Change style of the text.
      /// @param style New style.
      void set_style(FontStyle style);

      /// @brief Change color of the text.
      /// @param color New color.
      void set_text_color(const Color& color);

      /// @brief Change outline color of the text.
      /// @param color New color.
      void set_text_outline_color(const Color& color);

      /// @brief Change outline thickness of the text.
      /// @param thickness New thickness.
      void set_text_outline_thickness(float thickness);

      /// @brief Set the button as disabled or enabled.
      /// @param disabled Should the button be disabled.
      void set_disabled(bool disabled);
      
      /// @brief Toggle disabled property of the button.
      void toggle_disabled();

      // Getter functions

      /// @brief Get button type.
      /// @return Type.
      ElementType get_element_type() const override;

      /// @brief Get center position of the button.
      /// @return Center.
      Vec2f get_center() const override;

      /// @brief Get scale of the button.
      /// @return Scale.
      Vec2f get_scale() const override;

      /// @brief Get size of the button.
      /// @return Size.
      Vec2f get_size() const override;

      /// @brief Get origin of the button.
      /// @return Origin.
      Vec2f get_origin() const override;

      /// @brief Get rotation of the button.
      /// @return Rotation in degrees.
      Deg get_rotation() const override;

      /// @brief Get texture of the button.
      /// @return Texture.
      const sf::Texture* get_texture() const;

      /// @brief Get texture rectangle of the button.
      /// @return Texture rectangle.
      Vec4i get_texture_rect() const;

      /// @brief Get color of the button.
      /// @return Color.
      Color get_color() const override;

      /// @brief Get outline color of the button.
      /// @return Outline color.
      Color get_outline_color() const override;

      /// @brief Get outline thickness of the button.
      /// @return Outline thickness.
      float get_outline_thickness() const override;

      /// @brief Get string of the text.
      /// @return String.
      std::string get_string() const;

      /// @brief Get font of the text.
      /// @return Font.
      const sf::Font& get_font() const;

      /// @brief Get character size of the text.
      /// @return Character size.
      unsigned get_char_size() const;

      /// @brief Get style of the text.
      /// @return Style.
      FontStyle get_text_style() const;

      /// @brief Get color of the text.
      /// @return Color.
      Color get_text_color() const;

      /// @brief Get outline color of the text.
      /// @return Outline color.
      Color get_text_outline_color() const;

      /// @brief Get outline thickness of the text.
      /// @return Outline thickness.
      float get_text_outline_thickness() const;

      /// @brief Get disabled property of the button.
      /// @return Disabled property.
      bool is_disabled() const;

      // Update functions

      /// @brief Truncate the text to fit in the button.
      void truncate();

      /// @brief Wrap the text to fit in the button.
      void wrap();

      /// @brief Wrap and truncate the text to fit in the button.
      void fit_inside();

      /// @brief Update button's state and functions.
      /// @param state Mouse state.
      /// @param local Should local boundaries be used.
      void update(const MouseState& state, bool local = false) override;

      // Render functions

      /// @brief Render the button.
      /// @param window Window to draw to.
      void render(sf::RenderWindow& window) const override;

      /// @brief Render the button.
      /// @param window Window to draw to.
      /// @param shader Shader.
      void render(sf::RenderWindow& window, const sf::Shader* shader) const override;

      // Access functions

      /// @brief Get background.
      /// @return Background.
      sf::RectangleShape& get_background();

      /// @brief Get text.
      /// @return Text.
      sf::Text& get_text();

   private:
      bool button_disabled = false;
      sf::RectangleShape rect;
      sf::Text text;

      /// @brief Recenter text.
      void recenter(); 
   };
}

#endif
