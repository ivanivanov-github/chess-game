#pragma once

#include "enums.h"
#include "square.h"

#include <vector>

class Board
{
public:
  explicit Board(std::vector<std::vector<Square>>& squares);

  void print();

private:
  std::vector<std::vector<Square>> m_squares;
};