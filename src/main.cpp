#include "chess_black_perspective_board.h"
#include "chess_white_perspective_board.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <optional>

constexpr auto initialWindowWidth{800}, initialWindowHeight{600},
    boardDimension{512};

class windowHandlerTemplate {
private:
public:
  sf::RenderWindow window{
      sf::VideoMode{{initialWindowWidth, initialWindowHeight}}, "Chess"};
};

class assetHandlerTemplate {
private:
  sf::Texture chessBlackPerspectiveBoardTexture{chess_black_perspective_board,
                                                5231};
  sf::Texture chessWhitePerspectiveBoardTexture{chess_white_perspective_board,
                                                5233};

public:
  sf::Sprite chessBlackPerspectiveBoard{chessBlackPerspectiveBoardTexture};
  sf::Sprite chessWhitePerspectiveBoard{chessWhitePerspectiveBoardTexture};
  assetHandlerTemplate() {
    constexpr sf::Vector2<float> boardPosition{
        static_cast<float>(initialWindowWidth) / 2 -
            static_cast<float>(boardDimension) / 2,
        static_cast<float>(initialWindowHeight) / 2 -
            static_cast<float>(boardDimension) / 2};
    chessWhitePerspectiveBoard.setPosition(boardPosition);
    chessBlackPerspectiveBoard.setPosition(boardPosition);
  }
  void onResize(windowHandlerTemplate &passed) {
    const sf::Vector2<float> boardPosition{
        static_cast<float>(passed.window.getSize().x) / 2 -
            static_cast<float>(boardDimension) / 2,
        static_cast<float>(passed.window.getSize().y) / 2 -
            static_cast<float>(boardDimension) / 2};
    chessWhitePerspectiveBoard.setPosition(boardPosition);
    chessBlackPerspectiveBoard.setPosition(boardPosition);
  }
};

int main() {
  windowHandlerTemplate windowHandler;
  assetHandlerTemplate assetHandler;

  while (windowHandler.window.isOpen()) {
    while (const std::optional event{windowHandler.window.pollEvent()}) {
      if (event->is<sf::Event::Closed>()) {
        windowHandler.window.close();
      }
      if (const auto *resized = event->getIf<sf::Event::Resized>()) {
        sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));
        windowHandler.window.setView(sf::View(visibleArea));
        assetHandler.onResize(windowHandler);
      }
    }
    windowHandler.window.clear(sf::Color::Cyan);

    windowHandler.window.draw(assetHandler.chessBlackPerspectiveBoard);

    windowHandler.window.display();
  }

  return 0;
}
