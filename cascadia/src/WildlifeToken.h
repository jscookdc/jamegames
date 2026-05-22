#pragma once

#include "WildlifeType.h"

class WildlifeToken
{
    public:
        WildlifeToken(WildlifeType wildlife_type);

        WildlifeType getWildlifeType() const;

        bool operator==(const WildlifeToken& other_token);

    private:
        WildlifeType m_wildlife_type;
};