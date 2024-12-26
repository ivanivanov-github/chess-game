#include "board.h"
#include "enums.h"
#include "game_engine.h"
#include "player.h"
#include "utilities/definitions.h"
#include "utilities/initialize_helper.h"

#include <iostream>
#include <vector>

using namespace utilities;

int main()
{
  std::string input;

  auto playerWhite = Player(PlayerColor::white);
  auto playerBlack = Player(PlayerColor::black);

  std::vector<std::vector<Square>> squares;

  initializeSquares(squares);

  auto board = Board(squares);

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