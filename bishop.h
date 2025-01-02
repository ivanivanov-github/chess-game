#pragma once

#include "enums.h"
#include "piece.h"

class Square;

class Bishop : public Piece
{
public:
  explicit Bishop(const PieceColor& color);

  bool isValidMove(
    const Position& startPosition,
    const Position& endPosition,
    const std::unique_ptr<std::array<std::array<Square, BOARD_NUM_OF_COLS>, BOARD_NUM_OF_ROWS>>& squares) override;
  void print() override;
};