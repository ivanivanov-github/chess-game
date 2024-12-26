#pragma once

#include "enums.h"
#include "piece.h"
#include "position.h"

#include <memory>

class Square
{
public:
  explicit Square(const SquareColor& color, const Position& position, Piece* piece = nullptr);

private:
  SquareColor m_color;
  Position m_position;
  Piece* m_piece;
};