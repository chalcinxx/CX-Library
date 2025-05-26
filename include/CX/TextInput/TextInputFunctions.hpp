#ifndef CX_TEXTINPUT_TEXTINPUT_FUNCTIONS_HPP
#define CX_TEXTINPUT_TEXTINPUT_FUNCTIONS_HPP

#include "CX/UIElement/UIElement.hpp"

namespace cx
{
   /// @brief Save functions between text inputs.
   struct TextInputFunctions
   {
   private:
      /// @brief Global overridable styles.
      static std::unique_ptr<TextInputFunctions> style1_t, style2_t, style3_t;
   public:

      /// @brief Called when user selects input.
      std::function<void(UIElement&)> on_active_start = [](UIElement&){};

      /// @brief Called when user unselects input.
      std::function<void(UIElement&)> on_active_end = [](UIElement&){};

      /// @brief Called every frame the input is active.
      std::function<void(UIElement&)> on_active = [](UIElement&){};

      /// @brief Called every frame the input is not active.
      std::function<void(UIElement&)> on_not_active = [](UIElement&){};

      /// @brief Access first style.
      /// @return First style.
      static TextInputFunctions& style1()
      {
         if (!style1_t)
            style1_t = std::make_unique<TextInputFunctions>();
         return *style1_t;
      }

      /// @brief Access second style.
      /// @return Second style.
      static TextInputFunctions& style2()
      {
         if (!style2_t)
            style2_t = std::make_unique<TextInputFunctions>();
         return *style2_t;
      }

      /// @brief Access third style.
      /// @return Third style.
      static TextInputFunctions& style3()
      {
         if (!style3_t)
            style3_t = std::make_unique<TextInputFunctions>();
         return *style3_t;
      }
   };
}

#endif
