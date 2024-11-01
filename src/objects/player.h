#pragma once

#include "raylib.h"

#include "objects/obstacle.h"

struct Player
{
    Vector2 position;
    Vector2 speed;
    float radius;
    bool isActive;
    int life;
    float respawnTime;
    int point;
    int lastPoints;
};

 
//extern Sound loseSfx;
//extern Sound boostSfx;

void initPlayer(Player& player);
void loadPlayer();
void updatePlayer(Player& player);
void drawPlayer(Player& player);
void unloadPlayer();