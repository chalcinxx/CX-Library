#ifndef CX_VECTOR_VEC4_HPP
#define CX_VECTOR_VEC4_HPP

#include <SFML/Graphics/Rect.hpp>
#include "CX/Vector/Vec2.hpp"

namespace cx
{
   /// @brief 4 value container.
   template<Number T>
   struct Vec4
   {
      T x {}; ///< @brief X value.
      T y {}; ///< @brief Y value.
      T w {}; ///< @brief W value.
      T h {}; ///< @brief H value.

      // Constructors

      /// @brief Create the default vector.
      constexpr Vec4<T>()
         : x(T()), y(T()), w(T()), h(T()) {}

      /// @brief Create a new vector.
      /// @param value X, Y, W and H value.
      template<Number U>
      constexpr Vec4<T>(U value)
         : x(static_cast<T>(value)), y(static_cast<T>(value)), w(static_cast<T>(value)), h(static_cast<T>(value)) {}

      /// @brief Create a new vector.
      /// @param pos X, Y value.
      /// @param size W, H value.
      template<Number U>
      constexpr Vec4<T>(U pos, U size)
         : x(static_cast<T>(pos)), y(static_cast<T>(pos)), w(static_cast<T>(size)), h(static_cast<T>(size)) {} 
      
      /// @brief Create a new vector.
      /// @param x X value.
      /// @param y Y value.
      /// @param w W value.
      /// @param h H value.
      template<Number U>
      constexpr Vec4<T>(U x, U y, U w, U h)
         : x(static_cast<T>(x)), y(static_cast<T>(y)), w(static_cast<T>(w)), h(static_cast<T>(h)) {}
      
      /// @brief Create a new vector.
      /// @param pos X, Y value.
      /// @param size W, H value.
      template<Number U>
      constexpr Vec4<T>(const Vec2<U>& pos, const Vec2<U>& size)
         : x(static_cast<T>(pos.x)), y(static_cast<T>(pos.y)), w(static_cast<T>(size.x)), h(static_cast<T>(size.y)) {}
      
      /// @brief Create a new vector.
      /// @param pos X, Y value.
      /// @param size W, H value.
      template<Number U>
      constexpr Vec4<T>(const sf::Vector2<U>& pos, const sf::Vector2<U>& size)
         : x(static_cast<T>(pos.x)), y(static_cast<T>(pos.y)), w(static_cast<T>(size.x)), h(static_cast<T>(size.y)) {}
      
      /// @brief Copy a vector.
      /// @param rect Vector to copy.
      template<Number U>
      constexpr Vec4<T>(const Vec4<U>& rect)
         : x(static_cast<T>(rect.x)), y(static_cast<T>(rect.y)), w(static_cast<T>(rect.w)), h(static_cast<T>(rect.h)) {}
      
      /// @brief Create a new vector.
      /// @param rect Vector to copy.
      template<Number U>
      constexpr Vec4<T>(const sf::Rect<U>& rect)
         : x(static_cast<T>(rect.left)), y(static_cast<T>(rect.top)), w(static_cast<T>(rect.width)), h(static_cast<T>(rect.height)) {}

      // Constructors after creation

      /// @brief Create a new vector.
      /// @param value X, Y, W and H value.
      template<Number U>
      constexpr void create(T value)
      {
         x = y = w = h = static_cast<T>(value);
      }

      /// @brief Create a new vector.
      /// @param pos X, Y value.
      /// @param size W, H value.
      template<Number U>
      constexpr void create(U pos, U size)
      {
         x = y = static_cast<T>(pos);
         w = h = static_cast<T>(size);
      }
      
      /// @brief Create a new vector.
      /// @param new_x X value.
      /// @param new_y Y value.
      /// @param new_w W value.
      /// @param new_h H value.
      template<Number U>
      constexpr void create(U new_x, U new_y, U new_w, U new_h)
      {
         x = static_cast<T>(new_x);
         y = static_cast<T>(new_y);
         w = static_cast<T>(new_w);
         h = static_cast<T>(new_h);
      }

