#ifndef CX_UI_ELEMENT_FUNCTIONS_HPP
#define CX_UI_ELEMENT_FUNCTIONS_HPP

#include <functional>
#include <memory>

namespace cx
{
   class UIElement;

   /// @brief Save functions between elements.
   struct Functions
   {
   private:
      /// @brief Global overridable styles.
      static std::unique_ptr<Functions> style1_t, style2_t, style3_t;
   public:

      /// @brief Called after updating the element.
      std::shared_ptr<std::function<void(UIElement&)>> func;

      /// @brief Access first style.
      /// @return First style.
      static Functions& style1()
      {
         if (!style1_t)
            style1_t = std::make_unique<Functions>();
         return *style1_t;
      }

      /// @brief Access second style.
      /// @return Second style.
      static Functions& style2()
      {
         if (!style2_t)
            style2_t = std::make_unique<Functions>();
         return *style2_t;
      }

      /// @brief Access third style.
      /// @return Third style.
      static Functions& style3()
      {
         if (!style3_t)
            style3_t = std::make_unique<Functions>();
         return *style3_t;
      }
   };
}

#endif
