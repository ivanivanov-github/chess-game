#include "rook.h"

#include "position.h"
#include "square.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

Rook::Rook(const PieceColor& color) : Piece(color)
{
}

bool Rook::isValidMove(
  const Position& startPosition,
  const Position& endPosition,
  const std::unique_ptr<std::array<std::array<Square, BOARD_NUM_OF_COLS>, BOARD_NUM_OF_ROWS>>& squares)
{
  if (squares == nullptr)
  {
    return false;
  }

  // Check if the move is either vertical or horizontal
  if (startPosition.row != endPosition.row || startPosition.col != endPosition.col)
  {
    return false;
  }

  // Check the path is clear
  if (startPosition.row == endPosition.row)
  {
    uint8_t colMin = std::min(startPosition.col, endPosition.col) + 1;
    uint8_t colMax = std::min(startPosition.col, endPosition.col);
    for (uint8_t& col = colMin; col <= colMax; col++)
    {
      if ((*squares)[startPosition.row][col].getPiece() != nullptr)
      {
        return false;
      }
    }
  }
  else if (startPosition.col == endPosition.col)
  {
    uint8_t rowMin = std::min(startPosition.row, endPosition.row) + 1;
    uint8_t rowMax = std::min(startPosition.row, endPosition.row);
    for (uint8_t& row = rowMin; row <= rowMax; row++)
    {
      if ((*squares)[startPosition.row][row].getPiece() != nullptr)
      {
        return false;
      }
    }
  }

  // Check the end square
  auto& endPiece = (*squares)[endPosition.row][endPosition.col].getPiece();
  if (endPiece == nullptr || endPiece->getColor() != m_color)
  {
    return true;
  }

  return false;
}

void Rook::print()
{
  std::cout << 'R' << ((this->m_color == PieceColor::black) ? 'B' : 'W');
}