      /// @brief Create a new vector.
      /// @param pos X, Y value.
      /// @param size W, H value.
      template<Number U>
      constexpr void create(const Vec2<U>& pos, const Vec2<U>& size)
      {
         x = static_cast<T>(pos.x);
         y = static_cast<T>(pos.y);
         w = static_cast<T>(size.x);
         h = static_cast<T>(size.y);  
      }

      /// @brief Create a new vector.
      /// @param pos X, Y value.
      /// @param size W, H value.
      template<Number U>
      constexpr void create(const sf::Vector2<U>& pos, const sf::Vector2<U>& size)
      {
         x = static_cast<T>(pos.x);
         y = static_cast<T>(pos.y);
         w = static_cast<T>(size.x);
         h = static_cast<T>(size.y);  
      }

      /// @brief Copy a vector.
      /// @param rect Vector to copy.
      template<Number U>
      constexpr void create(const Vec4<U>& rect)
      {
         x = static_cast<T>(rect.x);
         y = static_cast<T>(rect.y);
         w = static_cast<T>(rect.w);
         h = static_cast<T>(rect.h);
      }
      
      /// @brief Create a new vector.
      /// @param rect Vector to copy.
      template<Number U>
      constexpr void create(const sf::Rect<U>& rect)
      {
         x = static_cast<T>(rect.left);
         y = static_cast<T>(rect.top);
         w = static_cast<T>(rect.width);
         h = static_cast<T>(rect.height);
      }

      // Random constructors

      /// @brief Create a random vector.
      /// @param min Minimum value.
      /// @param max Maximum value.
      /// @return Random vector.
      template<Number U = T>
      inline static Vec4<T> random(U min = U(0), U max = U(1))
      {
         return Vec4<T>(
            cx::random<T>(min, max), cx::random<T>(min, max),
            cx::random<T>(min, max), cx::random<T>(min, max)
         );
      }

      /// @brief Create a random vector.
      /// @param min Minimum value.
      /// @param max Maximum value.
      /// @return Random vector.
      template<Number U = T>
      inline static Vec4<T> random(const Vec4<U>& min, const Vec4<U>& max = Vec4<U>(1))
      {
         return Vec4<T>(
            cx::random<T>(min.x, max.x), cx::random<T>(min.y, max.y),
            cx::random<T>(min.w, max.w), cx::random<T>(min.h, max.h)
         );
      }

      // Arithmetic functions

      /// @brief Add two vectors together.
      /// @param other Other vector.
      /// @return Sum.
      template<Number U>
      constexpr Vec4<T> operator+(const Vec4<U>& other) const
      {
         return Vec4<T>(
            x + static_cast<T>(other.x), y + static_cast<T>(other.y),
            w + static_cast<T>(other.w), h + static_cast<T>(other.h)
         );
      }

      /// @brief Add two vectors together.
      /// @param other Other vector.
      /// @return Sum.
      template<Number U>
      constexpr Vec4<T> operator+(const sf::Rect<U>& other) const
      {
         return Vec4<T>(
            x + static_cast<T>(other.left), y + static_cast<T>(other.top),
            w + static_cast<T>(other.width), h + static_cast<T>(other.height)
         );
      }

      /// @brief Subtract two vectors apart.
      /// @param other Other vector.
      /// @return Difference.
      template<Number U>
      constexpr Vec4<T> operator-(const Vec4<U>& other) const
      {
         return Vec4<T>(
            x - static_cast<T>(other.x), y - static_cast<T>(other.y),
            w - static_cast<T>(other.w), h - static_cast<T>(other.h)
         );
      }

      /// @brief Subtract two vectors apart.
      /// @param other Other vector.
      /// @return Difference.
      template<Number U>
      constexpr Vec4<T> operator-(const sf::Rect<U>& other) const
      {
         return Vec4<T>(
            x - static_cast<T>(other.left), y - static_cast<T>(other.top),
            w - static_cast<T>(other.width), h - static_cast<T>(other.height)
         );
      }

