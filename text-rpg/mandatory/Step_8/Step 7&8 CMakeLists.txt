cmake_minimum_required(VERSION 3.20)

project(Project_Text_RPG)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Project_Text_RPG

    text-rpg-mandatory/Step_8_mandatory/Step_7_Main.cpp

    text-rpg-mandatory/Step_1_mandatory/CharacterSetup.cpp

    text-rpg-mandatory/Step_2_mandatory/SetupCheck.cpp

    text-rpg-mandatory/Step_3_mandatory/UpgradeSetup.cpp

    text-rpg-mandatory/Step_4_mandatory/Player.cpp
    text-rpg-mandatory/Step_4_mandatory/Warrior.cpp
    text-rpg-mandatory/Step_4_mandatory/Magician.cpp
    text-rpg-mandatory/Step_4_mandatory/Thief.cpp
    text-rpg-mandatory/Step_4_mandatory/Archer.cpp
    text-rpg-mandatory/Step_4_mandatory/SelectClass.cpp

    text-rpg-mandatory/Step_5_mandatory/MonsterBone.cpp
    text-rpg-mandatory/Step_5_mandatory/Mushroom.cpp
    text-rpg-mandatory/Step_5_mandatory/Slime.cpp
    text-rpg-mandatory/Step_5_mandatory/Battle.cpp
    
    text-rpg-mandatory/Step_6_mandatory/Inventory.cpp
    text-rpg-mandatory/Step_6_mandatory/Ui.cpp

    text-rpg-mandatory/Step_7_mandatory/AlchemyWorkshop.cpp
    text-rpg-mandatory/Step_7_mandatory/PotionRecipe.cpp

)

target_include_directories(Project_Text_RPG PRIVATE
    text-rpg-mandatory
)