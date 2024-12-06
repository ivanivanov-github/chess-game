#include <iostream>

#include "game_engine.h"
#include "player.h"
#include "enums.h"

int main()
{
    std::string input;

    auto playerWhite = Player(PlayerColor::white);
    auto playerBlack = Player(PlayerColor::black);

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