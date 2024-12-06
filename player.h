#pragma once

#include "enums.h"

class Player
{
public:
    explicit Player(const PlayerColor &playerColor);

private:
    PlayerColor m_playerColor;
};