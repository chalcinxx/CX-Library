#ifndef CX_MATH_CONSTANTS_HPP
#define CX_MATH_CONSTANTS_HPP

#include "CX/Concepts.hpp"

namespace cx
{
   /// @brief Get math constants.
   template<Floating T = float>
   struct Constants
   {
      static constexpr T e             {T(2.71828182845904523536)};
      static constexpr T pi            {T(3.14159265358979323846)};
      static constexpr T two_pi        {T(2) * pi};
      static constexpr T round         {T(0.99999999999999999999)};
      static constexpr T half_pi       {pi / T(2)};
      static constexpr T quarter_pi    {pi / T(4)};
      static constexpr T one_third     {T(1) / T(3)};
      static constexpr T one_sixth     {T(1) / T(6)};
      static constexpr T one_fifteenth {T(1) / T(15)};
      static constexpr T one_twentieth {T(1) / T(120)};
      static constexpr T one_pith      {T(1) / pi};
      static constexpr T one_half_pith {T(1) / half_pi};
   };
}

#endif