      /// @brief Multiply vector by a factor.
      /// @param factor Factor.
      /// @return Product.
      template<Number U>
      constexpr Vec4<T> operator*(U factor) const
      {
         return Vec4<T>(
            x * static_cast<T>(factor), y * static_cast<T>(factor),
            w * static_cast<T>(factor), h * static_cast<T>(factor)
         );
      }

      /// @brief Multiply vectors together.
      /// @param other Other vector.
      /// @return Product.
      template<Number U>
      constexpr Vec4<T> operator*(const Vec4<U>& other) const
      {
         return Vec4<T> (
            x * static_cast<T>(other.x), y * static_cast<T>(other.y),
            w * static_cast<T>(other.w), h * static_cast<T>(other.h)
         );
      }

      /// @brief Multiply vectors together.
      /// @param other Other vector.
      /// @return Product.
      template<Number U>
      constexpr Vec4<T> operator*(const sf::Rect<U>& other) const
      {
         return Vec4<T> (
            x * static_cast<T>(other.left), y * static_cast<T>(other.top),
            w * static_cast<T>(other.width), h * static_cast<T>(other.height)
         );
      }

      /// @brief Divide vector by the factor.
      /// @param factor Factor.
      /// @return Quotient.
      template<Number U>
      constexpr Vec4<T> operator/(U factor) const
      {
         if (static_cast<T>(factor) == T(0))
            throw std::runtime_error(errors::vector::division_by_zero);

         return Vec4<T>(
            x / static_cast<T>(factor), y / static_cast<T>(factor),
            w / static_cast<T>(factor), h / static_cast<T>(factor)
         );
      }

      /// @brief Divide vector by the other.
      /// @param other Other vector.
      /// @return Quotient.
      template<Number U>
      constexpr Vec4<T> operator/(const Vec4<U>& other) const
      {
         if (Vec4<T>(other).zero())
            throw std::runtime_error(errors::vector::division_by_zero);
   
         return Vec4<T> (
            x / static_cast<T>(other.x), y / static_cast<T>(other.y),
            w / static_cast<T>(other.w), h / static_cast<T>(other.h)
         );
      }

      /// @brief Divide vector by the other.
      /// @param other Other vector.
      /// @return Quotient.
      template<Number U>
      constexpr Vec4<T> operator/(const sf::Rect<U>& other) const
      {
         if (Vec4<T>(other).zero())
            throw std::runtime_error(errors::vector::division_by_zero);
   
         return Vec4<T> (
            x / static_cast<T>(other.left), y / static_cast<T>(other.top),
            w / static_cast<T>(other.width), h / static_cast<T>(other.height)
         );
      }

      /// @brief Negate vector.
      /// @return Negated vector.
      constexpr Vec4<T> operator-() const
      {
         return Vec4<T>(-x, -y, -w, -h);
      }

      // Compound arithmetic functions

      /// @brief Add vectors together.
      /// @param other Other vector.
      /// @return Sum.
      template<Number U>
      constexpr const Vec4<T>& operator+=(const Vec4<U>& other)
      {
         x += static_cast<T>(other.x);
         y += static_cast<T>(other.y);
         w += static_cast<T>(other.w);
         h += static_cast<T>(other.h);
         return *this;
      }

      /// @brief Add vectors together.
      /// @param other Other vector.
      /// @return Sum.
      template<Number U>
      constexpr const Vec4<T>& operator+=(const sf::Rect<U>& other)
      {
         x += static_cast<T>(other.left);
         y += static_cast<T>(other.top);
         w += static_cast<T>(other.width);
         h += static_cast<T>(other.height);
         return *this;
      }

      /// @brief Subtract vectors apart.
      /// @param other Other vector.
      /// @return Difference.
      template<Number U>
      constexpr const Vec4<T>& operator-=(const Vec4<U>& other)
      {
         x -= static_cast<T>(other.x);
         y -= static_cast<T>(other.y);
         w -= static_cast<T>(other.w);
         h -= static_cast<T>(other.h);
         return *this;
      }

