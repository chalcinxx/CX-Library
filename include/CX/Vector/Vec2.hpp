#ifndef CX_VECTOR_VEC2_HPP
#define CX_VECTOR_VEC2_HPP

#include <SFML/System/Vector2.hpp>
#include "CX/Errors.hpp"
#include "CX/Math/Angle.hpp"
#include "CX/Math/Random.hpp"

namespace cx
{
   /// @brief 2 value container.
   template<Number T>
   struct Vec2
   {
      T x {}; ///< @brief X value.
      T y {}; ///< @brief Y value.

      // Constructors

      /// @brief Create an empty vector.
      constexpr Vec2<T>()
         : x(T()), y(T()) {}

      /// @brief Create a new vector.
      /// @param value X and Y value.
      template<Number U>
      constexpr Vec2<T>(U value)
         : x(static_cast<T>(value)), y(static_cast<T>(value)) {}

      /// @brief Create a new vector.
      /// @param x X value.
      /// @param y Y value.
      template<Number U>
      constexpr Vec2<T>(U x, U y)
         : x(static_cast<T>(x)), y(static_cast<T>(y)) {}
      
      /// @brief Copy a vector.
      /// @param vector Vector to copy.
      template<Number U>
      constexpr Vec2<T>(const Vec2<U>& vector)
         : x(static_cast<T>(vector.x)), y(static_cast<T>(vector.y)) {}

      /// @brief Copy a vector.
      /// @param vector Vector to copy.
      template<Number U>
      constexpr Vec2<T>(const sf::Vector2<U>& vector)
         : x(static_cast<T>(vector.x)), y(static_cast<T>(vector.y)) {}
      
      // Constructors after creation

      /// @brief Create a new vector.
      /// @param value X and Y value.
      template<Number U>
      constexpr void create(U value)
      {
         x = y = static_cast<T>(value);
      }

      /// @brief Create a new vector.
      /// @param newX X value.
      /// @param newY Y value.
      template<Number U>
      constexpr void create(U new_x, U new_y)
      {
         x = static_cast<T>(new_x);
         y = static_cast<T>(new_y);
      }

      /// @brief Copy a vector.
      /// @param vector Vector to copy.
      template<Number U>
      constexpr void create(const Vec2<U>& vector)
      {
         x = static_cast<T>(vector.x);
         y = static_cast<T>(vector.y);
      }

      /// @brief Copy a vector.
      /// @param vector Vector to copy.
      template<Number U>
      constexpr void create(const sf::Vector2<U>& vector)
      {
         x = static_cast<T>(vector.x);
         y = static_cast<T>(vector.y);
      }

      // Random constructors

      /// @brief Create a random vector.
      /// @param min Minimum value.
      /// @param max Maximum value.
      /// @return Random vector.
      template<Number U = T>
      inline static Vec2<T> random(U min = U(0), U max = U(1))
      {
         return Vec2<T>(cx::random<T>(min, max), cx::random<T>(min, max));
      }

      /// @brief Create a random vector.
      /// @param min Minimum values.
      /// @param max Maximum values.
      /// @return Random vector.
      template<Number U = T>
      inline static Vec2<T> random(const Vec2<U>& min, const Vec2<U>& max = Vec2<U>(1))
      {
         return Vec2<T>(cx::random<T>(min.x, max.x), cx::random<T>(min.y, max.y));
      }

      // Arithmetic functions

      /// @brief Add two vectors together.
      /// @param other Other vector.
      /// @return Sum.
      template<Number U>
      constexpr Vec2<T> operator+(const Vec2<U>& other) const
      {
         return Vec2<T>(x + static_cast<T>(other.x), y + static_cast<T>(other.y));
      }

      /// @brief Add two vectors together.
      /// @param other Other vector.
      /// @return Sum.
      template<Number U>
      constexpr Vec2<T> operator+(const sf::Vector2<U>& other) const
      {
         return Vec2<T>(x + static_cast<T>(other.x), y + static_cast<T>(other.y));
      }

