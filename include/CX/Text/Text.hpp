#ifndef CX_TEXT_TEXT_HPP
#define CX_TEXT_TEXT_HPP

#include <SFML/Graphics/Text.hpp>
#include "CX/Text/FontStyle.hpp"
#include "CX/Text/TextStyle.hpp"
#include "CX/UIElement/UIElement.hpp"

namespace cx
{
   /// @brief Modify and display text.
   class Text : public UIElement
   {
   public:
      // Constructors
      
      /// @brief Create a default text.
      Text();
      ~Text() = default;

      /// @brief Create a new text.
      /// @param style Style of the text.
      /// @param string String of the text.
      Text(const TextStyle& style,
           const std::string& string);

      /// @brief Create a new text.
      /// @param string String of the text.
      /// @param font Font of the text.
      /// @param position Position of the text.
      /// @param char_size Character size of the text.
      /// @param outline_thickness Outline thickness of the text.
      Text(const std::string& string,
           const sf::Font& font,
           const Vec2f& position = Vec2f(),
           unsigned char_size = 32U,
           float outline_thickness = 0.f);

      // Constructors after creation

      /// @brief Create a new text.
      /// @param style Style of the text.
      /// @param string String of the text.
      void create(const TextStyle& style,
                  const std::string& string);

      /// @brief Create a new text.
      /// @param string String of the text.
      /// @param font Font of the text.
      /// @param position Position of the text.
      /// @param char_size Character size of the text.
      /// @param outline_thickness Outline thickness of the text.
      void create(const std::string& string,
                  const sf::Font& font,
                  const Vec2f& position = Vec2f(),
                  unsigned char_size = 32U,
                  float outline_thickness = 0.f);

      // Setter functions

      /// @brief Import UIElement functions to not override them.
      using UIElement::set_center;
      using UIElement::set_top_left;
      using UIElement::set_bottom_right;
      using UIElement::set_scale;
      using UIElement::set_size;
      using UIElement::set_rotation;

      /// @brief Change string of the text.
      /// @param string New string.
      /// @param stay_still Should text stay still.
      void set_string(const std::string& string, bool stay_still = false);

      /// @brief Change font of the text.
      /// @param font New font.
      void set_font(const sf::Font& font);

      /// @brief Change character size of the text.
      /// @param char_size New character size.
      void set_char_size(unsigned char_size);

      /// @brief Change style of the text.
      /// @param style New style.
      void set_style(FontStyle style);

      /// @brief Change center position of the text.
      /// @param position New center.
      void set_center(const Vec2f& position) override;

      /// @brief Change top-left position of the text.
      /// @param position New position.
      void set_top_left(const Vec2f& position) override;

      /// @brief Change bottom-right position of the text.
      /// @param position New position.
      void set_bottom_right(const Vec2f& position) override;

      /// @brief Change scale of the text.
      /// @param scale New scale.
      void set_scale(const Vec2f& scale) override;

      /// @brief Change size of the text.
      /// @param size New size.
      void set_size(const Vec2f& size) override;

      /// @brief Change rotation of the text.
      /// @param angle New rotation in degrees.
      void set_rotation(float angle) override;

      /// @brief Change color of the text.
      /// @param color New color.
      void set_color(const Color& color) override;

      /// @brief Change outline color of the text.
      /// @param color New outline color.
      void set_outline_color(const Color& color) override;

      /// @brief Change outline thickness of the text.
      /// @param thickness New outline thickness.
      void set_outline_thickness(float thickness) override;

      // Text specific functions

      /// @brief Place and rotate text inside of the boundaries.
      /// @param bounds Boundaries.
      void place_inside(const Vec5f& bounds);

      /// @brief Place text inside of the boundaries.
      /// @param bounds Boundaries.
      void place_inside(const Vec4f& bounds);

      /// @brief Fit text inside of a certain size.
      /// @param size Size.
      void fit_inside(const Vec2f& size);

