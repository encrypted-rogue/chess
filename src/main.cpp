#include "chess_black_perspective_board.h"
#include "chess_white_perspective_board.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <optional>

int main() {
  sf::RenderWindow window(sf::VideoMode({800, 600}), "Chess");

  sf::Texture chessBlackPerspectiveBoardTexture(chess_black_perspective_board,
                                                5231);
  sf::Texture chessWhitePerspectiveBoardTexture(chess_white_perspective_board,
                                                5233);
  sf::Sprite chessBlackPerspectiveBoard(chessBlackPerspectiveBoardTexture);
  sf::Sprite chessWhitePerspectiveBoard(chessWhitePerspectiveBoardTexture);

  while (window.isOpen()) {
    while (const std::optional event{window.pollEvent()}) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }
    sf::Vector2u windowCenter{window.getSize().x / 2, window.getSize().y / 2};

    window.clear(sf::Color::Cyan);

    window.draw(chessBlackPerspectiveBoard);

    window.display();
  }

  return 0;
}