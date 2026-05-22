#pragma once

#include "Board.h"
#include "Log.h"
#include <cstdint>
#include <memory>
#include <string>

class Player {
public:
  Player(std::string player_name);

  void addNatureToken();
  std::string getPlayerName();

  void printPlayerScore();

private:
  std::string m_player_name;
  uint8_t m_player_score = 0;
  uint8_t m_player_nature_tokens = 0;

  Board m_board;
};