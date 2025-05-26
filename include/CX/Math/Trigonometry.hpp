#ifndef CX_MATH_TRIGONOMETRY_HPP
#define CX_MATH_TRIGONOMETRY_HPP

#include "CX/Math/Constants.hpp"

namespace cx
{
   /// @brief Approximate sine of the angle.
   /// @param x Angle in radians.
   /// @return Sine of the angle.
   /// @warning Not suitable for high-precision calculations.
   template<Floating T>
   constexpr T sin(T x)
   {
      constexpr T one_sixth = Constants<T>::one_sixth;
      constexpr T one_twentieth = Constants<T>::one_twentieth;
      constexpr T half_pi = Constants<T>::half_pi;
      constexpr T one_half_pith = Constants<T>::one_half_pith;

      const int k = static_cast<int>(floor(x * one_half_pith));
      const T y = x - k * half_pi;

      switch ((k < T(0) ? -k : k) % 4)
      {
      case 0:
      {
         const T y2 = y * y;
         return y - (y2 * y) * one_sixth + (y2 * y2 * y) * one_twentieth;
      }
      case 1:
      {
         const T v = half_pi - y;
         const T v2 = v * v;
         return v - (v2 * v) * one_sixth + (v2 * v2 * v) * one_twentieth;
      }
      case 2:
      {
         const T y2 = y * y;
         return -(y - (y2 * y) * one_sixth + (y2 * y2 * y) * one_twentieth);
      }
      case 3:
      {
         const T v = half_pi - y;
         const T v2 = v * v;
         return -(v - (v2 * v) * one_sixth + (v2 * v2 * v) * one_twentieth);
      }
      default: return T(0);
      }
   }

   /// @brief Approximate cosine of the angle.
   /// @param x Angle in radians.
   /// @return Cosine of the angle.
   /// @warning Not suitable for high-precision calculations.
   template<Floating T>
   constexpr T cos(T x)
   {
      constexpr T one_sixth = Constants<T>::one_sixth;
      constexpr T one_twentieth = Constants<T>::one_twentieth;
      constexpr T half_pi = Constants<T>::half_pi;
      constexpr T one_half_pith = Constants<T>::one_half_pith;

      x += half_pi;
      const int k = static_cast<int>(floor(x * one_half_pith));
      const T y = x - k * half_pi;

      switch ((k < T(0) ? -k : k) % 4)
      {
      case 0:
      {
         const T y2 = y * y;
         return y - (y2 * y) * one_sixth + (y2 * y2 * y) * one_twentieth;
      }
      case 1:
      {
         const T v = half_pi - y;
         const T v2 = v * v;
         return v - (v2 * v) * one_sixth + (v2 * v2 * v) * one_twentieth;
      }
      case 2:
      {
         const T y2 = y * y;
         return -(y - (y2 * y) * one_sixth + (y2 * y2 * y) * one_twentieth);
      }
      case 3:
      {
         const T v = half_pi - y;
         const T v2 = v * v;
         return -(v - (v2 * v) * one_sixth + (v2 * v2 * v) * one_twentieth);
      }
      default: return T(0);
      }
   }

   /// @brief Approximate tangent of the angle.
   /// @param x Angle in radians.
   /// @return Tangent of the angle.
   /// @warning Not suitable for high-precision calculations.
   template<Floating T>
   constexpr T tan(T x)
   {
      constexpr T pi = Constants<T>::pi;
      constexpr T half_pi = Constants<T>::half_pi;
      constexpr T quarter_pi = Constants<T>::quarter_pi;
      constexpr T one_pith = Constants<T>::one_pith;
      constexpr T one_third = Constants<T>::one_third;
      constexpr T one_fifteenth = Constants<T>::one_fifteenth;

      x -= pi * floor((x + half_pi) * one_pith);

      const bool negative = (x < T(0));
      x = (negative ? -x : x);
      const bool flip = (x > quarter_pi);
      x = (flip ? half_pi - x : x);

      const T x2 = x * x;
      T result = x * (1 + x2 * one_third + (2 * x2 * x2) * one_fifteenth);

      result = (flip ? 1 / result : result);
      return (negative ? -result : result);
   }
}

#endif
