
#include "Game.h"

Game::Game(std::vector<Player> players)
    : m_players(players), m_current_game_state(GameState::Initializing) {
  printStartupLog();
  initialize();
  printScoreboard();
}

void Game::printStartupLog() {
  LOG_DEBUG << "Beginning game...";
  LOG_DEBUG << "\tPlayers: " << m_players.size();
  for (auto& player : m_players) {
    LOG_DEBUG << "\t\t" << player.getPlayerName();
  }
}

void Game::printScoreboard() {
  LOG_DEBUG << "Game State: " << m_current_game_state;
  LOG_DEBUG << "Turn: " << U8(m_current_turn);
  LOG_DEBUG << "Current Standings:";
  for (auto& player : m_players) {
    player.printPlayerScore();
  }
}

void Game::progressGameState(GameState game_state) {
  LOG_DEBUG << "Progressing game state from " << m_current_game_state << " to " << game_state;

  // TODO: handle protection of entering various game states
  m_current_game_state = game_state;
}

void Game::enterTurnLoop() {
  m_current_turn++;
}

void Game::initialize() {
  LOG_DEBUG << "Initializing";
  for (int i = 0; i < int(m_players.size()); i++) {
    Biome starting_biome = BiomeUtilities::getRandomBiome();
    WildlifeType starting_wildlife_type = WildlifeTypeUtilities::getRandomWildlifeType();
    Tile origin_tile = Tile(starting_biome, starting_biome, starting_wildlife_type);
  }
  progressGameState(GameState::Ongoing);
}