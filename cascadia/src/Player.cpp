#include "Player.h"

Player::Player(std::string player_name) : m_player_name(player_name) {
  m_board = Board();
}

void Player::addNatureToken() { m_player_nature_tokens++; }

std::string Player::getPlayerName() { return m_player_name; }

void Player::printPlayerScore() {
  LOG_DEBUG << "Player: " << m_player_name;
  LOG_DEBUG << "\tScore: " << U8(m_player_score);
  LOG_DEBUG << "\tNature Tokens: " << U8(m_player_nature_tokens);
  LOG_DEBUG << "\tBoard size: " << U8(m_board.getBoardSize());
}