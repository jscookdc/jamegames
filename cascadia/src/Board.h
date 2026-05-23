#pragma once

#include "BiomeUtilities.h"
#include "Log.h"
#include "Tile.h"
#include "WildlifeTypeUtilities.h"
#include <unordered_map>

struct HexCoordinate {
  int q, r;
  bool operator==(const HexCoordinate&) const = default;
};

struct HexCoordinateHash {
  std::size_t operator()(const HexCoordinate& c) const {
    return std::hash<int>()(c.q) ^ (std::hash<int>()(c.r) << 16);
  }
};

class Board {
public:
  Board();

  void placeTile(Tile tile, HexCoordinate coordinate);
  bool isValidPlacement(HexCoordinate coordinate) const;
  std::size_t getBoardSize() const;

private:
  void initializeBoard();

  std::unordered_map<HexCoordinate, Tile, HexCoordinateHash> m_tiles;
};