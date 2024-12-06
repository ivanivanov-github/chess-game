#include "pawn.h"

Pawn::Pawn(const PieceColor &color) : Piece(color)
{
}

bool Pawn::isValidMove(const Square &startSquare, const Square &endSquare)
{
    return true;
}
