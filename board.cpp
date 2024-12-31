#include "board.h"

#include <iostream>

Board::Board(std::unique_ptr<std::array<std::array<Square, BOARD_NUM_OF_COLS>, BOARD_NUM_OF_ROWS>> squares) :
  m_squares(std::move(squares))
{
}

void Board::movePiece(const Position& startPosition, const Position& endPosition)
{
  if (startPosition == endPosition)
  {
    return;
  }

  Square& startSquare = (*m_squares)[startPosition.row][startPosition.col];
  if (startSquare.getPiece() == nullptr)
  {
    return;
  }

  Square& endSquare = (*m_squares)[endPosition.row][endPosition.col];
  if (endSquare.getPiece() != nullptr)
  {
    return;
  }

  Piece* piece = startSquare.getPiece();
  if (!piece->isValidMove(startPosition, endPosition))
  {
    return;
  }

  endSquare.placePiece(startSquare);
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
        std::cout << ((square.getColor() == SquareColor::black) ? 0 : 1) << ' ';
      }
    }
    std::cout << std::endl;
  }
}