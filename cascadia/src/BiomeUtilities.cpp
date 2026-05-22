#include "BiomeUtilities.h"

std::string BiomeUtilities::toString(Biome biome) {
  switch (biome) {
  case Biome::Forest:
    return "Forest";
  case Biome::Mountain:
    return "Mountain";
  case Biome::Prairie:
    return "Prainie";
  case Biome::Wetland:
    return "Wetland";
  case Biome::River:
    return "River";
  default:
    return "Unknown";
  }
}

Biome BiomeUtilities::getRandomBiome() {
  static std::mt19937 rng(std::random_device{}());
  static std::uniform_int_distribution<int> dist(
      0, static_cast<int>(Biome::COUNT) - 1);

  return static_cast<Biome>(dist(rng));
}