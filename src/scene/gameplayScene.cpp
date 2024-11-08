#include "scene/gameplayScene.h"

#include "objects/player.h"
#include "objects/obstacle.h"
#include "objects/utils.h"
#include "scene/menuScene.h"

Player player;
Obstacle obstacle;
static Texture2D background;
static Texture2D clouds;
static Texture2D moon;

static float scrollingBack = 0.0f;
static float scrollingMid = 0.0f;
static float scrollingFront = 0.0f;

void initGameplay()
{
	initPlayer(player);
	initObstacle(obstacle);
}

void loadGameplay()
{
	loadPlayer(player);
}

void updateGameplay(bool& menuOn, bool& gameOver)
{
	updatePlayer(player);
	updateObstacle(obstacle);

	checkCollision();

	if (player.life <= 0)
	{
		gameOver = true;
		drawGameOver(menuOn, gameOver);
	}

}

void checkCollision()
{
	bool collisionTop = (player.position.x + player.radius >= obstacle.position.x &&
		player.position.x - player.radius <= obstacle.position.x + obstacle.width &&
		player.position.y + player.radius >= 0 &&
		player.position.y - player.radius <= obstacle.topHeight);

	bool collisionBottom = (player.position.x + player.radius >= obstacle.position.x &&
		player.position.x - player.radius <= obstacle.position.x + obstacle.width &&
		player.position.y + player.radius >= obstacle.topHeight + obstacle.gap &&
		player.position.y - player.radius <= obstacle.topHeight + obstacle.gap + obstacle.bottomHeight);

	if (collisionTop || collisionBottom)
	{
		initObstacle(obstacle); 
		player.life--;          
	}

}

void drawGameplay()
{
	drawParalaxBackgournd();

	ClearBackground(GREEN);
	drawPlayer(player);
	drawObstacle(obstacle);

	DrawText(TextFormat(" Life %01i", player.life), screenWidthMin , screenHeightMin , 30, RED);
}

void drawParalaxBackgournd()
{
	background = LoadTexture("res/Ocean_6/backgorund.png");
	clouds = LoadTexture("res/Ocean_6/clouds.png");
	moon = LoadTexture("res/Ocean_6/moon.png");

	scrollingBack -= 0.1f;
	scrollingMid -= 0.15f;
	scrollingFront -= 0.15f;

	if (scrollingBack <= -background.width * 2) scrollingBack = 0;
	if (scrollingMid <= -clouds.width * 2) scrollingMid = 0;
	if (scrollingFront <= -moon.width * 2) scrollingFront = 0;

	DrawTextureEx(background, Vector2{ scrollingBack, static_cast<float>(screenHeightMin) }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(background, Vector2{ background.width * 2 + scrollingBack, static_cast<float>(screenHeightMin) }, 0.0f, 2.0f, WHITE);

	DrawTextureEx(moon, Vector2{ scrollingFront, 20 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(moon, Vector2{ moon.width * 2 + scrollingFront, 20 }, 0.0f, 2.0f, WHITE);

	DrawTextureEx(clouds, Vector2{ scrollingMid, static_cast<float>(screenHeightMin)}, 0.0f, 2.0f, WHITE);
	DrawTextureEx(clouds, Vector2{ clouds.width * 2 + scrollingMid, static_cast<float>(screenHeightMin)}, 0.0f, 2.0f, WHITE);	
}

void resetGame()
{
	initPlayer(player);
	initObstacle(obstacle);
}

void unloadGameplay()
{
	UnloadTexture(background);
	UnloadTexture(clouds);
	UnloadTexture(moon);
}
