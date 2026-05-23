#pragma once

#include "BiomeUtilities.h"
#include "GameState.h"
#include "Log.h"
#include "Player.h"
#include "Tile.h"
#include "WildlifeTypeUtilities.h"
#include <map>
#include <vector>

class Game {
public:
  Game(std::vector<Player> players);

  void initialize();
  void printScoreboard();

private:
  /**
   * @brief prints logs about startup configuration
   */
  void printStartupLog();

  /**
   * @brief handles the transition of the game through the various GameState
   * states
   */
  void progressGameState(GameState game_state);

  /**
   * @brief Repeatedly does the following:
   *  - Prints the scoreboard
   *  - For each player:
   *    - Offer tile + token combo
   *    - Allow player to place tile
   *    - Allow player to place token
   *    - Update player score
   *    - Replace tile + token
   */
  void enterTurnLoop();

  /**
   * @brief A vector of players in the game. Each player object has a board,
   * score, etc
   */
  std::vector<Player> m_players;

  /**
   * @brief Overall game turn counter. Increments by 1 when all players have
   * taken their individual turns in a round.
   */
  uint8_t m_current_turn = 0;

  /**
   * @brief The current state of this game instance
   */
  GameState m_current_game_state;
};