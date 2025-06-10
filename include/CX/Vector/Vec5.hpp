#ifndef CX_VECTOR_VEC5_HPP
#define CX_VECTOR_VEC5_HPP

#include "CX/Vector/Vec4.hpp"

namespace cx
{
   /// @brief 5 value container.
   template<Number T>
   struct Vec5
   {
      T x {}; ///< @brief X value. Index 0.
      T y {}; ///< @brief Y value. Index 1.
      T w {}; ///< @brief W value. Index 2.
      T h {}; ///< @brief H value. Index 3.
      T r {}; ///< @brief R value. Index 4.

      // Constructors

      /// @brief Create a default vector.
      constexpr Vec5<T>()
         : x(T()), y(T()), w(T()), h(T()), r(T()) {}
      
      /// @brief Create a new vector.
      /// @param value X, Y, W, H and R value.
      template<Number U>
      constexpr Vec5<T>(U value)
         : x(static_cast<T>(value)), y(static_cast<T>(value)),
         w(static_cast<T>(value)), h(static_cast<T>(value)),
         r(static_cast<T>(value)) {}
      
      /// @brief Create a new vector.
      /// @param pos X, Y value.
      /// @param size W, H value.
      /// @param rotation R value.
      template<Number U>
      constexpr Vec5<T>(U pos, U size, U rotation = U())
         : x(static_cast<T>(pos)), y(static_cast<T>(pos)),
         w(static_cast<T>(size)), h(static_cast<T>(size)),
         r(static_cast<T>(rotation)) {}
      
      /// @brief Create a new vector.
      /// @param x X value.
      /// @param y Y value.
      /// @param w W value.
      /// @param h H value.
      /// @param r R value.
      template<Number U>
      constexpr Vec5<T>(U x, U y, U w, U h, U r = U())
         : x(static_cast<T>(x)), y(static_cast<T>(y)), w(static_cast<T>(w)),
         h(static_cast<T>(h)), r(static_cast<T>(r)) {}
      
      /// @brief Create a new vector.
      /// @param pos X, Y value.
      /// @param size W, H value.
      /// @param rotation R value.
      template<Number U>
      constexpr Vec5<T>(const Vec2<U>& pos,
                        const Vec2<U>& size,
                        U rotation = U())
         : x(static_cast<T>(pos.x)), y(static_cast<T>(pos.y)),
         w(static_cast<T>(size.x)), h(static_cast<T>(size.y)),
         r(static_cast<T>(rotation)) {}

      /// @brief Create a new vector.
      /// @param pos X, Y value.
      /// @param size W, H value.
      /// @param rotation R value.
      template<Number U>
      constexpr Vec5<T>(const sf::Vector2<U>& pos,
                        const sf::Vector2<U>& size,
                        U rotation = U())
         : x(static_cast<T>(pos.x)), y(static_cast<T>(pos.y)),
         w(static_cast<T>(size.x)), h(static_cast<T>(size.y)),
         r(static_cast<T>(rotation)) {}

      /// @brief Create a new vector.
      /// @param bounds X, Y, W and H value.
      /// @param rotation R value.
      template<Number U>
      constexpr Vec5<T>(const Vec4<U>& bounds, U rotation = U())
         : x(static_cast<T>(bounds.x)), y(static_cast<T>(bounds.y)),
         w(static_cast<T>(bounds.w)), h(static_cast<T>(bounds.h)),
         r(static_cast<T>(rotation)) {}
      
      /// @brief Create a new vector.
      /// @param bounds X, Y, W and H value.
      /// @param rotation R value.
      template<Number U>
      constexpr Vec5<T>(const sf::Rect<U>& bounds, U rotation = U())
         : x(static_cast<T>(bounds.left)), y(static_cast<T>(bounds.top)),
         w(static_cast<T>(bounds.width)), h(static_cast<T>(bounds.height)),
         r(static_cast<T>(rotation)) {}

      /// @brief Copy a vector
      /// @param vector Vector to copy.
      template<Number U>
      constexpr Vec5<T>(const Vec5<U>& vector)
         : x(static_cast<T>(vector.x)), y(static_cast<T>(vector.y)),
         w(static_cast<T>(vector.w)), h(static_cast<T>(vector.h)),
         r(static_cast<T>(vector.r)) {}