      /// @brief Subtract two vectors apart.
      /// @param other Other vector.
      /// @return Difference.
      template<Number U>
      constexpr Vec2<T> operator-(const Vec2<U>& other) const
      {
         return Vec2<T>(x - static_cast<T>(other.x), y - static_cast<T>(other.y));
      }

      /// @brief Subtract two vectors apart.
      /// @param other Other vector.
      /// @return Difference.
      template<Number U>
      constexpr Vec2<T> operator-(const sf::Vector2<U>& other) const
      {
         return Vec2<T>(x - static_cast<T>(other.x), y - static_cast<T>(other.y));
      }

      /// @brief Multiply vector by the factor.
      /// @param factor Factor.
      /// @return Product.
      template<Number U>
      constexpr Vec2<T> operator*(U factor) const
      {
         return Vec2<T>(x * static_cast<T>(factor), y * static_cast<T>(factor));
      }

      /// @brief Multiply vectors together.
      /// @param other Other vector.
      /// @return Product.
      template<Number U>
      constexpr Vec2<T> operator*(const Vec2<U>& other) const
      {
         return Vec2<T>(x * static_cast<T>(other.x), y * static_cast<T>(other.y));
      }

      /// @brief Multiply vectors together.
      /// @param other Other vector.
      /// @return Product.
      template<Number U>
      constexpr Vec2<T> operator*(const sf::Vector2<U>& other) const
      {
         return Vec2<T>( x * static_cast<T>(other.x), y * static_cast<T>(other.y));
      }

      /// @brief Divide vector by the factor.
      /// @param factor Factor.
      /// @return Quotient.
      template<Number U>
      constexpr Vec2<T> operator/(U factor) const
      {
         if (static_cast<T>(factor) == T(0))
            throw std::runtime_error(errors::vector::division_by_zero2);
         return Vec2<T>(x / static_cast<T>(factor), y / static_cast<T>(factor));
      }

      /// @brief Divide vector by the other.
      /// @param other Other vector.
      /// @return Quotient.
      template<Number U>
      constexpr Vec2<T> operator/(const Vec2<U>& other) const
      {
         if (Vec2<T>(other).zero())
            throw std::runtime_error(errors::vector::division_by_zero2);
         return Vec2<T>(x / static_cast<T>(other.x), y / static_cast<T>(other.y));
      }

      /// @brief Divide vector by the other.
      /// @param other Other vector.
      /// @return Quotient.
      template<Number U>
      constexpr Vec2<T> operator/(const sf::Vector2<U>& other) const
      {
         if (Vec2<T>(other).zero())
            throw std::runtime_error(errors::vector::division_by_zero2);
         return Vec2<T>(x / static_cast<T>(other.x), y / static_cast<T>(other.y));
      }

      /// @brief Negate vector.
      /// @return Negated vector.
      constexpr Vec2<T> operator-() const
      {
         return Vec2<T>(-x, -y);
      }

      // Compound arithmetic functions

      /// @brief Add vectors together.
      /// @param other Other vector.
      /// @return Sum.
      template<Number U>
      constexpr const Vec2<T>& operator+=(const Vec2<U>& other)
      {
         x += static_cast<T>(other.x);
         y += static_cast<T>(other.y);
         return *this;
      }

      /// @brief Add vectors together.
      /// @param other Other vector.
      /// @return Sum.
      template<Number U>
      constexpr const Vec2<T>& operator+=(const sf::Vector2<U>& other)
      {
         x += static_cast<T>(other.x);
         y += static_cast<T>(other.y);
         return *this;
      }

      /// @brief Subtract vectors apart.
      /// @param other Other vector.
      /// @return Difference.
      template<Number U>
      constexpr const Vec2<T>& operator-=(const Vec2<U>& other)
      {
         x -= static_cast<T>(other.x);
         y -= static_cast<T>(other.y);
         return *this;
      }

