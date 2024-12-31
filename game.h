#pragma once

#include "enums.h"
#include "position.h"

class Game
{
public:
  explicit Game();
  void switchCurrentPlayer();
  inline PieceColor getCurrentPlayerColor() { return m_currentPlayerColor; };

private:
  PieceColor m_currentPlayerColor = PieceColor::white;
};