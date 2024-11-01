#include "objects/player.h"

#include "objects/utils.h"

Player player;

//static Texture2D spaceShip;
//Sound loseSfx;
//Sound boostSfx;

void initPlayer(Player& p)
{
	p.position = { static_cast<float>(screenWidthMin) + 200, 
				   static_cast<float>(screenHeight) / 2.0f };

	p.speed = { 0.0f, 0.0f };

	p.radius = 20.0f;

	p.isActive = true;
	p.life = 3;
	p.respawnTime = 1.0f;

	p.point = 0;
}

void loadPlayer()
{
}

void updatePlayer(Player& p)
{
	if (IsKeyDown(KEY_UP))
		p.position.y -= 0.1f;

	if (IsKeyDown(KEY_DOWN))
		p.position.y += 0.1f;
}

//void checkPlayerCollisions(Player& p)
//{
//}

void drawPlayer(Player& p)
{
	DrawCircle(static_cast<int>(p.position.x), static_cast<int>(p.position.y), p.radius, BLUE);
}

void unloadPlayer()
{
}
