#include "pawn.h"

#include "square.h"

Pawn::Pawn(const PieceColor& color) : Piece(color)
{
}

bool Pawn::isValidMove(const Position& startPosition, const Position& endPosition)
{
  return true;
}
