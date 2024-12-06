#pragma once

#include <string>
#include <stdexcept>

enum class PlayerColor
{
    white,
    black
};

enum class SquareColor
{
    white,
    black
};

inline std::string getString(const PlayerColor &playerColor)
{
    switch (playerColor)
    {
    case PlayerColor::white:
        return "white";
    case PlayerColor::black:
        return "black";
    default:
    {
        throw std::invalid_argument("Invalid value for playerColor. Should be on of the values of enum.");
    }
    }
};