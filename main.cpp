#include "board.h"
#include "enums.h"
#include "game_engine.h"
#include "player.h"
#include "utilities/definitions.h"
#include "utilities/initialize_helper.h"

#include <array>
#include <iostream>

using namespace utilities;

int main()
{
  std::string input;

  auto playerWhite = Player(PlayerColor::white);
  auto playerBlack = Player(PlayerColor::black);

  auto board = Board(initializeSquares());

  board.movePiece(Position(1, 0), Position(2, 0));

  board.print();

  auto gameEngine = GameEngine();

  while (true)
  {
    std::cout << "Current player is: " + getString(gameEngine.currentPlayerColor) << std::endl;
    std::cout << "Press enter to pass turn." << std::endl;
    std::getline(std::cin, input);

    if (input.empty())
    {
      if (gameEngine.currentPlayerColor == PlayerColor::white)
      {
        gameEngine.currentPlayerColor = PlayerColor::black;
      }
      else
      {
        gameEngine.currentPlayerColor = PlayerColor::white;
      }
    }
  };

  return 0;
}