#ifndef CX_TIMER_WAIT_HPP
#define CX_TIMER_WAIT_HPP

#include <thread>

namespace cx
{
   /// @brief Delay code execution.
   /// @param seconds Time in seconds.
   inline bool wait(float seconds) noexcept
   {
      std::this_thread::sleep_for(std::chrono::duration<float>(seconds));
      return true;
   }
}

#endif
