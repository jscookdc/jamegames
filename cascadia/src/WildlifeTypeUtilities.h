#pragma once

#include "WildlifeType.h"
#include <random>
#include <stdexcept>
#include <string>

class WildlifeTypeUtilities {
public:
  static std::string toString(WildlifeType wildlife_type);
  static WildlifeType getRandomWildlifeType();
  static std::vector<WildlifeType>
  getRandomWildlifeTypeVector(unsigned max_size);

private:
  WildlifeTypeUtilities() = delete;
};