#pragma once

#include "definitions.h"
#include "square.h"

#include <vector>

namespace utilities
{
inline void initializeSquares(std::vector<std::vector<Square>>& squares)
{
  for (uint8_t i = 0; i < BOARD_NUM_OF_ROWS; i++)
  {
    std::vector<Square> row;
    for (uint8_t j = 0; j < BOARD_NUM_OF_COLS; j++)
    {
      if (i % 2 == 0)
      {
        row.emplace_back((j % 2 == 0) ? SquareColor::white : SquareColor::black, Position(i, j));
      }
      else
      {
        row.emplace_back((j % 2 == 0) ? SquareColor::white : SquareColor::black, Position(i, j));
      }
    }
    squares.emplace_back(row);
  }
}
} // namespace utilities
