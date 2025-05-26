#include "CX/Cx.hpp"
#include "CX/Math/Angle.hpp"
using k = cx::Key;
using b = cx::Controller;
using m = cx::Mouse;

using namespace std::string_literals;

int main()
{
   sf::RenderWindow window (sf::VideoMode(960, 540), "CX Library"s);
   window.setFramerateLimit(60u);

   cx::EventHandler event (window);
   cx::AssetManager asset ("project/");
   asset.load_font_dir();
   asset.load_texture_dir();

   cx::Rect thing ({50.f}, {250.f, 70.f});

   while (window.isOpen())
   {
      event.update();

      if (event.is_down(k::e))
         thing.rotate(cx::Degrees(25).radians() * event.get_dt());
      else if (event.is_down(k::q))
         thing.rotate(-cx::Radians(20).degrees() * event.get_dt());

      window.clear();
      thing.render(window);
      window.display();
   }
}
