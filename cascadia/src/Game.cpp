
#include "Game.h"

Game::Game(std::vector<Player> players)
: m_players(players)
{
    printStartupLog();
    printScoreboard();
}

void Game::printStartupLog()
{
    LOG_DEBUG << "Beginning game...";
    LOG_DEBUG << "\tPlayers: " << m_players.size();
    for (auto& player: m_players)
    {
        LOG_DEBUG << "\t\t" << player.getPlayerName();
    }
}

void Game::printScoreboard()
{
    LOG_DEBUG << "Turn: " << U8(m_current_turn);
    LOG_DEBUG << "Current Standings:";
    for (auto& player: m_players)
    {
        player.printPlayerScore();
    }
}

void Game::initialize()
{
    LOG_DEBUG << "Initializing";
    for (int i = 0; i < int(m_players.size()); i++)
    {
        Biome starting_biome = BiomeUtilities::getRandomBiome();
        WildlifeType starting_wildlife_type = WildlifeTypeUtilities::getRandomWildlifeType(); 
        Tile origin_tile = Tile(starting_biome, starting_biome, starting_wildlife_type);
    }
}