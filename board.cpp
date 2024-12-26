#include "board.h"

#include <iostream>

Board::Board(std::vector<std::vector<Square>>& squares) : m_squares(squares)
{
}

void Board::print()
{
  for (auto row : m_squares)
  {
    for (auto square : row)
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