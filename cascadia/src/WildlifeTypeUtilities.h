#pragma once

#include "WildlifeType.h"
#include <string>
#include <random>
#include <stdexcept>

class WildlifeTypeUtilities
{
    public:
        static std::string toString(WildlifeType wildlife_type);
        static WildlifeType getRandomWildlifeType();
        static std::vector<WildlifeType> getRandomWildlifeTypeVector(unsigned max_size);

    
    private:
        WildlifeTypeUtilities() = delete;
};