#ifndef CX_VECTOR_VEC3_HPP
#define CX_VECTOR_VEC3_HPP

#include <SFML/System/Vector3.hpp>
#include <CX/Vector/Vec2.hpp>

namespace cx
{
   /// @brief 3 value container.
   template<Number T>
   struct Vec3
   {
      T x {}; ///< @brief X value.
      T y {}; ///< @brief Y value.
      T z {}; ///< @brief Z value.

      // Constructors

      /// @brief Create an empty vector.
      constexpr Vec3<T>()
         : x(T()), y(T()), z(T()) {}

      /// @brief Create a new vector.
      /// @param value X, Y and Z value.
      template<Number U>
      constexpr Vec3<T>(U value)
         : x(static_cast<T>(value)), y(static_cast<T>(value)), z(static_cast<T>(value)) {}

      /// @brief Create a new vector.
      /// @param x X value.
      /// @param y Y value.
      /// @param z Z value.
      template<Number U>
      constexpr Vec3<T>(U x, U y, U z)
         : x(static_cast<T>(x)), y(static_cast<T>(y)), z(static_cast<T>(z)) {}
      
      /// @brief Copy a vector.
      /// @param vector Vector to copy.
      template<Number U>
      constexpr Vec3<T>(const Vec3<U>& vector)
         : x(static_cast<T>(vector.x)), y(static_cast<T>(vector.y)), z(static_cast<T>(vector.z)) {}

      /// @brief Copy a vector.
      /// @param vector Vector to copy.
      template<Number U>
      constexpr Vec3<T>(const sf::Vector3<U>& vector)
         : x(static_cast<T>(vector.x)), y(static_cast<T>(vector.y)), z(static_cast<T>(vector.z)) {}
      
      // Constructors after creation

      /// @brief Create a new vector.
      /// @param value X, Y and Z value.
      template<Number U>
      constexpr void create(U value)
      {
         x = y = z = static_cast<T>(value);
      }

      /// @brief Create a new vector.
      /// @param new_x X value.
      /// @param new_y Y value.
      /// @param new_z Z value.
      template<Number U>
      constexpr void create(U new_x, U new_y, U new_z)
      {
         x = static_cast<T>(new_x);
         y = static_cast<T>(new_y);
         z = static_cast<T>(new_z);
      }

      /// @brief Copy a vector.
      /// @param vector Vector to copy.
      template<Number U>
      constexpr void create(const Vec3<U>& vector)
      {
         x = static_cast<T>(vector.x);
         y = static_cast<T>(vector.y);
         z = static_cast<T>(vector.z);
      }

      /// @brief Copy a vector.
      /// @param vector Vector to copy.
      template<Number U>
      constexpr void create(const sf::Vector3<U>& vector)
      {
         x = static_cast<T>(vector.x);
         y = static_cast<T>(vector.y);
         z = static_cast<T>(vector.z);
      }

      // Random constructors

      /// @brief Create a random vector.
      /// @param min Minimum value.
      /// @param max Maximum value.
      /// @return Random vector.
      template<Number U = T>
      inline static Vec3<T> random(U min = U(0), U max = U(1))
      {
         return {cx::random<T>(min, max), cx::random<T>(min, max), cx::random<T>(min, max)};
      }

      /// @brief Create a random vector.
      /// @param min Minimum values.
      /// @param max Maximum values.
      /// @return Random vector.
      template<Number U = T>
      inline static Vec3<T> random(const Vec3<U>& min, const Vec3<U>& max = Vec3<U>(1))
      {
         return {cx::random<T>(min.x, max.x), cx::random<T>(min.y, max.y), cx::random<T>(min.z, max.z)};
      }

      // Arithmetic functions

      /// @brief Add two vectors together.
      /// @param other Other vector.
      /// @return Sum.
      template<Number U>
      constexpr Vec3<T> operator+(const Vec3<U>& other) const
      {
         return {x + static_cast<T>(other.x), y + static_cast<T>(other.y), z + static_cast<T>(other.z)};
      }

      /// @brief Add two vectors together.
      /// @param other Other vector.
      /// @return Sum.
      template<Number U>
      constexpr Vec3<T> operator+(const sf::Vector3<U>& other) const
      {
         return {x + static_cast<T>(other.x), y + static_cast<T>(other.y), z + static_cast<T>(other.z)};
      }

