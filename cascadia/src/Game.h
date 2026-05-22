#pragma once

#include "Player.h"
#include "Tile.h"
#include "Log.h"
#include <vector>
#include <map> 
#include "BiomeUtilities.h" 
#include "WildlifeTypeUtilities.h"

class Game
{
    public:
        Game(std::vector<Player> players);

        void initialize();
        void printScoreboard();

    private:
        void printStartupLog();

        std::vector<Player> m_players;

        uint8_t m_current_turn = 0;
};