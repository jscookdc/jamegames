#pragma once

#include "Biome.h"
#include <string>
#include <random>

class BiomeUtilities
{
    public:
        static std::string toString(Biome biome);
        static Biome getRandomBiome();
    
    private:
        BiomeUtilities() = delete;
};