      /// @brief Add vectors together.
      /// @param other Other vector.
      /// @return Sum.
      template<Number U>
      constexpr const Vec4<T>& operator-=(const sf::Rect<U>& other)
      {
         x -= static_cast<T>(other.left);
         y -= static_cast<T>(other.top);
         w -= static_cast<T>(other.width);
         h -= static_cast<T>(other.height);
         return *this;
      }

      /// @brief Multiply vector by the factor.
      /// @param factor Factor.
      /// @return Product.
      template<Number U>
      constexpr const Vec4<T>& operator*=(U factor)
      {
         x *= static_cast<T>(factor);
         y *= static_cast<T>(factor);
         w *= static_cast<T>(factor);
         h *= static_cast<T>(factor);
         return *this;
      }

      /// @brief Multiply vectors together.
      /// @param other Other vector.
      /// @return Product.
      template<Number U>
      constexpr const Vec4<T>& operator*=(const Vec4<U>& other)
      {
         x *= static_cast<T>(other.x);
         y *= static_cast<T>(other.y);
         w *= static_cast<T>(other.w);
         h *= static_cast<T>(other.h);
         return *this;
      }

      /// @brief Multiply vectors together.
      /// @param other Other vector.
      /// @return Product.
      template<Number U>
      constexpr const Vec4<T>& operator*=(const sf::Rect<U>& other)
      {
         x *= static_cast<T>(other.left);
         y *= static_cast<T>(other.top);
         w *= static_cast<T>(other.width);
         h *= static_cast<T>(other.height);
         return *this;
      }

      /// @brief Divide vector by the factor.
      /// @param factor Factor.
      /// @return Quotient.
      template<Number U>
      constexpr const Vec4<T>& operator/=(U factor)
      {
         if (static_cast<T>(factor) == T(0))
            throw std::runtime_error(errors::vector::division_by_zero);

         x /= static_cast<T>(factor);
         y /= static_cast<T>(factor);
         w /= static_cast<T>(factor);
         h /= static_cast<T>(factor);
         return *this;
      }

      /// @brief Divide vectors apart.
      /// @param other Other vector.
      /// @return Quotient.
      template<Number U>
      constexpr const Vec4<T>& operator/=(const Vec4<U>& other)
      {
         if (Vec4<T>(other).zero())
            throw std::runtime_error(errors::vector::division_by_zero);

         x /= static_cast<T>(other.x);
         y /= static_cast<T>(other.y);
         w /= static_cast<T>(other.w);
         h /= static_cast<T>(other.h);
         return *this;
      }

      /// @brief Divide vectors apart.
      /// @param other Other vector.
      /// @return Quotient.
      template<Number U>
      constexpr const Vec4<T>& operator/=(const sf::Rect<U>& other)
      {
         if (Vec4<T>(other).zero())
            throw std::runtime_error(errors::vector::division_by_zero);

         x /= static_cast<T>(other.left);
         y /= static_cast<T>(other.top);
         w /= static_cast<T>(other.width);
         h /= static_cast<T>(other.height);
         return *this;
      }

      // Math functions

      /// @brief Get absolute vector.
      /// @return Absolute vector.
      constexpr Vec4<T> abs() const
      {
         return Vec4<T>(
            (x < T(0) ? -x : x), (y < T(0) ? -y : y),
            (w < T(0) ? -w : w), (h < T(0) ? -h : h)
         );
      }

      /// @brief Clamp values between the given range.
      /// @param min Minimum value.
      /// @param max Maximum value.
      /// @return Clamped vector.
      template<Number U>
      constexpr Vec4<T> clamp(U min, U max) const
      {
         const auto n_min = static_cast<T>(min);
         const auto n_max = static_cast<T>(max);

         return Vec4<T> (
            (x > n_max ? n_max : (x < n_min ? n_min : x)), (y > n_max ? n_max : (y < n_min ? n_min : y)),
            (w > n_max ? n_max : (w < n_min ? n_min : w)), (h > n_max ? n_max : (h < n_min ? n_min : h))
         );
      }

