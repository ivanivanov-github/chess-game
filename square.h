#pragma once

#include "enums.h"
#include "position.h"

class Square
{
public:
    explicit Square(const SquareColor &color, const Position &position);

private:
    SquareColor m_color;
    Position m_position;
};