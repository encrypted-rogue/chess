#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <optional>

class WindowManager {
 private:
  sf::RenderWindow window{sf::VideoMode{{800, 600}}, "Chess"};

 public:
	WindowManager() {
		window.setIcon(sf::Image::loadFromMemory());
	}
  sf::RenderWindow &get_window() { return window; }
};

int main() {
  WindowManager windowManager;
  while (windowManager.get_window().isOpen()) {
    while (const std::optional event{windowManager.get_window().pollEvent()}) {
      if (event->is<sf::Event::Closed>()) {
        windowManager.get_window().close();
      }
    }

    windowManager.get_window().clear(sf::Color::Cyan);

    windowManager.get_window().display();
  }
}
