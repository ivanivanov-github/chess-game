#include "game.h"

#include <iostream>

Game::Game()
{
}

void Game::switchCurrentPlayer()
{
  if (m_currentPlayerColor == PieceColor::white)
  {
    m_currentPlayerColor = PieceColor::black;
  }
  else
  {
    m_currentPlayerColor = PieceColor::white;
  }
}