      /// @brief Set values above minimum value.
      /// @param min Minimum value.
      /// @return Vector with values above minimum value.
      template<Number U>
      constexpr Vec4<T> min(U min) const
      {
         const auto n_min = static_cast<T>(min);
         return Vec4<T>((x < n_min ? n_min : x), (y < n_min ? n_min : y), (w < n_min ? n_min : w), (h < n_min ? n_min : h));
      }

      /// @brief Set values below maximum value.
      /// @param max Maximum value.
      /// @return Vector with values below maximum value.
      template<Number U>
      constexpr Vec4<T> max(U max) const
      {
         const auto n_max = static_cast<T>(max);
         return Vec4<T>((x > n_max ? n_max : x), (y > n_max ? n_max : y), (w > n_max ? n_max : w), (h > n_max ? n_max : h));
      }

      /// @brief Get dot product.
      /// @param other Other vector.
      /// @return Dot product.
      template<Number U>
      constexpr T dot(const Vec4<U>& other) const
      {
         return x * static_cast<T>(other.x) + y * static_cast<T>(other.y)
            + w * static_cast<T>(other.w) + h * static_cast<T>(other.h);
      }

      /// @brief Get dot product.
      /// @param other Other vector.
      /// @return Dot product.
      template<Number U>
      constexpr T dot(const sf::Rect<U>& other) const
      {
         return x * static_cast<T>(other.left) + y * static_cast<T>(other.top)
            + w * static_cast<T>(other.width) + h * static_cast<T>(other.height);
      }

      /// @brief Get magnitude.
      /// @return Magnitude.
      constexpr T magnitude() const
      {
         return sqrt(x * x + y * y + w * w + h * h);
      }

      /// @brief Get magnitude squared.
      /// @return Magnitude squared.
      constexpr T magnitude_squared() const
      {
         return x * x + y * y + w * w + h * h;
      }

      /// @brief Get distance between two vectors.
      /// @param other Other vector.
      /// @return Distance.
      template<Number U>
      constexpr float distance(const Vec4<U>& other) const
      {
         const auto nx = x - static_cast<T>(other.x);
         const auto ny = y - static_cast<T>(other.y);
         return std::sqrt(nx * nx + ny * ny);
      }

      /// @brief Get distance between two vectors.
      /// @param other Other vector.
      /// @return Distance.
      template<Number U>
      constexpr float distance(const sf::Rect<U>& other) const
      {
         const auto nx = x - static_cast<T>(other.left);
         const auto ny = y - static_cast<T>(other.top);
         return std::sqrt(nx * nx + ny * ny);
      }

      /// @brief Get distance squared between two vectors.
      /// @param other Other vector.
      /// @return Distance squared.
      template<Number U>
      constexpr float distance_squared(const Vec4<U>& other) const
      {
         const auto nx = x - static_cast<T>(other.x);
         const auto ny = y - static_cast<T>(other.y);
         return nx * nx + ny * ny;
      }

      /// @brief Get distance squared between two vectors.
      /// @param other Other vector.
      /// @return Distance squared.
      template<Number U>
      constexpr float distance_squared(const sf::Rect<U>& other) const
      {
         const auto nx = x - static_cast<T>(other.left);
         const auto ny = y - static_cast<T>(other.top);
         return nx * nx + ny * ny;
      }

      /// @brief Normalize vector.
      /// @return Normalized vector.
      constexpr Vec4<T> normalize() const
      {
         const T mag = magnitude();
         return (mag == T(0) ? Vec4<T>() : *this / mag);
      }

      /// @brief Check for collision against a point.
      /// @param point Point to check collision against.
      /// @return True if colliding.
      template<Number U>
      constexpr bool contains(const Vec2<U>& point) const
      {
         return !(static_cast<T>(point.x) < x || static_cast<T>(point.x) > x + w
               || static_cast<T>(point.y) < y || static_cast<T>(point.y) > y + h);
      }

