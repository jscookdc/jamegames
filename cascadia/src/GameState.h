#include <ostream>

// clang-format off
enum class GameState {
    Initializing,
    Ongoing,
    Complete
};
// clang-format on

inline std::ostream& operator<<(std::ostream& os, GameState state) {
  switch (state) {
  case GameState::Initializing:
    return os << "Initializing";
  case GameState::Ongoing:
    return os << "Ongoing";
  case GameState::Complete:
    return os << "Complete";
  }
  return os << "Unknown(" << static_cast<int>(state) << ")";
}