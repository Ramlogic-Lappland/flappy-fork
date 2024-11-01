#include "raylib.h"


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

extern Player player;
//extern Sound loseSfx;
//extern Sound boostSfx;

void initPlayer(Player& p);
void loadPlayer();
void updatePlayer(Player& p);
//void checkPlayerCollisions(Player& p);
void drawPlayer(Player& p);
void unloadPlayer();