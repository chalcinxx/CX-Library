#ifndef CX_MATH_RANDOM_HPP
#define CX_MATH_RANDOM_HPP

#include "CX/Concepts.hpp"
#include <random>

namespace cx
{
   /// @brief Seed the current time.
   inline void seed_random()
   {
      srand(time(nullptr));
   }
   
   /// @brief Seed the random.
   /// @param seed Seed.
   inline void seed(uint32_t seed)
   {
      srand(seed);
   }

   /// @brief Generate a random integer. Requires to be seeded.
   /// @param min Minimum value.
   /// @param max Maximum value.
   /// @return Randomly generated integer.
   template<Integral T = int>
   inline T randi(T min = T(0), T max = T(1))
   {
      return min + (rand() % (max - min + 1));
   }

   /// @brief Generate a random float. Requires to be seeded.
   /// @param min Minimum value.
   /// @param max Maximum value.
   /// @return Randomly generated float.
   template<Floating T = float>
   inline T randf(T min = T(0), T max = T(1))
   {
      return min + static_cast<T>(rand()) / static_cast<T>(RAND_MAX / (max - min));
   }

   /// @brief Generate a random boolean. Requires to be seeded.
   /// @return Randomly generated boolean.
   inline bool randb()
   {
      return static_cast<bool>(rand() % 2);
   }

   /// @brief Generate a random integer. Unseeded.
   /// @param min Minimum value.
   /// @param max Maximum value.
   /// @return Randomly generated integer.
   template<Integral T = int>
   inline T randiu(T min = T(0), T max = T(1))
   {
      static thread_local std::random_device rd;
      static thread_local std::mt19937 generator(rd());
      std::uniform_int_distribution<T> dist(min, max);
      return dist(generator);
   }

   /// @brief Generate a random float. Unseeded.
   /// @param min Minimum value.
   /// @param max Maximum value.
   /// @return Randomly generated float.
   template<Floating T = float>
   inline T randfu(T min = T(0), T max = T(1))
   {
      static thread_local std::random_device rd;
      static thread_local std::mt19937 generator(rd());
      std::uniform_real_distribution<T> dist(min, max);
      return dist(generator);
   }

   /// @brief Generate a random boolean. Unseeded.
   /// @return Randomly generated boolean.
   inline bool randbu()
   {
      static thread_local std::random_device rd;
      static thread_local std::mt19937 generator(rd());
      std::uniform_int_distribution<uint8_t> dist(0, 1);
      return static_cast<bool>(dist(generator));
   }

   /// @brief Generate a random number. Unseeded.
   /// @param min Minimum value.
   /// @param max Maximum value.
   /// @return Randomly generated number.
   template<Floating T = float>
   inline T random(T min = T(0), T max = T(1))
   {
      static thread_local std::random_device rd;
      static thread_local std::mt19937 generator(rd());
      std::uniform_real_distribution<T> dist(min, max);
      return dist(generator);
   }

   /// @brief Generate a random number. Unseeded.
   /// @param min Minimum value.
   /// @param max Maximum value.
   /// @return Randomly generated number.
   template<Integral T = int>
   inline T random(T min = T(0), T max = T(1))
   {
      static thread_local std::random_device rd;
      static thread_local std::mt19937 generator(rd());
      std::uniform_int_distribution<T> dist(min, max);
      return dist(generator);
   }
}

#endif
