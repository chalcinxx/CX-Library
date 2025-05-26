#ifndef CX_TIMER_BASIC_TIMER_HPP
#define CX_TIMER_BASIC_TIMER_HPP

#include <chrono>

namespace cx
{
   /// @brief Measure time.
   class BasicTimer
   {
   public:
      // Constructors

      /// @brief Start the timer.
      inline BasicTimer() noexcept
      {
         start = Clock::now();
      }

      /// @brief Start the timer at the given time.
      /// @param seconds Time in seconds.
      inline BasicTimer(float seconds) noexcept
      {
         const Duration duration(seconds);
         start = Clock::now() - std::chrono::duration_cast<Clock::duration>(duration);
      }

      ~BasicTimer() = default;

      // Time functions

      /// @brief Reset timer.
      inline void reset() noexcept
      {
         start = Clock::now();
      }

      /// @brief Get total elapsed time and reset timer.
      /// @return Time in seconds.
      inline float restart() noexcept
      {
         const auto now = Clock::now();
         const float elapsed = Duration(now - start).count();

         start = std::move(now);
         return elapsed;
      }

      /// @brief Get total elapsed time.
      /// @return Time in seconds.
      inline float get_elapsed() const noexcept
      {
         return Duration(Clock::now() - start).count();
      }

      /// @brief Set elapsed time.
      /// @param seconds Time in seconds.
      inline void set_elapsed(float seconds) noexcept
      {
         const Duration duration(seconds);
         start = Clock::now() - std::chrono::duration_cast<Clock::duration>(duration);
      }

   private:
      using Clock = std::chrono::steady_clock;
      using TimePoint = std::chrono::time_point<Clock>;
      using Duration = std::chrono::duration<float>;

      TimePoint start;
   };
}

#endif