      // Constructors after creation

      /// @brief Create a new vector.
      /// @param value X, Y, W, H and R value.
      template<Number U>
      constexpr void create(U value)
      {
         x = y = w = h = r = static_cast<T>(value);
      }
      
      /// @brief Create a new vector.
      /// @param pos X, Y value.
      /// @param size W, H value.
      /// @param rotation R value.
      template<Number U>
      constexpr void create(U pos, U size, U rotation = U())
      {
         x = y = static_cast<T>(pos);
         w = h = static_cast<T>(size);
         r = static_cast<T>(rotation);
      }
   
      /// @brief Create a new vector.
      /// @param new_x X value.
      /// @param new_y Y value.
      /// @param new_w W value.
      /// @param new_h H value.
      /// @param new_r R value.
      template<Number U>
      constexpr void create(U new_x, U new_y, U new_w, U new_h, U new_r = U())
      {
         x = static_cast<T>(new_x);
         y = static_cast<T>(new_y);
         w = static_cast<T>(new_w);
         h = static_cast<T>(new_h);
         r = static_cast<T>(new_r);
      }
      
      /// @brief Create a new vector.
      /// @param pos X, Y value.
      /// @param size W, H value.
      /// @param rotation R value.
      template<Number U>
      constexpr void create(const Vec2<U>& pos,
                            const Vec2<U>& size,
                            U rotation = U())
      {
         x = static_cast<T>(pos.x);
         y = static_cast<T>(pos.y);
         w = static_cast<T>(size.x);
         h = static_cast<T>(size.y);
         r = static_cast<T>(rotation);
      }
      
      /// @brief Create a new vector.
      /// @param pos X, Y value.
      /// @param size W, H value.
      /// @param rotation R value.
      template<Number U>
      constexpr void create(const sf::Vector2<U>& pos,
                            const sf::Vector2<U>& size,
                            U rotation = U())
      {
         x = static_cast<T>(pos.x);
         y = static_cast<T>(pos.y);
         w = static_cast<T>(size.x);
         h = static_cast<T>(size.y);
         r = static_cast<T>(rotation);
      }

      /// @brief Create a new vector.
      /// @param bounds X, Y, W and H value.
      /// @param rotation R value.
      template<Number U>
      constexpr void create(const Vec4<U>& bounds, U rotation = U())
      {
         x = static_cast<T>(bounds.x);
         y = static_cast<T>(bounds.y);
         w = static_cast<T>(bounds.w);
         h = static_cast<T>(bounds.h);
         r = static_cast<T>(rotation);
      }

      /// @brief Create a new vector.
      /// @param bounds X, Y, W and H value.
      /// @param rotation R value.
      template<Number U>
      constexpr void create(const sf::Rect<U>& bounds, U rotation = U())
      {
         x = static_cast<T>(bounds.left);
         y = static_cast<T>(bounds.top);
         w = static_cast<T>(bounds.width);
         h = static_cast<T>(bounds.height);
         r = static_cast<T>(rotation);
      }
      
      /// @brief Copy a vector
      /// @param vector Vector to copy.
      template<Number U>
      constexpr void create(const Vec5<U>& vector)
      {
         x = static_cast<T>(vector.x);
         y = static_cast<T>(vector.y);
         w = static_cast<T>(vector.w);
         h = static_cast<T>(vector.h);
         r = static_cast<T>(vector.r);
      }

      // Random constructors

      /// @brief Create a random vector.
      /// @param min Minimum value.
      /// @param max Maximum value.
      /// @return Random vector.
      template<Number U = T>
      inline static Vec5<T> random(U min = U(0), U max = U(1))
      {
         return Vec5<T>(
            cx::random<T>(min, max), cx::random<T>(min, max),
            cx::random<T>(min, max), cx::random<T>(min, max),
            cx::random<T>(min, max)
         );
      }

