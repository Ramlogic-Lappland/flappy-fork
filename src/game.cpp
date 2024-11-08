#include "game.h"

#include "raylib.h"

#include "scene/gameplayScene.h"
#include "scene/menuScene.h"

using namespace GameplayScene;
using namespace MenuScene;

namespace Game
{
	static void Initialization();
	static void loadGame();
	static void update();
	static void draw();
	static void unloadGame();
	static void close();

	int screenWidth = 800;
	int screenHeight = 600;
	int screenWidthMin = 0;
	int screenHeightMin = 0;

	bool menuOn = true;
	bool controlsOn = false;
	bool creditsOn = false;
	bool creditsOn2 = false;
	bool exitOn = false;
	bool gameOver = false;
	bool pauseOn = false;

	void run()
	{
		Initialization();

		loadGame();

		while (!WindowShouldClose())
		{
			update();
			draw();
		}

		unloadGame();

		close();
	}

	static void Initialization()
	{
		InitWindow(screenWidth, screenHeight, "flying guads");

		initGameplay();

		initMenu();
	}

	static void loadGame()
	{
		loadGameplay();
	}

	static void update()
	{
		if (!menuOn && !gameOver && !creditsOn && !creditsOn2 && !controlsOn && !pauseOn)
			updateGameplay(menuOn, gameOver);
	}

	static void draw()
	{
		BeginDrawing();

		if (menuOn)
		{
			drawMenu(menuOn, controlsOn, creditsOn);
		}
		else if (controlsOn)
		{
			drawConstrols(menuOn, controlsOn);
		}
		else if (creditsOn)
		{
			drawCredits(menuOn, creditsOn, creditsOn2);
		}
		else if (creditsOn2)
		{
			drawSecondCredits(menuOn, creditsOn, creditsOn2);
		}
		else if (gameOver)
		{
			drawGameOver(menuOn, gameOver);
		}
		else if (pauseOn)
		{
			drawPause(menuOn, pauseOn);
		}
		else
		{
			drawGameplay(menuOn, pauseOn);
		}

		EndDrawing();
	}

	static void unloadGame()
	{
		unloadMenu();
		unloadGameplay();
	}

	static void close()
	{
		CloseAudioDevice();
		CloseWindow();
	}
}

