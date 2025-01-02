#include "bishop.h"

#include "position.h"
#include "square.h"

#include <cstdlib>
#include <iostream>
#include <vector>

Bishop::Bishop(const PieceColor& color) : Piece(color)
{
}

bool Bishop::isValidMove(
  const Position& startPosition,
  const Position& endPosition,
  const std::unique_ptr<std::array<std::array<Square, BOARD_NUM_OF_COLS>, BOARD_NUM_OF_ROWS>>& squares)
{
  if (squares == nullptr)
  {
    return false;
  }

  // Check if the destination is diagonally reachable
  if (abs(startPosition.row - endPosition.row) != abs(startPosition.col - endPosition.col))
  {
    return false;
  }

  // Determine the direction of the diagonal movement
  int8_t rowDirection = (endPosition.row > startPosition.row) ? 1 : -1;
  int8_t colDirection = (endPosition.col > startPosition.col) ? 1 : -1;

  // Check the path is clear (no pieces blocking the move)
  uint8_t currentRow = startPosition.row + rowDirection;
  uint8_t currentCol = startPosition.col + colDirection;
  while (currentRow != endPosition.row)
  {
    if ((*squares)[currentRow][currentCol].getPiece() != nullptr)
    {
      return false;
    }
    currentRow += rowDirection;
    currentCol += colDirection;
  }

  // Check if the end square is empty or has an opponent's piece
  auto& endPiece = (*squares)[endPosition.row][endPosition.col].getPiece();
  if (endPiece == nullptr || endPiece->getColor() != m_color)
  {
    return true;
  }

  return false;
}

void Bishop::print()
{
  std::cout << 'B' << ((this->m_color == PieceColor::black) ? 'B' : 'W');
}