      /// @brief Create a random vector.
      /// @param min Minimum value.
      /// @param max Maximum value.
      /// @return Random vector.
      template<Number U = T>
      inline static Vec5<T> random(const Vec5<U>& min, const Vec5<U>& max = Vec5<U>(1))
      {
         return Vec5<T>(
            cx::random<T>(min.x, max.x), cx::random<T>(min.y, max.y),
            cx::random<T>(min.w, max.w), cx::random<T>(min.h, max.h),
            cx::random<T>(min.r, max.r)
         );
      }

      // Arithmetic functions

      /// @brief Add two vectors together.
      /// @param other Other vector.
      /// @return Sum.
      template<Number U>
      constexpr Vec5<T> operator+(const Vec5<U>& other) const
      {
         return Vec5<T>(
            x + static_cast<T>(other.x), y + static_cast<T>(other.y),
            w + static_cast<T>(other.w), h + static_cast<T>(other.h),
            r + static_cast<T>(other.r)
         );
      }

      /// @brief Add two vectors together.
      /// @param other Other vector.
      /// @return Sum.
      template<Number U>
      constexpr Vec5<T> operator+(const sf::Rect<U>& other) const
      {
         return Vec5<T>(
            x + static_cast<T>(other.left), y + static_cast<T>(other.top),
            w + static_cast<T>(other.width), h + static_cast<T>(other.height),
            r
         );
      }

      /// @brief Subtract two vectors apart.
      /// @param other Other vector.
      /// @return Difference.
      template<Number U>
      constexpr Vec5<T> operator-(const Vec5<U>& other) const
      {
         return Vec5<T>(
            x - static_cast<T>(other.x), y - static_cast<T>(other.y),
            w - static_cast<T>(other.w), h - static_cast<T>(other.h),
            r - static_cast<T>(other.r)
         );
      }

      /// @brief Subtract two vectors apart.
      /// @param other Other vector.
      /// @return Difference.
      template<Number U>
      constexpr Vec5<T> operator-(const sf::Rect<U>& other) const
      {
         return Vec5<T>(
            x - static_cast<T>(other.left), y - static_cast<T>(other.top),
            w - static_cast<T>(other.width), h - static_cast<T>(other.height),
            r
         );
      }
      
      /// @brief Multiply vector by a factor.
      /// @param factor Factor.
      /// @return Product.
      template<Number U>
      constexpr Vec5<T> operator*(U factor) const
      {
         return Vec5<T>(
            x * static_cast<T>(factor), y * static_cast<T>(factor),
            w * static_cast<T>(factor), h * static_cast<T>(factor),
            r * static_cast<T>(factor)
         ); 
      }

      /// @brief Multiply vectors together.
      /// @param other Other vector.
      /// @return Product.
      template<Number U>
      constexpr Vec5<T> operator*(const Vec5<U>& other) const
      {
         return Vec5<T>(
            x * static_cast<T>(other.x), y * static_cast<T>(other.y),
            w * static_cast<T>(other.w), h * static_cast<T>(other.h),
            r * static_cast<T>(other.r)
         ); 
      }

      /// @brief Multiply vectors together.
      /// @param other Other vector.
      /// @return Product.
      template<Number U>
      constexpr Vec5<T> operator*(const sf::Rect<U>& other) const
      {
         return Vec5<T>(
            x * static_cast<T>(other.left), y * static_cast<T>(other.top),
            w * static_cast<T>(other.width), h * static_cast<T>(other.height),
            r
         ); 
      }
      
      /// @brief Divide vector by the factor.
      /// @param factor Factor.
      /// @return Quotient.
      template<Number U>
      constexpr Vec5<T> operator/(U factor) const
      {
         if (static_cast<T>(factor) == T(0))
            throw std::runtime_error(errors::vector::division_by_zero);

         return Vec5<T>(
            x / static_cast<T>(factor), y / static_cast<T>(factor),
            w / static_cast<T>(factor), h / static_cast<T>(factor),
            r / static_cast<T>(factor)
         ); 
      }

      /// @brief Divide vector by the other.
      /// @param other Other vector.
      /// @return Quotient.
      template<Number U>
      constexpr Vec5<T> operator/(const Vec5<U>& other) const
      {
         if (Vec5<T>(other).zero())
            throw std::runtime_error(errors::vector::division_by_zero);

         return Vec5<T>(
            x / static_cast<T>(other.x), y / static_cast<T>(other.y),
            w / static_cast<T>(other.w), h / static_cast<T>(other.h),
            r / static_cast<T>(other.r)
         ); 
      }
      
