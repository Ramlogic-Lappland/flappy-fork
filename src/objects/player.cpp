#include "objects/player.h"

#include "objects/utils.h"
#include "game.h"

using namespace Game;

namespace Player
{
	void initPlayer(Player& player1, Player& player2, bool twoPlayers)
	{

		// P1
		int posDiff = 0;

		if (twoPlayers == true)
		{
			posDiff = 20;
		}

		player1.position = { static_cast<float>(screenWidthMin) + 200,
			                 static_cast<float>(screenHeight)   / 2.0f  + posDiff};

		player1.speed = { 0.0f, 0.0f };

		player1.radius = 20.0f;
		player1.isActive = true;
		player1.life = 3;

		player1.point = 0;

		player1.grvity = 500;

		player1.currentFrame = 0;
		player1.framesCounter = 0;
		player1.framesSpeed = 8;
		player1.frameTimeAccum = 0.0f;

		player1.frameRec = { 0.0f, 0.0f, 64.0f, 64.0f };


		if (twoPlayers == true)
		{
			// P2
			player2.position = { static_cast<float>(screenWidthMin) + 200,
								 static_cast<float>(screenHeight) / 2.0f - 20 };

			player2.speed = { 0.0f, 0.0f };

			player2.radius = 20.0f;
			player2.isActive = true;
			player2.life = 3;

			player2.point = 0;

			player2.grvity = 500;

			player2.currentFrame = 0;
			player2.framesCounter = 0;
			player2.framesSpeed = 8;
			player2.frameTimeAccum = 0.0f;

			player2.frameRec = { 0.0f, 0.0f, 64.0f, 64.0f };

		}
	}

	void loadPlayer(Player& player1, Player& player2)
	{
		player1.texture = LoadTexture("res/spritesheet.png");
		player2.texture = LoadTexture("res/spritesheetP2.png");
	}

	void updatePlayer(Player& player1, Player& player2, bool twoPlayers)
	{
		// UPDATE P1 ------------------------------------------------------------------------
		if (player1.life > 0)
		{
			player1.speed.y += player1.grvity * GetFrameTime();

			player1.position.y += player1.speed.y * GetFrameTime();

			if (IsKeyDown(KEY_SPACE) || IsMouseButtonDown(MOUSE_BUTTON_LEFT))
				player1.speed.y = -200.f;

			if (player1.position.y > screenHeight)
			{
				player1.life--;

				player1.position = { static_cast<float>(screenWidthMin) + 200,
				   static_cast<float>(screenHeight) / 2.0f };

				player1.speed = { 0.0f, 0.0f };
			}

			if (player1.position.y < screenHeightMin + player1.radius)
			{
				player1.position.y = static_cast<float>(screenHeightMin) + player1.radius;
			}

			player1.frameTimeAccum += GetFrameTime();

			if (player1.frameTimeAccum >= (1.0f / player1.framesSpeed))
			{
				player1.frameTimeAccum = 0.0f;

				player1.currentFrame++;

				if (player1.currentFrame > 3)
					player1.currentFrame = 0;

				player1.frameRec.y = static_cast<float>(player1.currentFrame) * 64.0f;
			}
		}


		// UPDATE P2 ------------------------------------------------------------------------
		if (twoPlayers == true && player2.life > 0)
		{
			player2.speed.y += player2.grvity * GetFrameTime();

			player2.position.y += player2.speed.y * GetFrameTime();

			if (IsKeyDown(KEY_UP) || IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
				player2.speed.y = -200.f;

			if (player2.position.y > screenHeight)
			{
				player2.life--;

				player2.position = { static_cast<float>(screenWidthMin) + 200,
				   static_cast<float>(screenHeight) / 2.0f };

				player2.speed = { 0.0f, 0.0f };
			}

			if (player2.position.y < screenHeightMin + player2.radius)
			{
				player2.position.y = static_cast<float>(screenHeightMin) + player2.radius;
			}

			player2.frameTimeAccum += GetFrameTime();

			if (player2.frameTimeAccum >= (1.0f / player2.framesSpeed))
			{
				player2.frameTimeAccum = 0.0f;

				player2.currentFrame++;

				if (player2.currentFrame > 3)
					player2.currentFrame = 0;

				player2.frameRec.y = static_cast<float>(player2.currentFrame) * 64.0f;
			}
		}
	}

	void drawPlayer(Player& player1, Player& player2, bool twoPlayers)
	{

		// UPDATE P1 -----------------------------------------------------------------------------------------------------------------
		if (player1.life > 0)
		{
			DrawCircle(static_cast<int>(player1.position.x), static_cast<int>(player1.position.y), player1.radius, BLUE);

			DrawTextureRec(player1.texture, player1.frameRec,
				{ player1.position.x - player1.frameRec.width / 2,
				  player1.position.y - player1.frameRec.height / 2 }, WHITE);

		}

		// UPDATE P2 -----------------------------------------------------------------------------------------------------------------
		if (twoPlayers == true && player2.life > 0)
		{
			DrawCircle(static_cast<int>(player2.position.x), static_cast<int>(player2.position.y), player2.radius, BLUE);

			DrawTextureRec(player2.texture, player2.frameRec,
				{ player2.position.x - player2.frameRec.width / 2,
				  player2.position.y - player2.frameRec.height / 2 }, WHITE);
		}
	}

	void unloadPlayer(Player& player1, Player& player2)
	{
		UnloadTexture(player1.texture);
		UnloadTexture(player2.texture);
	}

}
