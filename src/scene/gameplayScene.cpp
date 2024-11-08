#include "scene/gameplayScene.h"

#include "game.h"
#include "objects/player.h"
#include "objects/obstacle.h"
#include "objects/utils.h"
#include "scene/menuScene.h"
#include "objects/buttons.h"

using namespace Buttons;
using namespace Obstacles; 
using namespace Game;

namespace GameplayScene
{
	Player::Player player;
	Obstacle obstacle;
	static Texture2D background;
	static Texture2D waterReflection;
	static Texture2D clouds;
	static Texture2D moon;

	static float scrollingBack = 0.0f;
	static float scrollingMidBack = 0.0f;
	static float scrollingMid = 0.0f;
	static float scrollingFront = 0.0f;

	void initGameplay()
	{
		initBackground();
		Player::initPlayer(player);
		initObstacle(obstacle);

		initButton(pauseGame, screenWidth - 200, 550);
	}

	void loadGameplay()
	{
		Player::loadPlayer(player);
	}

	void updateGameplay(bool& menuOn, bool& gameOver)
	{
		Player::updatePlayer(player);
		updateObstacle(obstacle);

		checkCollision();

		if (player.life <= 0)
		{
			gameOver = true;
			MenuScene::drawGameOver(menuOn, gameOver);
		}

		updateBackground();
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

	void drawGameplay(bool& menuOn, bool& pauseOn)
	{
		drawParalaxBackgournd();
		ClearBackground(GREEN);
		Player::drawPlayer(player);
		drawObstacle(obstacle);

		drawButton(pauseGame);
		drawPauseButtonTitle();

		if (isButtonPressed(pauseGame))
		{
			pauseOn = true;
			menuOn = false;
		}

		DrawText(TextFormat(" Life %01i", player.life), screenWidthMin, screenHeightMin, 30, RED);
	}

	void initBackground()
	{
		background = LoadTexture("res/Ocean_6/backgorund.png");
		waterReflection = LoadTexture("res/Ocean_6/reflection.png");
		clouds = LoadTexture("res/Ocean_6/clouds.png");
		moon = LoadTexture("res/Ocean_6/moon.png");
	}

	void updateBackground()
	{
		scrollingBack -= 100.0f * GetFrameTime();
		scrollingMidBack -= 100.0f * GetFrameTime();
		scrollingMid -= 150.0f * GetFrameTime();
		scrollingFront -= 150.0f * GetFrameTime();

		if (scrollingBack <= -background.width * 2) scrollingBack = static_cast<float>(screenWidthMin);
		if (scrollingMidBack <= -waterReflection.width * 2) scrollingBack = static_cast<float>(screenWidthMin);
		if (scrollingMid <= -clouds.width * 2) scrollingMid = static_cast<float>(screenWidthMin);
		if (scrollingFront <= -moon.width * 2) scrollingFront = static_cast<float>(screenWidthMin);
	}

	void drawParalaxBackgournd()
	{
		DrawTextureEx(background, Vector2{ scrollingBack, static_cast<float>(screenHeightMin) }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(background, Vector2{ background.width * 2 + scrollingBack, static_cast<float>(screenHeightMin) }, 0.0f, 2.0f, WHITE);

		DrawTextureEx(waterReflection, Vector2{ scrollingMidBack, static_cast<float>(screenHeightMin) }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(waterReflection, Vector2{ waterReflection.width * 2 + scrollingMidBack, static_cast<float>(screenHeightMin) }, 0.0f, 2.0f, WHITE);

		DrawTextureEx(moon, Vector2{ scrollingFront, static_cast<float>(screenHeightMin) + 20 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(moon, Vector2{ moon.width * 2 + scrollingFront, static_cast<float>(screenHeightMin) + 20 }, 0.0f, 2.0f, WHITE);

		DrawTextureEx(clouds, Vector2{ scrollingMid, static_cast<float>(screenHeightMin) }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(clouds, Vector2{ clouds.width * 2 + scrollingMid, static_cast<float>(screenHeightMin) }, 0.0f, 2.0f, WHITE);
	}

	void resetGame()
	{
		Player::initPlayer(player);
		initObstacle(obstacle);
	}

	void unloadGameplay()
	{
		UnloadTexture(background);
		UnloadTexture(clouds);
		UnloadTexture(moon);
	}

}
