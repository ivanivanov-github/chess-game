#pragma once

#include "enums.h"
#include "square.h"

class Piece
{
public:
    explicit Piece(const PieceColor &color) : m_color(color) {};

    virtual bool isValidMove(const Square &startSquare, const Square &endSquare) = 0;

protected:
    PieceColor m_color;
};