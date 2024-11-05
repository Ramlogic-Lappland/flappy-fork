#include "objects/player.h"

#include "objects/utils.h"

//static Texture2D spaceShip;
//Sound loseSfx;
//Sound boostSfx;

void initPlayer(Player& player)
{
	player.position = { static_cast<float>(screenWidthMin) + 200, 
		   static_cast<float>(screenHeight) / 2.0f };

	player.speed = { 0.0f, 0.0f };

	player.radius = 20.0f;
	player.isActive = true;
	player.life = 3;
	player.respawnTime = 1.0f;
	
	player.point = 0;
}

void loadPlayer()
{
}

void updatePlayer(Player& player)
{
	player.speed.y += 500 * GetFrameTime();

	player.position.y += player.speed.y * GetFrameTime();

	if (IsKeyDown(KEY_UP))
		player.speed.y = -200.f;

	if (player.position.y > screenHeight)
	{
		player.life--;

		player.position = { static_cast<float>(screenWidthMin) + 200,
		   static_cast<float>(screenHeight) / 2.0f };

		player.speed = { 0.0f, 0.0f };
	}

	if (player.position.y < screenHeightMin + player.radius)
	{
		player.position.y = static_cast<float>(screenHeightMin) + player.radius;
	}

}


void drawPlayer(Player& player)
{
	DrawCircle(static_cast<int>(player.position.x), static_cast<int>(player.position.y), player.radius, BLUE);
}

void unloadPlayer()
{
}
