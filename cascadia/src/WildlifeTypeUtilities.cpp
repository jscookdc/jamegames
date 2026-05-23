#include "WildlifeTypeUtilities.h"

std::string WildlifeTypeUtilities::toString(WildlifeType wildlife_type) {
  switch (wildlife_type) {
  case WildlifeType::Bear:
    return "Bear";
  case WildlifeType::Elk:
    return "Elk";
  case WildlifeType::Fox:
    return "Fox";
  case WildlifeType::Hawk:
    return "Hawk";
  case WildlifeType::Salmon:
    return "Salmon";
  case WildlifeType::NoToken:
    return "No Token";
  default:
    return "Unknown";
  }
}

WildlifeType WildlifeTypeUtilities::getRandomWildlifeType() {
  static std::mt19937 rng(std::random_device{}());
  static std::uniform_int_distribution<int> dist(0, static_cast<int>(WildlifeType::COUNT) - 1);

  return static_cast<WildlifeType>(dist(rng));
}

std::vector<WildlifeType> WildlifeTypeUtilities::getRandomWildlifeTypeVector(unsigned max_size) {
  if (max_size == 0) {
    throw std::invalid_argument("max_size must be a positive integer");
  }

  static thread_local std::mt19937 rng{std::random_device{}()};

  std::uniform_int_distribution<unsigned> size_dist(1, max_size);
  unsigned size = size_dist(rng);

  std::uniform_int_distribution<int> wildlife_dist(0, static_cast<int>(WildlifeType::COUNT) - 1);

  std::vector<WildlifeType> result;
  result.reserve(size);
  for (unsigned i = 0; i < size; ++i) {
    result.push_back(static_cast<WildlifeType>(wildlife_dist(rng)));
  }
  return result;
}