#ifndef CX_CONCEPTS_HPP
#define CX_CONCEPTS_HPP

#include <concepts>

namespace cx
{
   template<typename T>
   concept Integral = std::integral<T>;

   template<typename T>
   concept SignedIntegral = std::signed_integral<T>;

   template<typename T>
   concept UnsignedIntegral = std::unsigned_integral<T>;

   template<typename T>
   concept Floating = std::floating_point<T>;

   template<typename T>
   concept Number = Integral<T> || Floating<T>;

   template<typename T>
   concept SignedNumber = SignedIntegral<T> || Floating<T>;
}

#endif
