#pragma once

#include "raylib.h"

struct Obstacle
{
    Vector2 position;
    Vector2 speed;
    int width;
    int height;
};

extern Obstacle obstacle;

//extern Sound loseSfx;
//extern Sound boostSfx;

void initObstacle(Obstacle& o);
void loadObstacle();
void updateObstacle(Obstacle& o);
void drawObstacle(Obstacle& o);
void unloadObstacle();