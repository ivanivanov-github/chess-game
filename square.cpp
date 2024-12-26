#include "square.h"

Square::Square(const SquareColor& color, const Position& position, Piece* piece) :
  m_color(color),
  m_position(position),
  m_piece(std::move(piece))
{
}