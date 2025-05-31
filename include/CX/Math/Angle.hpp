#ifndef CX_MATH_ANGLE_HPP
#define CX_MATH_ANGLE_HPP

namespace cx
{
   /// @brief Angle struct for handling degrees and radians.
   struct Angle
   {
   public:
      /// @brief Create a default angle.
      constexpr Angle() = default;
      virtual ~Angle() = default;

      /// @brief Convert the angle to degrees.
      /// @return Angle in degrees.
      virtual constexpr float degrees() const = 0;

      /// @brief Convert the angle to radians.
      /// @return Angle in radians.
      virtual constexpr float radians() const = 0;

      /// @brief Get the angle.
      /// @return Angle.
      virtual constexpr operator float() const = 0;

      /// @brief Get the angle.
      /// @return Angle.
      virtual constexpr operator float&() = 0;

   protected:
      /// @brief The constant PI.
      static constexpr float pi = 3.14159265358979323846f;

      /// @brief Constant used in degree to radian conversion.
      static constexpr float radian_conversion_constant = pi / 180.f;

      /// @brief Constant used in radian to degree conversion.
      static constexpr float degree_conversion_constant = 180.f / pi;
   };

   /// @brief Angle struct in degrees.
   struct Deg : public Angle
   {
   public:

      /// @brief Create default angle.'
      constexpr Deg() = default;

      /// @brief Create an angle.
      /// @param angle Angle in degrees.
      constexpr Deg(float angle)
         : angle(angle) {}

      /// @brief Create an angle.
      /// @param angle Angle.
      constexpr Deg(const Angle& angle)
         : angle(angle.degrees()) {}

      /// @brief Convert the given angle in radians to degrees.
      /// @param radians Angle in radians.
      /// @return Angle in degrees.
      constexpr static float convert(float radians)
      {
         return radians * degree_conversion_constant;
      }

      /// @brief Convert the angle to degrees.
      /// @return Angle in degrees.
      constexpr float degrees() const override
      {
         return angle;
      }

      /// @brief Convert the angle to radians.
      /// @return Angle in radians.
      constexpr float radians() const override
      {
         return angle * radian_conversion_constant;
      }

      /// @brief Get the angle.
      /// @return Angle.
      constexpr operator float() const override
      {
         return angle;
      }

      /// @brief Get the angle.
      /// @return Angle.
      constexpr operator float&() override
      {
         return angle;
      }

      /// @brief Assign a new angle.
      /// @param new_angle New angle.
      /// @return New angle.
      constexpr float& operator=(float new_angle)
      {
         angle = new_angle;
         return angle;
      }

      /// @brief Assign a new angle.
      /// @param new_angle New angle.
      /// @return New angle.
      constexpr float& operator=(const Angle& new_angle)
      {
         angle = new_angle.degrees();
         return angle;
      }

   private:

      float angle = 0.f;
   };

   /// @brief Angle struct in radians.
   struct Rad : public Angle
   {
   public:

      /// @brief Create default angle.
      constexpr Rad() = default;

      /// @brief Create an angle.
      /// @param angle Angle in radians.
      constexpr Rad(float angle)
         : angle(angle) {}
      
      /// @brief Create an angle.
      /// @param angle Angle.
      constexpr Rad(const Angle& angle)
         : angle(angle.radians()) {}

      /// @brief Convert the given angle in degrees to radians.
      /// @param degrees Angle in degrees.
      /// @return Angle in radians.
      constexpr static float convert(float degrees)
      {
         return degrees * radian_conversion_constant;
      }

      /// @brief Convert the angle to degrees.
      /// @return Angle in degrees.
      constexpr float degrees() const override
      {
         return angle * degree_conversion_constant;
      }

      /// @brief Convert the angle to radians.
      /// @return Angle in radians.
      constexpr float radians() const override
      {
         return angle;
      }

      /// @brief Get the angle.
      /// @return Angle.
      constexpr operator float() const override
      {
         return angle;
      }

      /// @brief Get the angle.
      /// @return Angle.
      constexpr operator float&() override
      {
         return angle;
      }

      /// @brief Assign a new angle.
      /// @param new_angle New angle.
      /// @return New angle.
      constexpr float& operator=(float new_angle)
      {
         angle = new_angle;
         return angle;
      }

      /// @brief Assign a new angle.
      /// @param new_angle New angle.
      /// @return New angle.
      constexpr float& operator=(const Angle& new_angle)
      {
         angle = new_angle.radians();
         return angle;
      }

   private:
      float angle = 0.f;
   };
}

#endif