      /// @brief Subtract vectors apart.
      /// @param other Other vector.
      /// @return Difference.
      template<Number U>
      constexpr const Vec2<T>& operator-=(const sf::Vector2<U>& other)
      {
         x -= static_cast<T>(other.x);
         y -= static_cast<T>(other.y);
         return *this;
      }

      /// @brief Multiply vector by the factor.
      /// @param factor Factor.
      /// @return Product.
      template<Number U>
      constexpr const Vec2<T>& operator*=(U factor)
      {
         x *= static_cast<T>(factor);
         y *= static_cast<T>(factor);
         return *this;
      }

      /// @brief Multiply vectors together.
      /// @param other Other vector.
      /// @return Product.
      template<Number U>
      constexpr const Vec2<T>& operator*=(const Vec2<U>& other)
      {
         x *= static_cast<T>(other.x);
         y *= static_cast<T>(other.y);
         return *this;
      }

      /// @brief Multiply vectors together.
      /// @param other Other vector.
      /// @return Product.
      template<Number U>
      constexpr const Vec2<T>& operator*=(const sf::Vector2<U>& other)
      {
         x *= static_cast<T>(other.x);
         y *= static_cast<T>(other.y);
         return *this;
      }

      /// @brief Divide vector by the factor.
      /// @param factor Factor.
      /// @return Quotient.
      template<Number U>
      constexpr const Vec2<T>& operator/=(U factor)
      {
         if (static_cast<T>(factor) == T(0))
            throw std::runtime_error(errors::vector::division_by_zero2);
         x /= static_cast<T>(factor);
         y /= static_cast<T>(factor);
         return *this;
      }

      /// @brief Divide vectors apart.
      /// @param other Other vector.
      /// @return Quotient.
      template<Number U>
      constexpr const Vec2<T>& operator/=(const Vec2<U>& other)
      {
         if (Vec2<T>(other).zero())
            throw std::runtime_error(errors::vector::division_by_zero2);
         x /= static_cast<T>(other.x);
         y /= static_cast<T>(other.y);
         return *this;
      }

      /// @brief Divide vectors apart.
      /// @param other Other vector.
      /// @return Quotient.
      template<Number U>
      constexpr const Vec2<T>& operator/=(const sf::Vector2<U>& other)
      {
         if (Vec2<T>(other).zero())
            throw std::runtime_error(errors::vector::division_by_zero2);
         x /= static_cast<T>(other.x);
         y /= static_cast<T>(other.y);
         return *this;
      }

      // Math functions

      /// @brief Get absolute vector.
      /// @return Absolute vector.
      constexpr Vec2<T> abs() const
      {
         return Vec2<T>((x < T(0) ? -x : x), (y < T(0) ? -y : y));
      }

      /// @brief Clamp values between the given range.
      /// @param min Minimum value.
      /// @param max Maximum value.
      /// @return Clamped vector.
      template<Number U>
      constexpr Vec2<T> clamp(U min, U max) const
      {
         const auto n_min = static_cast<T>(min);
         const auto n_max = static_cast<T>(max);

         return Vec2<T>(
            (x > n_max ? n_max : (x < n_min ? n_min : x)),
            (y > n_max ? n_max : (y < n_min ? n_min : y))
         );
      }

      /// @brief Set values above minimum value.
      /// @param min Minimum value.
      /// @return Vector with values above minimum value.
      template<Number U>
      constexpr Vec2<T> min(U min) const
      {
         const auto n_min = static_cast<T>(min);
         return Vec2<T>((x < n_min ? n_min : x), (y < n_min ? n_min : y));
      }

      /// @brief Set values below maximum value.
      /// @param max Maximum value.
      /// @return Vector with values below maximum value.
      template<Number U>
      constexpr Vec2<T> max(U max) const
      {
         const auto n_max = static_cast<T>(max);
         return Vec2<T>((x > n_max ? n_max : x), (y > n_max ? n_max : y));
      }

      /// @brief Get dot product.
      /// @param other Other vector.
      /// @return Dot product.
      template<Number U>
      constexpr float dot(const Vec2<U>& other) const
      {
         return x * static_cast<T>(other.x) + y * static_cast<T>(other.y);
      }

