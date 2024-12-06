#pragma once

#include <cstdint>
#include <stdexcept>

struct Position
{
    Position(uint8_t r, uint8_t c)
    {
        if (r > 8 || c > 8)
        {
            throw std::out_of_range("Row and column values must be between 0 and 8.");
        }
        row = r;
        col = c;
    };

    uint8_t row;
    uint8_t col;
};