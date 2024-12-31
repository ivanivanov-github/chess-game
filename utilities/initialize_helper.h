#pragma once

#include "definitions.h"
#include "pawn.h"
#include "square.h"

#include <array>

namespace utilities
{
inline std::unique_ptr<std::array<std::array<Square, BOARD_NUM_OF_COLS>, BOARD_NUM_OF_ROWS>> initializeSquares()
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
} // namespace utilities