      /// @brief Get dot product.
      /// @param other Other vector.
      /// @return Dot product.
      template<Number U>
      constexpr float dot(const sf::Vector2<U>& other) const
      {
         return x * static_cast<T>(other.x) + y * static_cast<T>(other.y);
      }

      /// @brief Get cross product.
      /// @param other Other vector.
      /// @return Cross product.
      template<Number U>
      constexpr float cross(const Vec2<U>& other) const
      {
         return x * static_cast<T>(other.y) - y * static_cast<T>(other.x);
      }

      /// @brief Get cross product.
      /// @param other Other vector.
      /// @return Cross product.
      template<Number U>
      constexpr float cross(const sf::Vector2<U>& other) const
      {
         return x * static_cast<T>(other.y) - y * static_cast<T>(other.x);
      }

      /// @brief Get magnitude.
      /// @return Magnitude.
      constexpr float magnitude() const
      {
         return std::sqrt(x * x + y * y);
      }

      /// @brief Get magnitude squared.
      /// @return Magnitude squared.
      constexpr float magnitude_squared() const
      {
         return x * x + y * y;
      }

      /// @brief Get angle between two vectors.
      /// @param other Other vector.
      /// @return Angle in radians.
      template<Number U>
      constexpr Radians angle(const Vec2<U>& other) const
      {
         return cx::Radians(-std::atan2(static_cast<T>(other.x) - x, static_cast<T>(other.y) - y) + M_PIf);
      }

      /// @brief Get angle between two vectors.
      /// @param other Other vector.
      /// @return Angle in radians.
      template<Number U>
      constexpr Radians angle(const sf::Vector2<U>& other) const
      {
         return cx::Radians(-std::atan2(static_cast<T>(other.x) - x, static_cast<T>(other.y) - y) + M_PIf);
      }

      /// @brief Get distance between two vectors.
      /// @param other Other vector.
      /// @return Distance.
      template<Number U>
      constexpr float distance(const Vec2<U>& other) const
      {
         const auto nx = x - static_cast<T>(other.x);
         const auto ny = y - static_cast<T>(other.y);
         return std::sqrt(nx * nx + ny * ny);
      }

      /// @brief Get distance between two vectors.
      /// @param other Other vector.
      /// @return Distance.
      template<Number U>
      constexpr float distance(const sf::Vector2<U>& other) const
      {
         const auto nx = x - static_cast<T>(other.x);
         const auto ny = y - static_cast<T>(other.y);
         return std::sqrt(nx * nx, ny * ny);
      }

      /// @brief Get distance squared between two vectors.
      /// @param other Other vector.
      /// @return Distance squared.
      template<Number U>
      constexpr float distance_squared(const Vec2<U>& other) const
      {
         const auto nx = x - static_cast<T>(other.x);
         const auto ny = y - static_cast<T>(other.y);
         return nx * nx, ny * ny;
      }

      /// @brief Get distance squared between two vectors.
      /// @param other Other vector.
      /// @return Distance squared.
      template<Number U>
      constexpr float distance_squared(const sf::Vector2<U>& other) const
      {
         const auto nx = x - static_cast<T>(other.x);
         const auto ny = y - static_cast<T>(other.y);
         return nx * nx, ny * ny;
      }

      /// @brief Project vector onto the other.
      /// @param other Other vector.
      /// @return Projected vector.
      template<Number U>
      constexpr Vec2<T> project(const Vec2<U>& other) const
      {
         return Vec2<T>(other * (dot(other) / other.magnitude_squared()));
      }

      /// @brief Project vector onto the other.
      /// @param other Other vector.
      /// @return Projected vector.
      template<Number U>
      constexpr Vec2<T> project(const sf::Vector2<U>& other) const
      {
         return Vec2<T>(other * (dot(other) / Vec2<U>(other).magnitude_squared()));
      }