      /// @brief Check for collision against a point.
      /// @param point Point to check collision against.
      /// @return True if colliding.
      template<Number U>
      constexpr bool contains(const sf::Vector2<U>& point) const
      {
         return !(static_cast<T>(point.x) <= x || static_cast<T>(point.x) >= x + w
               || static_cast<T>(point.y) <= y || static_cast<T>(point.y) >= y + h);
      }

      /// @brief Check for collision against rectangle.
      /// @param rect Rectangle to check collision against.
      /// @return True if colliding.
      template<Number U>
      constexpr bool colliding(const Vec4<U>& rect) const
      {
         return !(x >= static_cast<T>(rect.x + rect.w) || x + w <= static_cast<T>(rect.x)
               || y >= static_cast<T>(rect.y + rect.h) || y + h <= static_cast<T>(rect.y));
      }
      
      /// @brief Check for collision against rectangle.
      /// @param rect Rectangle to check collision against.
      /// @return True if colliding.
      template<Number U>
      constexpr bool colliding(const sf::Rect<U>& rect) const
      {
         return !(x >= static_cast<T>(rect.left + rect.width) || x + w <= static_cast<T>(rect.left)
               || y >= static_cast<T>(rect.top + rect.height) || y + h <= static_cast<T>(rect.top));
      }

      /// @brief Linearly interpolate between two vectors.
      /// @param b Ending value.
      /// @param t Interpolation factor.
      /// @return Middle point between this and b based on factor t.
      template<Number U>
      constexpr Vec4<T> lerp(const Vec4<U>& b, float t) const
      {
         return *this + (b - *this) * t;
      }

      /// @brief Linearly interpolate between two vectors.
      /// @param b Ending value.
      /// @param t Interpolation factor.
      /// @return Middle point between this and b based on factor t.
      template<Number U>
      constexpr Vec4<T> lerp(const sf::Rect<U>& b, float t) const
      {
         return *this + (Vec4<T>(b) - *this) * t;
      }

      /// @brief Get center position of the vector.
      /// @return Center position.
      constexpr Vec2<T> get_center() const
      {
         return Vec2<T>(x + w / T(2), y + h / T(2));
      }

      /// @brief Get top-left position of the vector.
      /// @return Position.
      constexpr Vec2<T> get_top_left() const
      {
         return Vec2<T>(x, y);
      }

      /// @brief Get bottom-right position of the vector.
      /// @return Position.
      constexpr Vec2<T> get_bottom_right() const
      {
         return Vec2<T>(x + w, y + h);
      }

      /// @brief Get size of the vector.
      /// @return Size.
      constexpr Vec2<T> get_size() const
      {
         return Vec2<T>(w, h);
      }

      /// @brief Get left position.
      /// @return Left position.
      constexpr T get_left() const
      {
         return x;
      }

      /// @brief Get top position.
      /// @return Top position.
      constexpr T get_top() const
      {
         return y;
      }

      /// @brief Get right position.
      /// @return Right position.
      constexpr T get_right() const
      {
         return x + w;
      }

      /// @brief Get bottom position.
      /// @return Bottom position.
      constexpr T get_bottom() const
      {
         return y + h;
      }

      /// @brief Get center X position.
      /// @return Center X.
      constexpr T get_center_x() const
      {
         return x + w / T(2);
      }

      /// @brief Get center Y position.
      /// @return Center Y.
      constexpr T get_center_y() const
      {
         return y + h / T(2);
      }

      /// @brief Get width.
      /// @return Width.
      constexpr T get_width() const
      {
         return w;
      }

      /// @brief Get height.
      /// @return Height.
      constexpr T get_height() const
      {
         return h;
      }

      // Condition functions

      /// @brief Check if vector is positive.
      /// @return True if all values are positive.
      constexpr bool positive() const
      {
         return x >= T(0) && y >= T(0) && w >= T(0) && h >= T(0);
      }

      /// @brief Check if vector is negative.
      /// @return True if all values are negative.
      constexpr bool negative() const
      {
         return x <= T(0) && y <= T(0) && w <= T(0) && h <= T(0);
      }

