#pragma once

#include "raylib.h"

#include "objects/player.h"


namespace Obstacles
{
    struct Obstacle
    {
        Vector2 position;
        Vector2 speed;
        int width;
        int topHeight;
        int gap;
        int bottomHeight;
    };


    void initObstacle(Obstacle& o);
    void loadObstacle();
    void updateObstacle(Obstacle& o);
    void drawObstacle(Obstacle& o);
    void unloadObstacle();
}
