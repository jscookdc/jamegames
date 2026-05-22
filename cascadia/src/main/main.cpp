#include "Tile.h"
#include "Biome.h"
#include <iostream>
#include "WildlifeType.h"
#include "Player.h"
#include "Game.h"
#include "Log.h"
#include <glog/logging.h>


int main(int argc, char* argv[])
{
    google::InitGoogleLogging(argv[0]);
    FLAGS_alsologtostderr = true;  // print logs to terminal as well as file

    LOG_DEBUG << "===== Initializing Cascadia =====";

    // Solo game for now, more players later
    Player player_james = Player("James");
    std::vector<Player> players;
    players.push_back(player_james);

    Game solo_game = Game(players);

    LOG_DEBUG << "===== Shutting Down Cascadia =====";
    google::ShutdownGoogleLogging();
    return 0;
}