      /// @brief Project vector onto the line.
      /// @param origin Origin of the line.
      /// @param direction Direction of the line.
      /// @return Projected vector.
      template<Number U>
      constexpr T project(const Vec2<U>& origin, const Vec2<U>& direction) const
      {
         return (x - static_cast<T>(origin.x)) * static_cast<T>(direction.x)
              + (y - static_cast<T>(origin.y)) * static_cast<T>(direction.y);
      }

      /// @brief Project vector onto the line.
      /// @param origin Origin of the line.
      /// @param direction Direction of the line.
      /// @return Projected vector.
      template<Number U>
      constexpr T project(const sf::Vector2<U>& origin, const sf::Vector2<U>& direction) const
      {
         return (x - static_cast<T>(origin.x)) * static_cast<T>(direction.x)
              + (y - static_cast<T>(origin.y)) * static_cast<T>(direction.y);
      }

      /// @brief Reflect vector over the normal.
      /// @param normal Normal.
      /// @return Reflected vector.
      template<Number U>
      constexpr Vec2<T> reflect(const Vec2<U>& normal) const
      {
         return *this - normal * (2 * dot(normal));
      }

      /// @brief Reflect vector over the normal.
      /// @param normal Normal.
      /// @return Reflected vector.
      template<Number U>
      constexpr Vec2<T> reflect(const sf::Vector2<U>& normal) const
      {
         return *this - normal * (2 * dot(normal));
      }

      /// @brief Normalize vector.
      /// @return Normalized vector.
      constexpr Vec2<T> normalize() const
      {
         const T mag = magnitude();
         return (mag == T(0) ? Vec2<T>() : *this / mag);
      }

      /// @brief Get vector normal.
      /// @return Normal.
      constexpr Vec2<T> normal() const
      {
         return Vec2<T>(-y, x).normalize();
      }

      /// @brief Rotate vector.
      /// @param radians Angle in radians.
      /// @return Rotated vector.
      template<Floating U>
      constexpr Vec2<T> rotate(U radians) const
      {
         if (radians == U(0))
            return *this;

         const auto sin = std::sin(radians);
         const auto cos = std::cos(radians);

         return Vec2<T>(x * cos - y * sin, x * sin + y * cos);
      }

      /// @brief Rotate vector.
      /// @param angle Angle.
      /// @return Rotated vector.
      constexpr Vec2<T> rotate(const Angle& angle) const
      {
         const auto radians = angle.radians();
         if (radians == 0.f)
            return *this;

         const auto sin = std::sin(radians);
         const auto cos = std::cos(radians);

         return Vec2<T>(x * cos - y * sin, x * sin + y * cos);
      }

      /// @brief Get direction to other vector.
      /// @param other Other vector.
      /// @return Normalized direction.
      template<Number U>
      constexpr Vec2<T> direction_to(const Vec2<U>& other) const
      {
         return Vec2<T>(other - *this).normalize();
      }

      /// @brief Get direction to other vector.
      /// @param other Other vector.
      /// @return Normalized direction.
      template<Number U>
      constexpr Vec2<T> direction_to(const sf::Vector2<U>& other) const
      {
         return Vec2<T>(Vec2<U>(other) - *this).normalize();
      }

      /// @brief Linearly interpolate between two vectors.
      /// @param b Ending value.
      /// @param t Interpolation factor.
      /// @return Middle point between this and b based on factor t.
      template<Number U, Floating Y = float>
      constexpr Vec2<T> lerp(const Vec2<U>& b, Y t) const
      {
         return *this + (b - *this) * t;
      }

      /// @brief Linearly interpolate between two vectors.
      /// @param b Ending value.
      /// @param t Interpolation factor.
      /// @return Middle point between this and b based on factor t.
      template<Number U, Floating Y = float>
      constexpr Vec2<T> lerp(const sf::Vector2<U>& b, Y t) const
      {
         return *this + (Vec2<U>(b) - *this) * t;
      }

      // Condition functions

