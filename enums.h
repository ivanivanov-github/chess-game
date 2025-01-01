#pragma once

#include <stdexcept>
#include <string>

enum class SquareColor
{
  white,
  black
};

enum class PieceColor
{
  white,
  black
};

inline std::string getString(const PieceColor& playerColor)
{
  switch (playerColor)
  {
  case PieceColor::white:
    return "white";
  case PieceColor::black:
    return "black";
  default:
  {
    throw std::invalid_argument("Invalid value for playerColor. Should be one of the values of enum PieceColor.");
  }
  }
};