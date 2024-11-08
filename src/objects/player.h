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
    int point;
    int lastPoints;
    int grvity;
    int currentFrame;
    int framesCounter;
    int framesSpeed;
    float frameTimeAccum;

    Rectangle frameRec;
    Texture2D texture;
};

void initPlayer(Player& player);
void loadPlayer(Player& player);
void updatePlayer(Player& player);
void drawPlayer(Player& player);
void unloadPlayer(Player& player);