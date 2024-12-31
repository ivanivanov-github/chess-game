#include "square.h"

Square::Square(const SquareColor& color, const Position& position, Piece* piece) :
  m_color(color),
  m_position(position),
  m_piece(piece)
{
}

Square::Square(Square&& other) : m_color(other.m_color), m_position(other.m_position), m_piece(other.m_piece)
{
  if (this == &other)
  {
    return;
  }

  delete m_piece;

  m_piece = other.m_piece;
  other.m_piece = nullptr;
  m_position = other.m_position;
  m_color = other.m_color;
}

Square& Square::operator=(Square& other)
{
  if (this == &other)
  {
    return *this;
  }

  delete m_piece;

  m_piece = other.m_piece;
  other.m_piece = nullptr;
  m_position = other.m_position;
  m_color = other.m_color;
}

Square::~Square()
{
  if (m_piece != nullptr)
  {
    delete m_piece;
    m_piece = nullptr;
  }
}

void Square::movePiece(Square& startSquare)
{
  if (startSquare.getPiece() == nullptr)
  {
    return;
  }

  if (m_piece != nullptr)
  {
    delete m_piece;
  }

  m_piece = startSquare.getPiece();
  startSquare.m_piece = nullptr;
}