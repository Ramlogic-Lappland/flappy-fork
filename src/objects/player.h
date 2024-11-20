#pragma once

#include "raylib.h"

#include "objects/obstacle.h"

namespace PlayerN
{
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

    void initPlayer(Player& player1, Player& player2, bool twoPlayers);
    void loadPlayer(Player& player1, Player& player2);
    void updatePlayer(Player& player1, Player& player2, bool twoPlayers);
    void drawPlayer(Player& player1, Player& player2, bool twoPlayers);
    void unloadPlayer(Player& player1, Player& player2);
}
