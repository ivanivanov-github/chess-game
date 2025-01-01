#include "board.h"
#include "enums.h"
#include "game.h"
#include "utilities/definitions.h"

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

std::unique_ptr<std::array<std::array<Square, BOARD_NUM_OF_COLS>, BOARD_NUM_OF_ROWS>> initializeSquares()
{
  std::unique_ptr<std::array<std::array<Square, BOARD_NUM_OF_COLS>, BOARD_NUM_OF_ROWS>> squares =
    std::make_unique<std::array<std::array<Square, BOARD_NUM_OF_COLS>, BOARD_NUM_OF_ROWS>>();

  for (uint8_t i = 0; i < BOARD_NUM_OF_ROWS; i++)
  {
    for (uint8_t j = 0; j < BOARD_NUM_OF_COLS; j++)
    {
      if (i % 2 == 0)
      {
        if (i == 6)
        {
          (*squares)[i][j] = Square((j % 2 == 0) ? SquareColor::white : SquareColor::black,
                                    Position(i, j),
                                    new Pawn(PieceColor::white));
        }
        else
        {
          (*squares)[i][j] = Square((j % 2 == 0) ? SquareColor::white : SquareColor::black, Position(i, j));
        }
      }
      else
      {
        // second row top down (black pawns)
        if (i == 1)
        {
          (*squares)[i][j] = Square((j % 2 != 0) ? SquareColor::white : SquareColor::black,
                                    Position(i, j),
                                    new Pawn(PieceColor::black));
        }
        else
        {
          (*squares)[i][j] = Square((j % 2 != 0) ? SquareColor::white : SquareColor::black, Position(i, j));
        }
      }
    }
  }
  return squares;
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