      /// @brief Subtract two vectors apart.
      /// @param other Other vector.
      /// @return Difference.
      template<Number U>
      constexpr Vec3<T> operator-(const Vec3<U>& other) const
      {
         return {x - static_cast<T>(other.x), y - static_cast<T>(other.y), z - static_cast<T>(other.z)};
      }

      /// @brief Subtract two vectors apart.
      /// @param other Other vector.
      /// @return Difference.
      template<Number U>
      constexpr Vec3<T> operator-(const sf::Vector3<U>& other) const
      {
         return {x - static_cast<T>(other.x), y - static_cast<T>(other.y), z - static_cast<T>(other.z)};
      }

      /// @brief Multiply vector by the factor.
      /// @param factor Factor.
      /// @return Product.
      template<Number U>
      constexpr Vec3<T> operator*(U factor) const
      {
         const auto sfactor = static_cast<T>(factor);
         return {x * sfactor, y * sfactor, z * sfactor};
      }

      /// @brief Multiply vectors together.
      /// @param other Other vector.
      /// @return Product.
      template<Number U>
      constexpr Vec3<T> operator*(const Vec3<U>& other) const
      {
         return {x * static_cast<T>(other.x), y * static_cast<T>(other.y), z * static_cast<T>(other.z)};
      }

      /// @brief Multiply vectors together.
      /// @param other Other vector.
      /// @return Product.
      template<Number U>
      constexpr Vec3<T> operator*(const sf::Vector3<U>& other) const
      {
         return {x * static_cast<T>(other.x), y * static_cast<T>(other.y), z * static_cast<T>(other.z)};
      }

      /// @brief Divide vector by the factor.
      /// @param factor Factor.
      /// @return Quotient.
      template<Number U>
      constexpr Vec3<T> operator/(U factor) const
      {
         const auto sfactor = static_cast<T>(factor);
         if (sfactor == T(0))
            throw std::runtime_error(errors::vector::division_by_zero);
         return {x / sfactor, y / sfactor, z / sfactor};
      }

      /// @brief Divide vector by the other.
      /// @param other Other vector.
      /// @return Quotient.
      template<Number U>
      constexpr Vec3<T> operator/(const Vec3<U>& other) const
      {
         if (Vec2<T>(other).zero())
            throw std::runtime_error(errors::vector::division_by_zero);
         return {x / static_cast<T>(other.x), y / static_cast<T>(other.y), z / static_cast<T>(other.z)};
      }

      /// @brief Divide vector by the other.
      /// @param other Other vector.
      /// @return Quotient.
      template<Number U>
      constexpr Vec3<T> operator/(const sf::Vector3<U>& other) const
      {
         if (Vec2<T>(other).zero())
            throw std::runtime_error(errors::vector::division_by_zero);
         return {x / static_cast<T>(other.x), y / static_cast<T>(other.y), z / static_cast<T>(other.z)};
      }

      /// @brief Negate vector.
      /// @return Negated vector.
      constexpr Vec3<T> operator-() const
      {
         return {-x, -y, -z};
      }

      // Compound arithmetic functions

      /// @brief Add vectors together.
      /// @param other Other vector.
      /// @return Sum.
      template<Number U>
      constexpr const Vec3<T>& operator+=(const Vec3<U>& other)
      {
         *this = *this + other;
         return *this;
      }

      /// @brief Add vectors together.
      /// @param other Other vector.
      /// @return Sum.
      template<Number U>
      constexpr const Vec3<T>& operator+=(const sf::Vector3<U>& other)
      {
         *this = *this + other;
         return *this;
      }

      /// @brief Subtract vectors apart.
      /// @param other Other vector.
      /// @return Difference.
      template<Number U>
      constexpr const Vec3<T>& operator-=(const Vec3<U>& other)
      {
         *this = *this - other;
         return *this;
      }

      /// @brief Subtract vectors apart.
      /// @param other Other vector.
      /// @return Difference.
      template<Number U>
      constexpr const Vec3<T>& operator-=(const sf::Vector3<U>& other)
      {
         *this = *this - other;
         return *this;
      }

