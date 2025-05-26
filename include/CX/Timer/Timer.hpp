#ifndef CX_TIMER_TIMER_HPP
#define CX_TIMER_TIMER_HPP

#include <chrono>

namespace cx
{
   /// @brief Pause and measure time.
   class Timer
   {
   public:
      // Constructors

      /// @brief Start the timer.
      inline Timer() noexcept
      {
         start = Clock::now();
      }

      /// @brief Start the timer at the given time.
      /// @param seconds Time in seconds.
      inline Timer(float seconds) noexcept
      {
         elapsed = seconds;
         start = Clock::now();
      }

      ~Timer() = default;

      // Time functions

      /// @brief Reset timer.
      inline void reset() noexcept
      {
         paused = false;
         elapsed = 0.f;
         start = Clock::now();
      }

      /// @brief Get total elapsed time and reset timer.
      /// @return Time in seconds.
      inline float restart() noexcept
      {
         const auto now = Clock::now();
         const float total = elapsed + (paused ? 0.f : Duration(now - start).count());

         paused = false;
         elapsed = 0.f;
         start = std::move(now);

         return total;
      }

      /// @brief Get total elapsed time.
      /// @return Time in seconds.
      inline float get_elapsed() const noexcept
      {
         return elapsed + (paused ? 0.f : Duration(Clock::now() - start).count());
      }

      /// @brief Set elapsed time.
      /// @param seconds Time in seconds.
      inline void set_elapsed(float seconds) noexcept
      {
         elapsed = seconds;
         start = Clock::now();
      }

      // Pause functions

      /// @brief Set timer paused.
      /// @param is_paused Should timer be paused.
      inline void set_paused(bool is_paused) noexcept
      {
         if (is_paused && !paused)
            elapsed += Duration(Clock::now() - start).count();
         else if (!is_paused && paused)
            start = Clock::now();
         
         paused = is_paused;
      }

      /// @brief Toggle timer paused.
      inline void toggle_paused() noexcept
      {
         if (paused)
            start = Clock::now();
         else
            elapsed += Duration(Clock::now() - start).count();

         paused = !paused;
      }

      /// @brief Pause the timer.
      inline void pause() noexcept
      {
         if (!paused)
         {
            paused = true;
            elapsed += Duration(Clock::now() - start).count();
         }
      }

      /// @brief Resume the timer.
      inline void resume() noexcept
      {
         if (paused)
         {
            paused = false;
            start = Clock::now();
         }
      }

      /// @brief Check if timer is paused.
      /// @return True if paused.
      inline bool is_paused() const noexcept
      {
         return paused;
      }

   protected:
      using Clock = std::chrono::steady_clock;
      using TimePoint = std::chrono::time_point<Clock>;
      using Duration = std::chrono::duration<float>;

      TimePoint start;
      float elapsed = 0.f;
      bool paused = false;
   };
}

#endif
