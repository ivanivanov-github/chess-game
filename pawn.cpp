#include "pawn.h"

#include "square.h"

#include <iostream>

Pawn::Pawn(const PieceColor& color) : Piece(color)
{
}

bool Pawn::isValidMove(const Position& startPosition, const Position& endPosition)
{
  return true;
}

void Pawn::print()
{
  std::cout << 'P' << ((this->m_color == PieceColor::black) ? 'B' : 'W');
}