      /// @brief Multiply vector by the factor.
      /// @param factor Factor.
      /// @return Product.
      template<Number U>
      constexpr const Vec3<T>& operator*=(U factor)
      {
         *this = *this * factor;
         return *this;
      }

      /// @brief Multiply vectors together.
      /// @param other Other vector.
      /// @return Product.
      template<Number U>
      constexpr const Vec3<T>& operator*=(const Vec3<U>& other)
      {
         *this = *this * other;
         return *this;
      }

      /// @brief Multiply vectors together.
      /// @param other Other vector.
      /// @return Product.
      template<Number U>
      constexpr const Vec3<T>& operator*=(const sf::Vector3<U>& other)
      {
         *this = *this * other;
         return *this;
      }

      /// @brief Divide vector by the factor.
      /// @param factor Factor.
      /// @return Quotient.
      template<Number U>
      constexpr const Vec3<T>& operator/=(U factor)
      {
         *this = *this / factor;
         return *this;
      }

      /// @brief Divide vectors apart.
      /// @param other Other vector.
      /// @return Quotient.
      template<Number U>
      constexpr const Vec3<T>& operator/=(const Vec3<U>& other)
      {
         *this = *this / other;
         return *this;
      }

      /// @brief Divide vectors apart.
      /// @param other Other vector.
      /// @return Quotient.
      template<Number U>
      constexpr const Vec3<T>& operator/=(const sf::Vector3<U>& other)
      {
         *this = *this / other;
         return *this;
      }

      // Math functions

      /// @brief Get absolute vector.
      /// @return Absolute vector.
      constexpr Vec3<T> abs() const
      {
         return {(x < T(0) ? -x : x), (y < T(0) ? -y : y), (z < T(0) ? -z : z)};
      }

      /// @brief Clamp values between the given range.
      /// @param min Minimum value.
      /// @param max Maximum value.
      /// @return Clamped vector.
      template<Number U>
      constexpr Vec3<T> clamp(U min, U max) const
      {
         const auto n_min = static_cast<T>(min);
         const auto n_max = static_cast<T>(max);
         return {
            (x > n_max ? n_max : (x < n_min ? n_min : x)), 
            (y > n_max ? n_max : (y < n_min ? n_min : y)), 
            (z > n_max ? n_max : (z < n_min ? n_min : z))
         };
      }

      /// @brief Set values above minimum value.
      /// @param min Minimum value.
      /// @return Vector with values above minimum value.
      template<Number U>
      constexpr Vec3<T> min(U min) const
      {
         const auto n_min = static_cast<T>(min);
         return {(x < n_min ? n_min : x), (y < n_min ? n_min : y), (z < n_min ? n_min : z)};
      }

      /// @brief Set values below maximum value.
      /// @param max Maximum value.
      /// @return Vector with values below maximum value.
      template<Number U>
      constexpr Vec3<T> max(U max) const
      {
         const auto n_max = static_cast<T>(max);
         return {(x > n_max ? n_max : x), (y > n_max ? n_max : y), (z > n_max ? n_max : z)};
      }

      /// @brief Get dot product.
      /// @param other Other vector.
      /// @return Dot product.
      template<Number U>
      constexpr float dot(const Vec3<U>& other) const
      {
         return x * static_cast<T>(other.x) + y * static_cast<T>(other.y) + z * static_cast<T>(other.z);
      }

      /// @brief Get dot product.
      /// @param other Other vector.
      /// @return Dot product.
      template<Number U>
      constexpr float dot(const sf::Vector3<U>& other) const
      {
         return dot(Vec3<T>(other));
      }

      /// @brief Get cross product.
      /// @param other Other vector.
      /// @return Cross product.
      template<Number U>
      constexpr Vec3<T> cross(const Vec3<U>& other) const
      {
         return {
            y * static_cast<T>(other.z) - z * static_cast<T>(other.y),
            z * static_cast<T>(other.x) - x * static_cast<T>(other.z),
            x * static_cast<T>(other.y) - y * static_cast<T>(other.x)
         };
      }

