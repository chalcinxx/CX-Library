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

      /// @brief Called when element is clicked on.
      std::function<void(UIElement&)> on_click = [](UIElement&){};

      /// @brief Called every frame mouse is held down on the element.
      std::function<void(UIElement&)> on_mouse_down = [](UIElement&){};

      /// @brief Called when mouse gets released on the element.
      std::function<void(UIElement&)> on_mouse_up = [](UIElement&){};

      /// @brief Called when mouse enters the element.
      std::function<void(UIElement&)> on_hover_start = [](UIElement&){};

      /// @brief Called when mouse exits the element.
      std::function<void(UIElement&)> on_hover_end = [](UIElement&){};

      /// @brief Called every frame the element is hovered on.
      std::function<void(UIElement&)> on_hovering = [](UIElement&){};

      /// @brief Called every frame the element isn't hovered on.
      std::function<void(UIElement&)> on_not_hovering = [](UIElement&){};

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
