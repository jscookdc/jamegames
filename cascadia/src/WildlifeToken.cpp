#include "WildlifeToken.h"

WildlifeToken::WildlifeToken(WildlifeType wildlife_type)
    : m_wildlife_type(wildlife_type) {}

WildlifeType WildlifeToken::getWildlifeType() const { return m_wildlife_type; }

bool WildlifeToken::operator==(const WildlifeToken &other_token) {
  return m_wildlife_type == other_token.getWildlifeType();
}