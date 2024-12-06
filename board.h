#pragma once

#include <vector>
#include "square.h"
#include "enums.h"

class Board
{
public:
    explicit Board(std::vector<std::vector<Square>> &squares);

private:
    std::vector<std::vector<Square>> m_squares;
};