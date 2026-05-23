#include "Tile.h"
#include "Player.h"

Tile::Tile(Biome biome_1, Biome biome_2, std::vector<WildlifeType> wildlife_token_options)
    : m_biome_1(biome_1), m_biome_2(biome_2), m_wildlife_token_options(wildlife_token_options),
      m_wildlife_token(WildlifeType::NoToken) {}

Tile::Tile(Biome biome_1, Biome biome_2, WildlifeType single_wildlife_token_option)
    : m_biome_1(biome_1), m_biome_2(biome_2), m_wildlife_token(WildlifeType::NoToken) {
  m_wildlife_token_options.push_back(single_wildlife_token_option);
}

bool Tile::canPlaceWildlifeToken(WildlifeToken token) {
  WildlifeType token_wildlife_type = token.getWildlifeType();
  for (const auto& token_option : m_wildlife_token_options) {
    if (token_option == token_wildlife_type) {
      return true;
    }
  }
  return false;
}

void Tile::placeWildlifeToken(WildlifeToken token, Player& player) {
  if (m_wildlife_token.getWildlifeType() == WildlifeType::NoToken) {
    if (!canPlaceWildlifeToken(token)) {
      throw std::invalid_argument("cannot place this type of wildlife token");
    }
    m_wildlife_token = token;
    if (m_biome_1 == m_biome_2 && m_wildlife_token_options.size() == 1) {
      player.addNatureToken();
    }
  } else {
    throw std::invalid_argument("wildlife token is already set");
  }
}