      /// @brief Wrap and rotate text inside of the boundaries.
      /// @param bounds Boundaries.
      void wrap_inside(const Vec5f& bounds);

      /// @brief Wrap text inside of the boundaries.
      /// @param bounds Boundaries.
      void wrap_inside(const Vec4f& bounds);
      
      /// @brief Wrap text to fit in the width.
      /// @param width Width.
      void wrap(float maxWidth);

      /// @brief Truncate and rotate text inside of the boundaries.
      /// @param bounds Boundaries.
      void truncate_inside(const Vec5f& bounds);

      /// @brief Truncate text inside of the boundaries.
      /// @param bounds Boundaries.
      void truncate_inside(const Vec4f& bounds);

      /// @brief Truncate text to fit in the width.
      /// @param width Width.
      void truncate(float maxWidth);

      // Getter functions

      /// @brief Get text type.
      /// @return Type.
      ElementType get_element_type() const override;

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
      FontStyle get_style() const;

      /// @brief Get center position of the text.
      /// @return Center.
      Vec2f get_center() const override;

      /// @brief Get scale of the text.
      /// @return Scale.
      Vec2f get_scale() const override;

      /// @brief Get size of the text.
      /// @return Size.
      Vec2f get_size() const override;

      /// @brief Get origin of the text.
      /// @return Origin.
      Vec2f get_origin() const override;

      /// @brief Get rotation of the text.
      /// @return Rotation in degrees.
      Deg get_rotation() const override;

      /// @brief Get color of the text.
      /// @return Color.
      Color get_color() const override;

      /// @brief Get outline color of the text.
      /// @return Outline color.
      Color get_outline_color() const override;

      /// @brief Get outline thickness of the text.
      /// @return Outline thickness.
      float get_outline_thickness() const override;

      // Update functions

      /// @brief Update text's state and functions.
      /// @param state Mouse state.
      /// @param local Should local boundaries be used.
      void update(const MouseState& state, bool local = false) override;

      // Render functions

      /// @brief Render the text.
      /// @param window Window to draw to.
      void render(sf::RenderWindow& window) const override;

      /// @brief Render the text.
      /// @param window Window to draw to.
      /// @param shader Shader.
      void render(sf::RenderWindow& window, const sf::Shader* shader) const override;

      // Access functions

      /// @brief Get text.
      /// @return Text.
      sf::Text& get_text();

   private:
      sf::Text text;

      /// @brief Recenter the text.
      void recenter();
   };

   /// @brief Bitwise OR operator.
   /// @param left Left text type.
   /// @param right Right text type.
   /// @return Combination of styles.
   constexpr FontStyle operator|(FontStyle left, FontStyle right)
   {
      return static_cast<FontStyle>(static_cast<char>(left)
         | static_cast<char>(right));
   }

   /// @brief Compound OR operator.
   /// @param left Left text type.
   /// @param right Right text type.
   /// @return Combination of styles.
   constexpr FontStyle& operator|=(FontStyle& left, FontStyle right)
   {
      left = left | right;
      return left;
   }

   /// @brief Bitwise AND operator.
   /// @param left Left text type.
   /// @param right Right text type.
   /// @return Matching styles.
   constexpr FontStyle operator&(FontStyle left, FontStyle right)
   {
      return static_cast<FontStyle>(static_cast<char>(left)
         & static_cast<char>(right));
   }

   /// @brief Compound AND operator.
   /// @param left Left text type.
   /// @param right Right text type.
   /// @return Matching styles.
   constexpr FontStyle& operator&=(FontStyle& left, FontStyle right)
   {
      left = left & right;
      return left;
   }

   /// @brief Bitwise NOT operator.
   /// @param value Value to invert.
   /// @return Opposite value.
   constexpr FontStyle operator~(FontStyle value)
   {
      return static_cast<FontStyle>(~static_cast<char>(value));
   }
}

#endif
