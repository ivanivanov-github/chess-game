#pragma once

#include "enums.h"
#include "piece.h"

class Pawn : Piece
{
public:
    explicit Pawn(const PieceColor &color);

    bool isValidMove(const Square &startSquare, const Square &endSquare) override;
};