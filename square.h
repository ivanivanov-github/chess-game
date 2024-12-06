#pragma once

#include "enums.h"

class Square
{
public:
    explicit Square(const SquareColor &color);

private:
    SquareColor m_color;
};