      /// @brief Check if vector is positive.
      /// @return True if all values are positive.
      constexpr bool positive() const
      {
         return x >= T(0) && y >= T(0);
      }

      /// @brief Check if vector is negative.
      /// @return True if all values are negative.
      constexpr bool negative() const
      {
         return x <= T(0) && y <= T(0);
      }

      /// @brief Check if vector is empty.
      /// @return True if all values are zero.
      constexpr bool empty() const
      {
         return x == T(0) && y == T(0);
      }

      /// @brief Check if any vector value is zero.
      /// @return True if atleast one is zero.
      constexpr bool zero() const
      {
         return x == T(0) || y == T(0);
      }

      /// @brief Compare two vectors.
      /// @param other Other vector.
      /// @return True if both are different.
      template<Number U>
      constexpr bool operator!=(const Vec2<U>& other) const
      {
         return x != static_cast<T>(other.x) || y != static_cast<T>(other.y);
      }

      /// @brief Compare two vectors.
      /// @param other Other vector.
      /// @return True if both are different.
      template<Number U>
      constexpr bool operator!=(const sf::Vector2<U>& other) const
      {
         return x != static_cast<T>(other.x) || y != static_cast<T>(other.y);
      }

      /// @brief Compare two vectors.
      /// @param other Other vector.
      /// @return True if both are equal.
      template<Number U>
      constexpr bool operator==(const Vec2<U>& other) const
      {
         return !(*this != other);
      }

      /// @brief Compare two vectors.
      /// @param other Other vector.
      /// @return True if both are equal.
      template<Number U>
      constexpr bool operator==(const sf::Vector2<U>& other) const
      {
         return !(*this != other);
      }

      // Other functions

      /// @brief Copy a vector.
      /// @param other Other vector.
      /// @return Vector.
      template<Number U>
      constexpr const Vec2<T>& operator=(const Vec2<U>& other)
      {
         x = static_cast<T>(other.x);
         y = static_cast<T>(other.y);
         return *this;
      }

      /// @brief Copy a vector.
      /// @param other Other vector.
      /// @return Vector.
      template<Number U>
      constexpr const Vec2<T>& operator=(const sf::Vector2<U>& other)
      {
         x = static_cast<T>(other.x);
         y = static_cast<T>(other.y);
         return *this;
      }

      /// @brief Return value by index.
      /// @param index Index of the value.
      /// @return Value.
      constexpr T& operator[](size_t index)
      {
         if (index > 1)
            throw std::runtime_error(errors::vector::out_of_bounds2);
         return (index == 1 ? y : x);
      }

      /// @brief Return value by index.
      /// @param index Index of the value.
      /// @return Value.
      constexpr T operator[](size_t index) const
      {
         if (index > 1)
            throw std::runtime_error(errors::vector::out_of_bounds2);
         return (index == 1 ? y : x);
      }

      /// @brief Return value by index.
      /// @param index Index of the value.
      /// @return Value.
      constexpr T& at(size_t index)
      {
         return (*this)[index];
      }

      /// @brief Return value by index.
      /// @param index Index of the value.
      /// @return Value.
      constexpr T at(size_t index) const
      {
         return (*this)[index];
      }

      /// @brief Clear vector.
      constexpr void clear()
      {
         x = y = T(0);
      }

      /// @brief Get vector size.
      /// @return Size.
      constexpr size_t size() const
      {
         return 2;
      }

      /// @brief Convert vector.
      template<Number U>
      inline operator sf::Vector2<U>() const
      {
         return sf::Vector2<U>(static_cast<U>(x), static_cast<U>(y));
      }

      /// @brief Convert vector.
      template<Number U>
      constexpr operator Vec2<U>() const
      {
         return Vec2<U>(static_cast<U>(x), static_cast<U>(y));
      }
   };

   using Vec2f = Vec2<float>;    ///< @brief 2 value container.
   using Vec2i = Vec2<int32_t>;  ///< @brief 2 value container.
   using Vec2u = Vec2<uint32_t>; ///< @brief 2 value container.
}

#endif
