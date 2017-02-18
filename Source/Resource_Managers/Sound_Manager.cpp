#include "Sound_Manager.h"

#include <thread>

Sound_Manager::Sound_Manager()
{
    std::string path ("Res/Sounds/");

    registerResource(Sound_ID::Splash_Made_By,  path + "MadeBy.ogg" );
    registerResource(Sound_ID::Sword1,          path + "Sword1.ogg" );

    registerResource(Sound_ID::Dmg_Player,  path + "Dmg_Player.ogg" );
    registerResource(Sound_ID::Dmg_Slime,   path + "Dmg_Slime.ogg"  );
    registerResource(Sound_ID::Dmg_Bee,     path + "Dmg_Bee.ogg"  );
}

Sound_Manager::~Sound_Manager()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
