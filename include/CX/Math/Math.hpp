#ifndef CX_MATH_MATH_HPP
#define CX_MATH_MATH_HPP

#include "CX/Math/Constants.hpp"

namespace cx
{
   /// @brief Clamp value between the given range.
   /// @param value Value to clamp.
   /// @param min Minimum value.
   /// @param max Maximum value.
   /// @return Clamped value.
   template<Number T>
   constexpr T clamp(T value, T min, T max)
   {
      return (value > max ? max : (value < min ? min : value));
   }

   /// @brief Get absolute value of a number.
   /// @param value Number.
   /// @return Absolute value.
   template<SignedNumber T>
   constexpr T abs(T value)
   {
      return (value < T(0) ? -value : value);
   }

   /// @brief Get absolute value of a number.
   /// @param value Number.
   /// @return Absolute value.
   template<UnsignedIntegral T>
   constexpr T abs(T value)
   {
      return value;
   }

   /// @brief Get sign of a number.
   /// @param value Number.
   /// @return Sign.
   template<SignedNumber T>
   constexpr int8_t sign(T value)
   {
      return (value > T(0)) - (value < T(0));
   }

   /// @brief Get sign of a number.
   /// @param value Number.
   /// @return Sign.
   template<UnsignedIntegral T>
   constexpr int8_t sign(T value)
   {
      return value != 0;
   }

   /// @brief Get smallest number.
   /// @param value1 First number.
   /// @param value2 Second number.
   /// @return Smallest number.
   template<Number T>
   constexpr T min(T value1, T value2)
   {
      return (value1 < value2 ? value1 : value2);
   }

   /// @brief Get largest number.
   /// @param value1 First number.
   /// @param value2 Second number.
   /// @return Largest number.
   template<Number T>
   constexpr T max(T value1, T value2)
   {
      return (value1 < value2 ? value2 : value1);
   }

   /// @brief Linearly interpolate between two values.
   /// @param a Starting value.
   /// @param b Ending value.
   /// @param t Interpolation factor.
   /// @return Middle point between a and b based on factor t.
   template<Number T, Floating U>
   constexpr T lerp(T a, T b, U t)
   {
      return a + (b - a) * t;
   }

   /// @brief Get remainder of a number.
   /// @param value Number.
   /// @param mod Divisor.
   /// @return Remainder.
   template<Integral T>
   constexpr T mod(T value, T mod)
   {
      return (value % mod + mod) % mod;
   }

   /// @brief Exponentiate the base.
   /// @param base Base.
   /// @param power Exponent.
   /// @return Exponentiation result.
   template<Number T>
   constexpr T pow(T base, size_t power)
   {
      T result = 1;

      for (;power > 0;)
      {
         if (power & 1)
            result *= base;

         base *= base;
         power >>= 1;
      }
      return result;
   }

   /// @brief Compare two floats.
   /// @param a First float.
   /// @param b Second float.
   /// @param epsilon Maximum offset.
   /// @return True if numbers are approximately equal.
   template<Floating T>
   constexpr bool apr_equal(T a, T b, T epsilon = 1e-5f)
   {
      return (a > b ? a - b : b - a) < epsilon;
   }

   /// @brief Round a number up to a full number.
   /// @param value Number.
   /// @return Rounded number.
   template<Floating T>
   constexpr T ceil(T value)
   {
      return static_cast<T>(static_cast<long>((value > T(0) ? value + Constants<T>::round : value)));
   }

   /// @brief Round a number down to a full number.
   /// @param value Number.
   /// @return Rounded number.
   template<Floating T>
   constexpr T floor(T value)
   {
      return static_cast<T>(static_cast<long>((value < T(0) ? value - Constants<T>::round : value)));
   }

   /// @brief Round a number to a full number.
   /// @param value Number.
   /// @return Rounded number.
   template<Floating T>
   constexpr T round(T value)
   {
      return static_cast<T>(static_cast<long>(value + (value > T(0) ? T(0.5) : T(-0.5))));
   }

   /// @brief Round a number up to the given decimal places.
   /// @param value Number.
   /// @param places Decimal places.
   /// @return Rounded number.
   template<Floating T>
   constexpr T ceil(T value, size_t decimal_places)
   {
      const T multiplier {pow(T(10), decimal_places)};
      return ceil(value * multiplier) / multiplier;
   }

   /// @brief Round a number down to the given decimal places.
   /// @param value Number.
   /// @param places Decimal places.
   /// @return Rounded number.
   template<Floating T>
   constexpr T floor(T value, size_t decimal_places)
   {
      const T multiplier {pow(T(10), decimal_places)};
      return floor(value * multiplier) / multiplier;
   }

   /// @brief Round a number to the given decimal places.
   /// @param value Number.
   /// @param places Decimal places.
   /// @return Rounded number.
   template<Floating T>
   constexpr T round(T value, size_t decimal_places)
   {
      const T multiplier {pow(T(10), decimal_places)};
      return round(value * multiplier) / multiplier;
   }
}

#endif
