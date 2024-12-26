#pragma once

#include "enums.h"
#include "position.h"

class Piece
{
public:
  explicit Piece(const PieceColor& color) : m_color(color) {};

  virtual bool isValidMove(const Position& startPosition, const Position& endPosition) = 0;
  virtual void print() = 0;

protected:
  PieceColor m_color;
};