      /// @brief Check if vector is empty.
      /// @return True if all values are zero.
      constexpr bool empty() const
      {
         return x == T(0) && y == T(0) && w == T(0) && h == T(0);
      }

      /// @brief Check if any value is zero.
      /// @return True if atleast one value is zero.
      constexpr bool zero() const
      {
         return x == T(0) || y == T(0) || w == T(0) || h == T(0);
      }

      /// @brief Compare two vectors.
      /// @param other Other vector.
      /// @return True if both are different.
      template<Number U>
      constexpr bool operator!=(const Vec4<U>& other) const
      {
         return x != static_cast<T>(other.x) || y != static_cast<T>(other.y)
            || w != static_cast<T>(other.w) || h != static_cast<T>(other.h);
      }

      /// @brief Compare two vectors.
      /// @param other Other vector.
      /// @return True if both are different.
      template<Number U>
      constexpr bool operator!=(const sf::Rect<U>& other) const
      {
         return x != static_cast<T>(other.left) || y != static_cast<T>(other.top)
            || w != static_cast<T>(other.width) || h != static_cast<T>(other.height);
      }

      /// @brief Compare two vectors.
      /// @param other Other vector.
      /// @return True if both are equal.
      template<Number U>
      constexpr bool operator==(const Vec4<U>& other) const
      {
         return !(*this != other);
      }

      /// @brief Compare two vectors.
      /// @param other Other vector.
      /// @return True if both are equal.
      template<Number U>
      constexpr bool operator==(const sf::Rect<U>& other) const
      {
         return !(*this != other);
      }

      // Other functions

      /// @brief Copy a vector.
      /// @param other Other vector.
      /// @return Vector.
      template<Number U>
      constexpr const Vec4<T>& operator=(const Vec4<U>& other)
      {
         x = static_cast<T>(other.x);
         y = static_cast<T>(other.y);
         w = static_cast<T>(other.w);
         h = static_cast<T>(other.h);
         return *this;
      }

      /// @brief Copy a vector.
      /// @param other Other vector.
      /// @return Vector.
      template<Number U>
      constexpr const Vec4<T>& operator=(const sf::Rect<U>& other)
      {
         x = static_cast<T>(other.left);
         y = static_cast<T>(other.top);
         w = static_cast<T>(other.width);
         h = static_cast<T>(other.height);
         return *this;
      }

      /// @brief Return value by index.
      /// @param index Index of the value.
      /// @return Value.
      constexpr T& operator[](size_t index)
      {
         if (index > 3)
            throw std::runtime_error(errors::vector::out_of_bounds);
         return (index == 0 ? x : (index == 1 ? y : (index == 2 ? w : h)));
      }

      /// @brief Return value by index.
      /// @param index Index of the value.
      /// @return Value.
      constexpr T operator[](size_t index) const
      {
         if (index > 3)
            throw std::runtime_error(errors::vector::out_of_bounds);
         return (index == 0 ? x : (index == 1 ? y : (index == 2 ? w : h)));
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
         x = y = w = h = T(0);
      }

      /// @brief Get vector size.
      /// @return Size.
      constexpr size_t size() const
      {
         return 4;
      }

      /// @brief Convert vector.
      template<Number U>
      inline operator sf::Rect<U>() const
      {
         return sf::Rect<T>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(w), static_cast<U>(h));
      }

      /// @brief Convert vector.
      template<Number U>
      constexpr operator Vec4<U>() const
      {
         return Vec4<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(w), static_cast<U>(h));
      }

      /// @brief Convert vector.
      template<Number U = T>
      inline sf::Rect<U> sfml() const
      {
         return sf::Rect<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(w), static_cast<U>(h));
      }
   };

   using Vec4f = Vec4<float>;    ///< @brief 4 value container.
   using Vec4i = Vec4<int32_t>;  ///< @brief 4 value container.
   using Vec4u = Vec4<uint32_t>; ///< @brief 4 value container.
}

#endif
