#include "pawn.h"

#include "square.h"

#include <cstdlib>
#include <iostream>

Pawn::Pawn(const PieceColor& color) : Piece(color)
{
}

bool Pawn::isValidMove(
  const Position& startPosition,
  const Position& endPosition,
  const std::unique_ptr<std::array<std::array<Square, BOARD_NUM_OF_COLS>, BOARD_NUM_OF_ROWS>>& squares)
{
  if (squares == nullptr)
  {
    return false;
  }

  int8_t direction = (m_color == PieceColor::white) ? -1 : 1;

  // Pawn moves one square forward
  if (endPosition.row == startPosition.row + direction && startPosition.col == endPosition.col)
  {
    if ((*squares)[endPosition.row][endPosition.col].getPiece() == nullptr)
    {
      return true;
    }
    return false;
  }

  // Pawn moves two squares forward from its starting position
  if (endPosition.row == startPosition.row + 2 * direction && startPosition.col == endPosition.col)
  {
    if ((m_color == PieceColor::white && startPosition.row == 6) ||
        (m_color == PieceColor::black && startPosition.row == 1))
    {
      if ((*squares)[endPosition.row][endPosition.col].getPiece() == nullptr)
      {
        return true;
      }
      return false;
    }
  }

  // Pawn captures diagonally
  if ((abs(startPosition.col - endPosition.col) == 1) && (endPosition.row == startPosition.row + direction))
  {
    auto& endSquare = (*squares)[endPosition.row][endPosition.col];
    if (endSquare.getPiece() != nullptr && m_color != endSquare.getPiece()->getColor())
    {
      return true;
    }
  }

  return false;
}

void Pawn::print()
{
  std::cout << 'P' << ((this->m_color == PieceColor::black) ? 'B' : 'W');
}
