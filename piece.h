#pragma once

#include "enums.h"
#include "position.h"
#include "utilities/definitions.h"

#include <array>
#include <memory>

using namespace utilities;

class Square;
class Piece
{
public:
  explicit Piece(const PieceColor& color) : m_color(color) {};

  virtual bool isValidMove(
    const Position& startPosition,
    const Position& endPosition,
    const std::unique_ptr<std::array<std::array<Square, BOARD_NUM_OF_COLS>, BOARD_NUM_OF_ROWS>>& squares) = 0;
  virtual void print() = 0;
  PieceColor getColor() { return m_color; };

protected:
  PieceColor m_color;
};