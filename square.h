#pragma once

#include "enums.h"
#include "piece.h"

#include <memory>

struct Position;

class Square
{
public:
  Square() = default;
  explicit Square(const SquareColor& color, const Position& position, Piece* piece = nullptr);
  Square(Square&& other);
  Square& operator=(Square&& other);
  ~Square();

  void movePiece(Square& startSquare);

  inline SquareColor getColor() { return m_color; };
  inline Piece*& getPiece() { return m_piece; };

private:
  SquareColor m_color = SquareColor::black;
  Position m_position = Position(0, 0);
  Piece* m_piece = nullptr;
};