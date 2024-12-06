#include <iostream>
#include <vector>

#include "game_engine.h"
#include "player.h"
#include "enums.h"
#include "board.h"

namespace
{
    constexpr uint8_t BOARD_NUM_OF_ROWS = 8;
    constexpr uint8_t BOARD_NUM_OF_COLS = 8;
}

int main()
{
    std::string input;

    auto playerWhite = Player(PlayerColor::white);
    auto playerBlack = Player(PlayerColor::black);

    std::vector<std::vector<Square>> squares;

    for (uint8_t i = 0; i < BOARD_NUM_OF_ROWS; i++)
    {
        std::vector<Square> row;
        for (uint8_t j = 0; j < BOARD_NUM_OF_COLS; j++)
        {
            if (i % 2 == 0)
            {
                row.emplace_back((j % 2 == 0) ? Square(SquareColor::white) : Square(SquareColor::black));
            }
            else
            {
                row.emplace_back((j % 2 != 0) ? Square(SquareColor::white) : Square(SquareColor::black));
            }
        }
        squares.emplace_back(row);
    }

    auto board = Board(squares);

    auto gameEngine = GameEngine();

    while (true)
    {

        std::cout << "Current player is: " + getString(gameEngine.currentPlayerColor) << std::endl;
        std::cout << "Press enter to pass turn." << std::endl;
        std::getline(std::cin, input);

        if (input.empty())
        {
            if (gameEngine.currentPlayerColor == PlayerColor::white)
            {
                gameEngine.currentPlayerColor = PlayerColor::black;
            }
            else
            {
                gameEngine.currentPlayerColor = PlayerColor::white;
            }
        }
    };

    return 0;
}