#include "board.h"
#include "enums.h"
#include "game.h"
#include "utilities/definitions.h"
#include "utilities/initialize_helper.h"

#include <iostream>
#include <limits>
#include <string>

using namespace utilities;

namespace
{
uint8_t getRowOrColInput(const std::string& prompt)
{
  int num;
  while (true)
  {
    std::cout << prompt;
    std::cin >> num;
    if (num >= 0 && num < 8)
    {
      return num;
    }
    else
    {
      std::cout << "Invalid input! Please enter a value between 0 and 7." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}
} // namespace

int main()
{
  auto board = Board(initializeSquares());

  board.print();

  auto game = Game();

  while (true)
  {
    std::cout << "Current player is: " + getString(game.getCurrentPlayerColor()) << std::endl;
    uint8_t startRow = getRowOrColInput("Enter start row: ");
    uint8_t startCol = getRowOrColInput("Enter start col: ");
    uint8_t endRow = getRowOrColInput("Enter end row: ");
    uint8_t endCol = getRowOrColInput("Enter end col: ");

    board.movePiece(Position(startRow, startCol), Position(endRow, endCol), game.getCurrentPlayerColor());
    game.switchCurrentPlayer();

    std::cout << std::endl;
    board.print();
    std::cout << std::endl;
  };

  return 0;
}