      /// @brief Get cross product.
      /// @param other Other vector.
      /// @return Cross product.
      template<Number U>
      constexpr Vec3<T> cross(const sf::Vector3<U>& other) const
      {
         return cross(Vec3<T>(other));
      }

      /// @brief Get magnitude squared.
      /// @return Magnitude squared.
      constexpr float magnitude_squared() const
      {
         return x * x + y * y + z * z;
      }

      /// @brief Get magnitude.
      /// @return Magnitude.
      constexpr float magnitude() const
      {
         return std::sqrt(magnitude_squared());
      }

      /// @brief Get distance squared between two vectors.
      /// @param other Other vector.
      /// @return Distance squared.
      template<Number U>
      constexpr float distance_squared(const Vec3<U>& other) const
      {
         const auto nx = x - static_cast<T>(other.x);
         const auto ny = y - static_cast<T>(other.y);
         const auto nz = z - static_cast<T>(other.z);
         return nx * nx + ny * ny + nz * nz;
      }

      /// @brief Get distance squared between two vectors.
      /// @param other Other vector.
      /// @return Distance squared.
      template<Number U>
      constexpr float distance_squared(const sf::Vector3<U>& other) const
      {
         return distance_squared(Vec3<T>(other));
      }

      /// @brief Get distance between two vectors.
      /// @param other Other vector.
      /// @return Distance.
      template<Number U>
      constexpr float distance(const Vec3<U>& other) const
      {
         return std::sqrt(distance_squared(other));
      }

      /// @brief Get distance between two vectors.
      /// @param other Other vector.
      /// @return Distance.
      template<Number U>
      constexpr float distance(const sf::Vector3<U>& other) const
      {
         return std::sqrt(distance_squared(other));
      }

      /// @brief Normalize vector.
      /// @return Normalized vector.
      constexpr Vec3<T> normalize() const
      {
         const T mag = magnitude();
         return (mag == T(0) ? Vec3<T>() : *this / mag);
      }

      /// @brief Linearly interpolate between two vectors.
      /// @param b Ending value.
      /// @param t Interpolation factor.
      /// @return Middle point between this and b based on factor t.
      template<Number U, Floating Y = float>
      constexpr Vec3<T> lerp(const Vec3<U>& b, Y t) const
      {
         return *this + (b - *this) * t;
      }

      /// @brief Linearly interpolate between two vectors.
      /// @param b Ending value.
      /// @param t Interpolation factor.
      /// @return Middle point between this and b based on factor t.
      template<Number U, Floating Y = float>
      constexpr Vec3<T> lerp(const sf::Vector3<U>& b, Y t) const
      {
         return lerp(Vec3<T>(b), t);
      }

      /// @brief Project the vector in 2d space.
      /// @return Point projected onto 2d space.
      constexpr Vec2<T> project() const
      {
         const T denom = std::max<T>(z + T(1), T(0.001));
         return Vec2<T>(x, y) / denom;
      }

      /// @brief Project the vector in 2d space.
      /// @param f Focal length.
      /// @return Point projected onto 2d space.
      constexpr Vec2<T> project(T f) const
      {
         if (z <= -f + 1e-3)
            return Vec2<T>(x, y) * f;

         const auto factor = f / (z + f);
         return Vec2<T>(x, y) * factor;
      }

      /// @brief Rotate the vector in 3d space.
      /// @param angle Angles in radians.
      /// @return Rotated point.
      template<Number U>
      constexpr Vec3<T> rotate(const Vec3<U>& angles) const
      {
         const auto angle = Vec3<T>(angles);
         float cx = std::cos(angle.x), sx = std::sin(angle.x);
         float cy = std::cos(angle.y), sy = std::sin(angle.y);
         float cz = std::cos(angle.z), sz = std::sin(angle.z);

          auto copy = *this;

         // Rotate X-axis
         float y1 = copy.y * cx - copy.z * sx;
         float z1 = copy.y * sx + copy.z * cx;
         copy.y = y1;
         copy.z = z1;

         // Rotate Y-axis
         float x2 = copy.x * cy + copy.z * sy;
         float z2 = -copy.x * sy + copy.z * cy;
         copy.x = x2;
         copy.z = z2;

         // Rotate Z-axis
         float x3 = copy.x * cz - copy.y * sz;
         float y3 = copy.x * sz + copy.y * cz;
         copy.x = x3;
         copy.y = y3;

         return copy;
      }

