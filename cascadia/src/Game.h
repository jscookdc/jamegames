#pragma once

#include "BiomeUtilities.h"
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
  void printStartupLog();

  std::vector<Player> m_players;

  uint8_t m_current_turn = 0;
};