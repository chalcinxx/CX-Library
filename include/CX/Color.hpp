#ifndef CX_COLOR_HPP
#define CX_COLOR_HPP

#include <SFML/Graphics/Color.hpp>
#include "CX/Errors.hpp"
#include <stdexcept>

namespace cx
{
   /// @brief Create and modify RGBA colors.
   struct Color
   {
      // Items

      uint8_t r = 0;   ///< @brief Red.
      uint8_t g = 0;   ///< @brief Green.
      uint8_t b = 0;   ///< @brief Blue.
      uint8_t a = 255; ///< @brief Alpha.

      // Constructors

      /// @brief Create a fully black color.
      constexpr Color()
         : r(0), g(0), b(0), a(255) {}

      /// @brief Create a gray color.
      /// @param gray Gray intensity.
      /// @param alpha Alpha intensity.
      constexpr Color(uint8_t gray, uint8_t alpha = 255)
         : r(gray), g(gray), b(gray), a(alpha) {}

      /// @brief Create a new color.
      /// @param red Red intensity.
      /// @param green Green intensity.
      /// @param blue Blue intensity.
      /// @param alpha Alpha intensity.
      constexpr Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255)
         : r(red), g(green), b(blue), a(alpha) {}

      /// @brief Copy a color.
      /// @param other Color to copy.
      constexpr Color(const Color& other)
         : r(other.r), g(other.g), b(other.b), a(other.a) {}
      
      /// @brief Copy a color.
      /// @param other Color to copy.
      constexpr Color(const sf::Color& other)
         : r(other.r), g(other.g), b(other.b), a(other.a) {}
      
      // Constructors after creation

      /// @brief Create a gray color.
      /// @param gray Gray intensity.
      /// @param alpha Alpha intensity.
      constexpr void create(uint8_t gray, uint8_t alpha = 255)
      {
         r = g = b = gray;
         a = alpha;
      }

      /// @brief Create a new color.
      /// @param red Red intensity.
      /// @param green Green intensity.
      /// @param blue Blue intensity.
      /// @param alpha Alpha intensity.
      constexpr void create(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255)
      {
         r = red;
         g = green;
         b = blue;
         a = alpha;
      }

      /// @brief Copy a color.
      /// @param other Color to copy.
      constexpr void create(const Color& other)
      {
         r = other.r;
         g = other.g;
         b = other.b;
         a = other.a;
      }
      
      /// @brief Copy a color.
      /// @param other Color to copy.
      constexpr void create(const sf::Color& other)
      {
         r = other.r;
         g = other.g;
         b = other.b;
         a = other.a;
      }

      // Update functions

      /// @brief Blend two colors together.
      /// @param other Other color.
      /// @param t Blend strength.
      /// @return Mixed color.
      constexpr Color blend(const Color& other, float t = .5f) const
      {
         const auto inverse = 1.f - t;
         return Color(
            (r * inverse) + (other.r * t), (g * inverse) + (other.g * t),
            (b * inverse) + (other.b * t), (a * inverse) + (other.a * t)
         );
      }

      /// @brief Invert the color.
      /// @return Inverted color.
      constexpr Color invert() const
      {
         return Color(255 - r, 255 - g, 255 - b, a);
      }

      // Operator overloaded functions

      /// @brief Return value by index.
      /// @param index Index of the value.
      /// @return Value.
      constexpr uint8_t& operator[](size_t index)
      {
         if (index > 3)
            throw std::runtime_error(errors::color::out_of_bounds);
         return (index == 0 ? r : (index == 1 ? g : (index == 2 ? b : a)));
      }

      /// @brief Return value by index.
      /// @param index Index of the value.
      /// @return Value.
      constexpr uint8_t operator[](size_t index) const
      {
         if (index > 3)
            throw std::runtime_error(errors::color::out_of_bounds);
         return (index == 0 ? r : (index == 1 ? g : (index == 2 ? b : a)));
      }

      /// @brief Return value by index.
      /// @param index Index of the value.
      /// @return Value.
      constexpr uint8_t& at(size_t index)
      {
         return (*this)[index];
      }

      /// @brief Return value by index.
      /// @param index Index of the value.
      /// @return Value.
      constexpr uint8_t at(size_t index) const
      {
         return (*this)[index];
      }

      /// @brief Copy color.
      /// @param other Color to copy.
      /// @return Color.
      constexpr Color& operator=(const Color& other)
      {
         r = other.r;
         g = other.g;
         b = other.b;
         a = other.a;
         return *this;
      }

      /// @brief Copy color.
      /// @param other Color to copy.
      /// @return Color.
      constexpr Color& operator=(const sf::Color& other)
      {
         r = other.r;
         g = other.g;
         b = other.b;
         a = other.a;
         return *this;
      }

      /// @brief Convert to SFML color.
      inline operator sf::Color() const
      {
         return sf::Color(r, g, b, a);
      }

      /// @brief Check if two colors are not equal.
      /// @param other Other color.
      constexpr bool operator!=(const Color& other) const
      {
         return r != other.r || g != other.g || b != other.b || a != other.a;
      }

      /// @brief Check if two colors are not equal.
      /// @param other Other color.
      constexpr bool operator!=(const sf::Color& other) const
      {
         return r != other.r || g != other.g || b != other.b || a != other.a;
      }
      
      /// @brief Check if two colors are equal.
      /// @param other Other color.
      constexpr bool operator==(const Color& other) const
      {
         return !(*this != other);
      }
      /// @brief Check if two colors are equal.
      /// @param other Other color.
      constexpr bool operator==(const sf::Color& other) const
      {
         return !(*this != other);
      }

      // Static functions

      /// @brief Get red color.
      /// @return Red.
      static constexpr cx::Color red()
      {
         return cx::Color(255, 0, 0);
      }

      /// @brief Get orange color.
      /// @return Orange.
      static constexpr cx::Color orange()
      {
         return cx::Color(255, 125, 0);
      }

      /// @brief Get yellow color.
      /// @return Yellow.
      static constexpr cx::Color yellow()
      {
         return cx::Color(255, 255, 0);
      }

      /// @brief Get green color.
      /// @return Green.
      static constexpr cx::Color green()
      {
         return cx::Color(0, 255, 0);
      }

      /// @brief Get cyan color.
      /// @return Cyan.
      static constexpr cx::Color cyan()
      {
         return cx::Color(0, 255, 255);
      }

      /// @brief Get blue color.
      /// @return Blue.
      static constexpr cx::Color blue()
      {
         return cx::Color(0, 0, 255);
      }

      /// @brief Get purple color.
      /// @return Purple.
      static constexpr cx::Color purple()
      {
         return cx::Color(125, 0, 255);
      }

      /// @brief Get magenta color.
      /// @return Magenta.
      static constexpr cx::Color magenta()
      {
         return cx::Color(255, 0, 255);
      }

      /// @brief Get pink color.
      /// @return Pink.
      static constexpr cx::Color pink()
      {
         return cx::Color(255, 200, 200);
      }

      /// @brief Get white color.
      /// @return White.
      static constexpr cx::Color white()
      {
         return cx::Color(255);
      }

      /// @brief Get gray color.
      /// @return Gray.
      static constexpr cx::Color gray()
      {
         return cx::Color(125);
      }

      /// @brief Get black color.
      /// @return Black.
      static constexpr cx::Color black()
      {
         return cx::Color();
      }

      /// @brief Get transparent color.
      /// @return Transparent.
      static constexpr cx::Color transparent()
      {
         return cx::Color(0, 0);
      }
   };
}

#endif
