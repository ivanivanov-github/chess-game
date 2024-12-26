#pragma once

#include "enums.h"
#include "piece.h"

class Square;

class Pawn : public Piece
{
public:
  explicit Pawn(const PieceColor& color);

  bool isValidMove(const Position& startPosition, const Position& endPosition) override;
  void print() override;
};