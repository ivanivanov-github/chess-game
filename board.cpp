#include "board.h"

#include <iostream>

Board::Board(std::unique_ptr<std::array<std::array<Square, BOARD_NUM_OF_COLS>, BOARD_NUM_OF_ROWS>> squares) :
  m_squares(std::move(squares))
{
}

void Board::movePiece(const Position& startPosition, const Position& endPosition, const PieceColor& currentPlayerColor)
{
  if (startPosition == endPosition)
  {
    return;
  }

  Square& startSquare = (*m_squares)[startPosition.row][startPosition.col];
  if (startSquare.getPiece() == nullptr)
  {
    std::cout << "Cannot move piece from a square with no piece.";
    return;
  }

  if (startSquare.getPiece()->getColor() != currentPlayerColor)
  {
    std::cout << "Cannot move opponent's piece.";
    return;
  }

  if (!startSquare.getPiece()->isValidMove(startPosition, endPosition, m_squares))
  {
    return;
  }

  Square& endSquare = (*m_squares)[endPosition.row][endPosition.col];
  if (endSquare.getPiece() != nullptr && endSquare.getPiece()->getColor() == currentPlayerColor)
  {
    std::cout << "Cannot move your piece to a square already occupied by one of your own pieces.";
    return;
  }

  (*m_squares)[endPosition.row][endPosition.col].movePiece(startSquare);
}

void Board::print()
{
  for (auto& row : (*m_squares))
  {
    for (auto& square : row)
    {
      if (square.getPiece())
      {
        square.getPiece()->print();
        std::cout << ' ';
      }
      else
      {
        std::cout << ((square.getColor() == SquareColor::black) ? 0 : 1) << "  ";
      }
    }
    std::cout << std::endl;
  }
}