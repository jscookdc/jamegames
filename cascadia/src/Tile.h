#pragma once

#include "Biome.h"
#include "WildlifeType.h"
#include "WildlifeToken.h"
#include <stdexcept>
#include <vector>

class Player;

class Tile 
{
    public:
        Tile(Biome biome_1, Biome biome_2, std::vector<WildlifeType> wildlife_token_options);
        Tile(Biome biome_1, Biome biome_2, WildlifeType single_wildlife_token_option);


        /**
        * @brief if the player can place a wildlife token
        *
        * @param token a specific wildlife token
        * 
        * @return true if the token can be placed,  false otherwise
        */
        bool canPlaceWildlifeToken(WildlifeToken token);

        /**
        * @brief places a wildlife token on the tile
        *
        * @param token a specific wildlife token
        * @param player a specific player playing the token
        */
        void placeWildlifeToken(WildlifeToken token, Player& player);

    private:
        Biome m_biome_1;
        Biome m_biome_2;

        std::vector<WildlifeType> m_wildlife_token_options;

        WildlifeToken m_wildlife_token;
};