cmake_minimum_required(VERSION 3.10)

#Set up project
project(
    hero 
    VERSION 1.0
)

include("$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

add_executable(${PROJECT_NAME}     
    Source/Game/Stat_Level.cpp
    Source/Game/Health.cpp
    Source/Game/GUI/Button.cpp
    Source/Game/Zone/Zone.cpp
    Source/Game/Zone/ZTown.cpp
    Source/Game/Zone/ZBeach.cpp
    Source/Game/Zone/ZForest.cpp
    Source/Game/Player.cpp
    Source/Game/Health_Bar.cpp
    Source/Game/Map/Zone_Selector.cpp
    Source/Game/Map/Map_Zone.cpp
    Source/Game/Map/Map_GUI.cpp
    Source/Game/Entities/Coral_Slime.cpp
    Source/Game/Entities/Bee.cpp
    Source/Game/Entities/Blacksmith.cpp
    Source/Game/Entities/Slime.cpp
    Source/Game/Entities/Enemy_Factory.cpp
    Source/Game/Entities/Entity.cpp
    Source/Game/Entities/Enemy.cpp
    Source/Game/Game_Notice.cpp
    Source/Game/World.cpp
    Source/Game/Projectile.cpp
    Source/Game/Component/CFollowPlayer.cpp
    Source/Game/Component/CDamagePlayer.cpp
    Source/Game/Component/CAnimation.cpp
    Source/Game/Component/Component.cpp
    Source/Game/Component/CDamagedBySword.cpp
    Source/Game/Equipment/Sword.cpp
    Source/Game/Equipment/Equippable.cpp
    Source/Game/Equipment/Equipment_Data.cpp
    Source/Game/Loot.cpp
    Source/Main.cpp
    Source/Util/Console.cpp
    Source/Util/Random.cpp
    Source/Application.cpp
    Source/Display.cpp
    Source/States/Splash_Screen.cpp
    Source/States/Playing_State.cpp
    Source/States/State_Base.cpp
    Source/Resource_Managers/Resource_Holder.cpp
    Source/Resource_Managers/Font_Manager.cpp
    Source/Resource_Managers/Texture_Manager.cpp
    Source/Resource_Managers/Sound_Manager.cpp
    Source/Resource_Managers/Resource_Manager.cpp
    Source/Animation.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "/O2")
    set(CMAKE_CXX_FLAGS_RELEASE "/Ox")
  	target_compile_options(${PROJECT_NAME} PRIVATE 
    	/W4)
else()
  	target_compile_options(${PROJECT_NAME} PRIVATE 
		-Wall -Wextra -pedantic)		
endif()

find_package(SFML COMPONENTS system audio network window graphics CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
    sfml-system sfml-audio sfml-network sfml-graphics sfml-window
)