      /// @brief Divide vector by the other.
      /// @param other Other vector.
      /// @return Quotient.
      template<Number U>
      constexpr Vec5<T> operator/(const sf::Rect<U>& other) const
      {
         if (Vec5<T>(other).zero())
            throw std::runtime_error(errors::vector::division_by_zero);

         return Vec5<T>(
            x / static_cast<T>(other.x), y / static_cast<T>(other.y),
            w / static_cast<T>(other.w), h / static_cast<T>(other.h), r
         ); 
      }

      /// @brief Negate vector.
      /// @return Negated vector.
      constexpr Vec5<T> operator-() const
      {
         return Vec5<T>(-x, -y, -w, -h, -r);
      }

      // Compound arithmetic functions

      /// @brief Add vectors together.
      /// @param other Other vector.
      /// @return Sum.
      template<Number U>
      constexpr const Vec5<T>& operator+=(const Vec5<U>& other)
      {
         x += static_cast<T>(other.x);
         y += static_cast<T>(other.y);
         w += static_cast<T>(other.w);
         h += static_cast<T>(other.h);
         r += static_cast<T>(other.r);
         return *this;
      }

      /// @brief Add vectors together.
      /// @param other Other vector.
      /// @return Sum.
      template<Number U>
      constexpr const Vec5<T>& operator+=(const sf::Rect<U>& other)
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
      constexpr const Vec5<T>& operator-=(const Vec5<U>& other)
      {
         x -= static_cast<T>(other.x);
         y -= static_cast<T>(other.y);
         w -= static_cast<T>(other.w);
         h -= static_cast<T>(other.h);
         r -= static_cast<T>(other.r);
         return *this;
      }

      /// @brief Subtract vectors apart.
      /// @param other Other vector.
      /// @return Difference.
      template<Number U>
      constexpr const Vec5<T>& operator-=(const sf::Rect<U>& other)
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
      constexpr const Vec5<T>& operator*=(U factor)
      {
         x *= static_cast<T>(factor);
         y *= static_cast<T>(factor);
         w *= static_cast<T>(factor);
         h *= static_cast<T>(factor);
         r *= static_cast<T>(factor);
         return *this;
      }

      /// @brief Multiply vectors together.
      /// @param other Other vector.
      /// @return Product.
      template<Number U>
      constexpr const Vec5<T>& operator*=(const Vec5<U>& other)
      {
         x *= static_cast<T>(other.x);
         y *= static_cast<T>(other.y);
         w *= static_cast<T>(other.w);
         h *= static_cast<T>(other.h);
         r *= static_cast<T>(other.r);
         return *this;
      }

      /// @brief Multiply vectors together.
      /// @param other Other vector.
      /// @return Product.
      template<Number U>
      constexpr const Vec5<T>& operator*=(const sf::Rect<U>& other)
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
      constexpr const Vec5<T>& operator/=(U factor)
      {
         if (static_cast<T>(factor) == T(0))
            throw std::runtime_error(errors::vector::division_by_zero);

         x /= static_cast<T>(factor);
         y /= static_cast<T>(factor);
         w /= static_cast<T>(factor);
         h /= static_cast<T>(factor);
         r /= static_cast<T>(factor);
         return *this;
      }

      /// @brief Divide vectors apart.
      /// @param other Other vector.
      /// @return Quotient.
      template<Number U>
      constexpr const Vec5<T>& operator/=(const Vec5<U>& other)
      {
         if (Vec5<T>(other).zero())
            throw std::runtime_error(errors::vector::division_by_zero);

         x /= static_cast<T>(other.x);
         y /= static_cast<T>(other.y);
         w /= static_cast<T>(other.w);
         h /= static_cast<T>(other.h);
         r /= static_cast<T>(other.r);
         return *this;
      }

