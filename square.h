#pragma once

#include "enums.h"
#include "piece.h"
#include "position.h"

#include <memory>

class Square
{
public:
  explicit Square(const SquareColor& color, const Position& position, Piece* piece = nullptr);

  inline SquareColor getColor() { return m_color; };
  inline Piece* getPiece() { return m_piece; };

private:
  SquareColor m_color;
  Position m_position;
  Piece* m_piece;
};