      // Condition functions

      /// @brief Check if vector is positive.
      /// @return True if all values are positive.
      constexpr bool positive() const
      {
         return x >= T(0) && y >= T(0) && z >= T(0);
      }

      /// @brief Check if vector is negative.
      /// @return True if all values are negative.
      constexpr bool negative() const
      {
         return x <= T(0) && y <= T(0) && z <= T(0);
      }

      /// @brief Check if vector is empty.
      /// @return True if all values are zero.
      constexpr bool empty() const
      {
         return x == T(0) && y == T(0) && z == T(0);
      }

      /// @brief Check if any vector value is zero.
      /// @return True if atleast one is zero.
      constexpr bool zero() const
      {
         return x == T(0) || y == T(0) || z == T(0);
      }

      /// @brief Compare two vectors.
      /// @param other Other vector.
      /// @return True if both are different.
      template<Number U>
      constexpr bool operator!=(const Vec3<U>& other) const
      {
         return x != static_cast<T>(other.x) || y != static_cast<T>(other.y) || z != static_cast<T>(other.z);
      }

      /// @brief Compare two vectors.
      /// @param other Other vector.
      /// @return True if both are different.
      template<Number U>
      constexpr bool operator!=(const sf::Vector3<U>& other) const
      {
         return x != static_cast<T>(other.x) || y != static_cast<T>(other.y) || z != static_cast<T>(other.z);
      }

      /// @brief Compare two vectors.
      /// @param other Other vector.
      /// @return True if both are equal.
      template<Number U>
      constexpr bool operator==(const Vec3<U>& other) const
      {
         return !(*this != other);
      }

      /// @brief Compare two vectors.
      /// @param other Other vector.
      /// @return True if both are equal.
      template<Number U>
      constexpr bool operator==(const sf::Vector3<U>& other) const
      {
         return !(*this != other);
      }

      // Other functions

      /// @brief Copy a vector.
      /// @param other Other vector.
      /// @return Vector.
      template<Number U>
      constexpr const Vec3<T>& operator=(const Vec3<U>& other)
      {
         x = static_cast<T>(other.x);
         y = static_cast<T>(other.y);
         z = static_cast<T>(other.z);
         return *this;
      }

      /// @brief Copy a vector.
      /// @param other Other vector.
      /// @return Vector.
      template<Number U>
      constexpr const Vec3<T>& operator=(const sf::Vector3<U>& other)
      {
         x = static_cast<T>(other.x);
         y = static_cast<T>(other.y);
         z = static_cast<T>(other.z);
         return *this;
      }

      /// @brief Return value by index.
      /// @param index Index of the value.
      /// @return Value.
      constexpr T& operator[](size_t index)
      {
         if (index > 2)
            throw std::runtime_error(errors::vector::out_of_bounds);
         return (index == 2 ? z : (index == 1 ? y : x));
      }

      /// @brief Return value by index.
      /// @param index Index of the value.
      /// @return Value.
      constexpr T operator[](size_t index) const
      {
         if (index > 2)
            throw std::runtime_error(errors::vector::out_of_bounds);
         return (index == 2 ? z : (index == 1 ? y : x));
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
         x = y = z = T(0);
      }

      /// @brief Get vector size.
      /// @return Size.
      constexpr size_t size() const
      {
         return 3;
      }

      /// @brief Convert vector.
      template<Number U>
      inline operator sf::Vector3<U>() const
      {
         return sf::Vector3<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(z));
      }

      /// @brief Convert vector.
      template<Number U>
      constexpr operator Vec3<U>() const
      {
         return Vec3<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(z));
      }

      /// @brief Convert vector.
      template<Number U = T>
      inline sf::Vector3<U> sfml() const
      {
         return sf::Vector3<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(z));
      }
   };

   using Vec3f = Vec3<float>;    ///< @brief 3 value container.
   using Vec3i = Vec3<int32_t>;  ///< @brief 3 value container.
   using Vec3u = Vec3<uint32_t>; ///< @brief 3 value container.
}

#endif