      /// @brief Divide vectors apart.
      /// @param other Other vector.
      /// @return Quotient.
      template<Number U>
      constexpr const Vec5<T>& operator/=(const sf::Rect<U>& other)
      {
         if (Vec5<T>(other).zero())
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
      constexpr Vec5<T> abs() const
      {
         return Vec5<T>(
            (x < T(0) ? -x : x), (y < T(0) ? -y : y), (w < T(0) ? -w : w),
            (h < T(0) ? -h : h), (r < T(0) ? -r : r)
         );
      }

      /// @brief Clamp values between the given range.
      /// @param min Minimum value.
      /// @param max Maximum value.
      /// @return Clamped vector.
      template<Number U>
      constexpr Vec5<T> clamp(U min, U max) const
      {
         const auto n_min = static_cast<T>(min);
         const auto n_max = static_cast<T>(max);
         return Vec5<T>(
            (x > n_max ? n_max : (x < n_min ? n_min : x)), (y > n_max ? n_max : (y < n_min ? n_min : y)),
            (w > n_max ? n_max : (w < n_min ? n_min : w)), (h > n_max ? n_max : (h < n_min ? n_min : h)),
            (r > n_max ? n_max : (r < n_min ? n_min : r))
         );
      }

      /// @brief Set values above minimum value.
      /// @param min Minimum value.
      /// @return Vector with values above minimum value.
      template<Number U>
      constexpr Vec5<T> min(U min) const
      {
         const auto n_min = static_cast<T>(min);
         return Vec5<T>(
            (x < n_min ? n_min : x), (y < n_min ? n_min : y), (w < n_min ? n_min : w),
            (h < n_min ? n_min : h), (r < n_min ? n_min : r)
         );
      }

      /// @brief Set values below maximum value.
      /// @param max Maximum value.
      /// @return Vector with values below maximum value.
      template<Number U>
      constexpr Vec5<T> max(U max) const
      {
         const auto n_max = static_cast<T>(max);
         return Vec5<T>(
            (x > n_max ? n_max : x), (y > n_max ? n_max : y), (w > n_max ? n_max : w),
            (h > n_max ? n_max : h), (r > n_max ? n_max : r)
         );
      }

      /// @brief Get dot product.
      /// @param other Other vector.
      /// @return Dot product.
      template<Number U>
      constexpr T dot(const Vec5<U>& other) const
      {
         return x * static_cast<T>(other.x) + y * static_cast<T>(other.y) + w * static_cast<T>(other.w)
            + h * static_cast<T>(other.h) + r * static_cast<T>(other.r);
      }

      /// @brief Get magnitude.
      /// @return Magnitude.
      constexpr T magnitude() const
      {
         return sqrt(x * x + y * y + w * w + h * h + r * r);
      }

      /// @brief Get magnitude squared.
      /// @return Magnitude squared.
      constexpr T magnitude_squared() const
      {
         return x * x + y * y + w * w + h * h + r * r;
      }

      /// @brief Get distance between two vectors.
      /// @param other Other vector.
      /// @return Distance.
      template<Number U>
      constexpr float distance(const Vec5<U>& other) const
      {
         const auto nx = x - static_cast<T>(other.x);
         const auto ny = y - static_cast<T>(other.y);
         return std::sqrt(x * x + y * y);
      }

      /// @brief Get distance squared between two vectors.
      /// @param other Other vector.
      /// @return Distance squared.
      template<Number U>
      constexpr float distance_squared(const Vec5<U>& other) const
      {
         const auto nx = x - static_cast<T>(other.x);
         const auto ny = y - static_cast<T>(other.y);
         return x * x + y * y;
      }

      /// @brief Normalize vector.
      /// @return Normalized vector.
      constexpr Vec5<T> normalize() const
      {
         const auto mag = magnitude();
         return (mag == T(0) ? Vec5<T>() : *this / mag);
      }

      /// @brief Check for collision against a point without rotation.
      /// @param point Point to check collision against.
      /// @return True if colliding.
      template<Number U>
      constexpr bool basic_contains(const Vec2<U>& position) const
      {
         return !(static_cast<T>(position.x) < x || static_cast<T>(position.x) > x + w
            || static_cast<T>(position.y) < y || static_cast<T>(position.y) > y + h);
      }

      /// @brief Check for collision against rectangle without rotation.
      /// @param rect Rectangle to check collision against.
      /// @return True if colliding.
      template<Number U>
      constexpr bool basic_colliding(const Vec5<U>& rect) const
      {
         return !(x > static_cast<T>(rect.x + rect.w) || x + w < static_cast<T>(rect.x)
            || y > static_cast<T>(rect.y + rect.h) || y + h < static_cast<T>(rect.y));
      }

      /// @brief Get rectangle axes.
      /// @return Both rectangle axes.
      constexpr std::array<Vec4<T>, 2> get_axes() const
      {
         const Vec2<T> center (x + w / T(2), y + h / T(2));
         return {
            Vec4<T>(center, Vec2<T>(T(1), T(0)).rotate(cx::Rad::convert(r)).normalize()),
            Vec4<T>(center, Vec2<T>(T(0), T(1)).rotate(cx::Rad::convert(r)).normalize())
         };
      }

      /// @brief Get corners of the rectangle.
      /// @return Rectangle corners.
      constexpr std::array<Vec2<T>, 4> get_corners() const
      {
         const std::array<Vec4<T>, 2> axis {get_axes()};
         const Vec2<T> rx {axis.at(0).get_size() * (w / T(2))};
         const Vec2<T> ry {axis.at(1).get_size() * (h / T(2))};
         const Vec2<T> center (x + w / T(2), y + h / T(2));

         return {
            center + rx + ry, center + rx - ry,
            center - rx - ry, center - rx + ry
         };
      }

      /// @brief Check for collision against a point.
      /// @param point Point to check collision against.
      /// @return True if colliding.
      template<Number U>
      constexpr bool contains(const Vec2<U>& point) const
      {
         const Vec2<T> position = point;

         if (!rotated())
            return basic_contains(point);

         const Vec2<T> center = get_center();
         const Vec2<T> trans (Vec2<T>(position - center).rotate(cx::Rad::convert(-r)));

         const T halfW = w / T(2);
         const T halfH = h / T(2);

         return !(trans.x < -halfW || trans.x > halfW || trans.y < -halfH || trans.y > halfH);
      }

      /// @brief Check for collision against rectangle.
      /// @param bounds Rectangle to check collision against.
      /// @return True if colliding.
      template<Number U>
      constexpr bool colliding(const Vec5<U>& bounds) const
      {
         const Vec5<T> rect = bounds;

         if (!rotated() && !bounds.rotated())
            return basic_colliding(bounds);

         const auto axes1 {get_axes()};
         const auto axes2 {rect.get_axes()};
         
         std::array<Vec4<T>, 4> axes {axes1.at(0), axes1.at(1), axes2.at(0), axes2.at(1)};

         const auto corners1 {get_corners()};
         const auto corners2 {rect.get_corners()};

         for (const auto& axis : axes)
         {
            T min1 {std::numeric_limits<T>::max()};
            T max1 {std::numeric_limits<T>::lowest()};

            for (const auto& corner : corners1)
            {
               const T projection {corner.project(axis.get_top_left(), axis.get_size())};
               min1 = std::min(min1, projection);
               max1 = std::max(max1, projection);
            }

            T min2 {std::numeric_limits<T>::max()};
            T max2 {std::numeric_limits<T>::lowest()};

            for (const auto& corner : corners2)
            {
               const T projection {corner.project(axis.get_top_left(), axis.get_size())};
               min2 = std::min(min2, projection);
               max2 = std::max(max2, projection);   
            }

            if (max1 < min2 || max2 < min1)
               return false;
         }
         return true;
      }

      /// @brief Linearly interpolate between two vectors.
      /// @param b Ending value.
      /// @param t Interpolation factor.
      /// @return Middle point between this and b based on factor t.
      template<Number U>
      constexpr Vec5<T> lerp(const Vec5<U>& other, float t) const
      {
         return *this + (Vec5<T>(other) - *this) * t;
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

      /// @brief Get un-rotated bounds.
      /// @return Simple bounds.
      constexpr Vec4<T> un_rotated() const
      {
         return Vec4<T>(x, y, w, h);
      }

      // Condition functions

      /// @brief Check if vector is positive.
      /// @return True if all values are positive.
      constexpr bool positive() const
      {
         return x >= T(0) && y >= T(0) && w >= T(0) && h >= T(0) && r >= T(0);
      }

      /// @brief Check if vector is negative.
      /// @return True if all values are negative.
      constexpr bool negative() const
      {
         return x <= T(0) && y <= T(0) && w <= T(0) && h <= T(0) && r <= T(0);
      }

      /// @brief Check if vector is empty.
      /// @return True if all values are zero.
      constexpr bool empty() const
      {
         return x == T(0) && y == T(0) && w == T(0) && h == T(0) && r == T(0);
      }

      /// @brief Check if atleast one vector value is zero.
      /// @return True if atleast one value is zero.
      constexpr bool zero() const
      {
         return x == T(0) || y == T(0) || w == T(0) || h == T(0) || r == T(0);
      }

      /// @brief Check if bounds are rotated.
      /// @return True if rotated.
      constexpr bool rotated() const
      {
         return r != T(0);
      }

      /// @brief Compare two vectors.
      /// @param other Other vector.
      /// @return True if both are different.
      template<Number U>
      constexpr bool operator!=(const Vec5<U>& other) const
      {
         return x != static_cast<T>(other.x) || y != static_cast<T>(other.y)
             || w != static_cast<T>(other.w) || h != static_cast<T>(other.h)
             || r != static_cast<T>(other.r);
      }

      /// @brief Compare two vectors.
      /// @param other Other vector.
      /// @return True if both are equal.
      template<Number U>
      constexpr bool operator==(const Vec5<U>& other) const
      {
         return !(*this != other);
      }

      // Other functions

      /// @brief Copy a vector.
      /// @param other Other vector.
      /// @return Vector.
      template<Number U>
      constexpr const Vec5<T>& operator=(const Vec5<U>& other)
      {
         x = static_cast<T>(other.x);
         y = static_cast<T>(other.y);
         w = static_cast<T>(other.w);
         h = static_cast<T>(other.h);
         r = static_cast<T>(other.r);
         return *this;
      }

      /// @brief Copy a vector.
      /// @param other Other vector.
      /// @return Vector.
      template<Number U>
      constexpr const Vec5<T>& operator=(const sf::Rect<U>& other)
      {
         x = static_cast<T>(other.left);
         y = static_cast<T>(other.top);
         w = static_cast<T>(other.width);
         h = static_cast<T>(other.height);
         r = T(0);
         return *this;
      }

      /// @brief Return value by index.
      /// @param index Index of the value.
      /// @return Value.
      constexpr T& operator[](size_t index)
      {
         if (index > 4)
            throw std::runtime_error(errors::vector::out_of_bounds);
         return (index == 0 ? x : (index == 1 ? y : (index == 2 ? w : (index== 3 ? h : r))));
      }

      /// @brief Return value by index.
      /// @param index Index of the value.
      /// @return Value.
      constexpr T operator[](size_t index) const
      {
         if (index > 4)
            throw std::runtime_error(errors::vector::out_of_bounds);
         return (index == 0 ? x : (index == 1 ? y : (index == 2 ? w : (index== 3 ? h : r))));
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
         x = y = w = h = r = T(0);
      }

      /// @brief Get vector size.
      /// @return Size.
      constexpr size_t size() const
      {
         return 5;
      }

      /// @brief Convert vector.
      template<Number U>
      inline operator sf::Rect<U>() const
      {
         return sf::Rect<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(w), static_cast<U>(h));
      }

      /// @brief Convert vector.
      template<Number U>
      constexpr operator Vec4<U>() const
      {
         return Vec4<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(w), static_cast<U>(h));
      }

      /// @brief Convert vector.
      template<Number U>
      constexpr operator Vec5<U>() const
      {
         return Vec5<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(w), static_cast<U>(h), static_cast<U>(r));
      }

      /// @brief Convert vector.
      template<Number U = T>
      inline sf::Rect<U> sfml() const
      {
         return sf::Rect<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(w), static_cast<U>(h));
      }
   };

   using Vec5f = Vec5<float>;    ///< @brief 5 value container.
   using Vec5i = Vec5<int32_t>;  ///< @brief 5 value container.
   using Vec5u = Vec5<uint32_t>; ///< @brief 5 value container.
}

#endif
