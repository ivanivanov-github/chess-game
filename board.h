#pragma once

#include "enums.h"
#include "square.h"
#include "utilities/definitions.h"

#include <array>

using namespace utilities;

class Board
{
public:
  explicit Board(std::unique_ptr<std::array<std::array<Square, BOARD_NUM_OF_COLS>, BOARD_NUM_OF_ROWS>> squares);

  void movePiece(const Position& startPosition, const Position& endPosition, const PieceColor& currentPlayerColor);

  void print();

private:
  const std::unique_ptr<std::array<std::array<Square, BOARD_NUM_OF_COLS>, BOARD_NUM_OF_ROWS>> m_squares;
};