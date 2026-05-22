#pragma once

#include "Biome.h"
#include <random>
#include <string>

class BiomeUtilities {
public:
  static std::string toString(Biome biome);
  static Biome getRandomBiome();

private:
  BiomeUtilities() = delete;
};