#include "Board.h"

static constexpr HexCoordinate k_hex_neighbors[6] = {
    {1, 0},  // E   (3 o'clock)  — pointy-top
    {1, -1}, // NE  (1 o'clock)
    {0, -1}, // NW  (11 o'clock)
    {-1, 0}, // W   (9 o'clock)
    {-1, 1}, // SW  (7 o'clock)
    {0, 1},  // SE  (5 o'clock)
};

Board::Board() {
  initializeBoard();
}

void Board::initializeBoard() {
  LOG_DEBUG << "New board instantiated.";
  m_tiles.emplace(HexCoordinate{0, 0},
                  Tile(BiomeUtilities::getRandomBiome(), BiomeUtilities::getRandomBiome(),
                       WildlifeTypeUtilities::getRandomWildlifeTypeVector(3)));
  m_tiles.emplace(HexCoordinate{0, 1},
                  Tile(BiomeUtilities::getRandomBiome(), BiomeUtilities::getRandomBiome(),
                       WildlifeTypeUtilities::getRandomWildlifeTypeVector(3)));
  m_tiles.emplace(HexCoordinate{-1, 1},
                  Tile(BiomeUtilities::getRandomBiome(), BiomeUtilities::getRandomBiome(),
                       WildlifeTypeUtilities::getRandomWildlifeTypeVector(3)));
}

bool Board::isValidPlacement(HexCoordinate coordinate) const {
  if (m_tiles.contains(coordinate)) {
    return false;
  }
  for (const auto& offset : k_hex_neighbors) {
    if (m_tiles.count({coordinate.q + offset.q, coordinate.r + offset.r})) {
      return true;
    }
  }
  return false;
}

void Board::placeTile(Tile tile, HexCoordinate coordinate) {
  if (!isValidPlacement(coordinate)) {
    throw std::invalid_argument("invalid tile placement");
  }
  m_tiles.emplace(coordinate, std::move(tile));
}

std::size_t Board::getBoardSize() const {
  return m_tiles.size();
}