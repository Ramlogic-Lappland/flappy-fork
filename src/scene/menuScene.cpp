#include "scene/menuScene.h"

#include "raylib.h"

#include "objects/buttons.h"
#include "objects/utils.h"
#include "scene/gameplayScene.h"
#include "game.h"

using namespace Buttons;
using namespace GameplayScene;
using namespace Game;

namespace MenuScene
{
	static Texture2D controlsTex;
	static Texture2D menuBackground;

	Sound buttonSound;
	Sound coin;
	Sound gameOverSound;
	Sound pop;
	Sound retroJump;

	Music menuMusic;
	Music gameMusic;

	void initMenu()
	{		
		controlsTex = LoadTexture("res/Controls.png");
		menuBackground = LoadTexture("res/backgorund.png");

		InitAudioDevice();

		gameMusic = LoadMusicStream("res/music/gameSong.mp3");
		menuMusic = LoadMusicStream("res/music/menuSong.mp3");

		buttonSound   = LoadSound("res/music/button.wav");
		gameOverSound = LoadSound("res/music/gameOver.wav");
		retroJump     = LoadSound("res/music/retroJump.wav");
		pop           = LoadSound("res/music/pop.wav");
		coin          = LoadSound("res/music/coin.wav");

		PlayMusicStream(menuMusic);
		PlayMusicStream(gameMusic);

		initButton(button, screenWidth / 2 - 100, 100);
		initButton(twoPlayersButton, screenWidth / 2 - 100, 200);
		initButton(controls, screenWidth / 2 - 100, 300);
		initButton(credits, screenWidth / 2 - 100, 400);
		initButton(exitGame, screenWidth / 2 - 100, 500);

		initButton(backToMenu, 30, 530);
		initButton(resumeGame, screenWidth / 2 - 80 , 500);
		initButton(playAgain, screenWidth / 2 - 80, 500);

		initPageButton(page1, screenWidth / 2 - 150, 500);
		initPageButton(page2, screenWidth / 2 - 50, 500);
	}

	void drawMenu(bool& menuOn, bool& controlsOn, bool& creditsOn) //update menu
	{
		UpdateMusicStream(menuMusic);
		ClearBackground(BLACK);

		DrawTexture(menuBackground, 0, 0, WHITE);

		DrawText(TextFormat("FLIYING GUADS"), screenWidth / 2 - 170, screenHeightMin + 30, 50, RED);

		drawButton(button);
		drawButton(twoPlayersButton);
		drawButton(controls);
		drawButton(credits);
		drawButton(exitGame);

		drawPlayTitle();
		drawPlayTwo();
		drawControlTitle();
		drawCreditsTitle();
		drawExitTitle();

		if (isButtonPressed(button))
		{
			PlaySound(buttonSound);
			menuOn = false;
			GameplayScene::twoPlayers = false;
			resetGame();
		}

		if (isButtonPressed(twoPlayersButton))
		{
			PlaySound(buttonSound);
			menuOn = false;
			GameplayScene::twoPlayers = true;
			resetGame();
		}

		if (isButtonPressed(controls))
		{
			PlaySound(buttonSound);
			controlsOn = true;
			menuOn = false;
		}

		if (isButtonPressed(credits))
		{
			PlaySound(buttonSound);
			creditsOn = true;
			menuOn = false;
		}

		if (isButtonPressed(exitGame))
		{
			PlaySound(buttonSound);
			Game::closeAll = true;
		}

		if (isButtonPressed(backToMenu))
		{
			PlaySound(buttonSound);
			menuOn = true;
			creditsOn = false;
			controlsOn = false;
		}

		DrawText("", screenWidth - 50, screenHeight - 50, 30, RED);
	}

	void drawConstrols(bool& menuOn, bool& controlsOn)
	{

		ClearBackground(BLACK);

		DrawTexture(controlsTex,0, 0, WHITE);

		drawBackToMenu(menuOn, controlsOn);

	}

	void drawCredits(bool& menuOn, bool& creditsOn, bool& creditsOn2)
	{

		ClearBackground(BLACK);

		DrawText(TextFormat("CREDITS"), screenWidth / 2 - 60, 50, 30, WHITE);

		DrawText("OG code: ", screenWidth / 2 - 250, 100, 30, WHITE);

		DrawText("Valentin Villar", screenWidth / 2 + 50, 100, 30, WHITE);
		DrawText("Tronik in ITCH.IO ", screenWidth / 2 + 50, 180, 30, WHITE);

		DrawText("Background By: ", screenWidth / 2 - 250, 240, 30, WHITE);

		DrawText(" in ITCH.IO", screenWidth / 2 + 50, 240, 30, WHITE);

		DrawText("Player By: ", screenWidth / 2 - 250, 300, 30, WHITE);

		DrawText("Valentin Villar Piskel", screenWidth / 2 + 50, 300, 30, WHITE);

		DrawText("Forked by: ", screenWidth / 2 - 250, 360, 30, WHITE);

		DrawText("Estanislao Sala", screenWidth / 2 + 50, 360, 30, WHITE);

		DrawText("Library: ", screenWidth / 2 - 250, 420, 30, WHITE);

		DrawText("Raylib", screenWidth / 2 + 50, 420, 30, WHITE);

		drawPageButton(creditsOn, creditsOn2);

		drawBackToMenu(menuOn, creditsOn);

	}

	void drawSecondCredits(bool& menuOn, bool& creditsOn, bool& creditsOn2)
	{

		ClearBackground(BLACK);

		DrawText(TextFormat("CREDITS"), screenWidth / 2 - 60, 50, 30, WHITE);

		DrawText("Menu Music: ", screenWidth / 2 - 290, 150, 30, WHITE);

		DrawText("Estanislao Sala", screenWidth / 2 - 80, 150, 30, WHITE);
		DrawText("Using SUNO AI ", screenWidth / 2 - 80, 180, 30, WHITE);

		DrawText("Sounds: ", screenWidth / 2 - 290, 240, 30, WHITE);
		DrawText("Driken5482 for Jump sound", screenWidth / 2 - 150, 240, 30, WHITE);
		DrawText("Audiosto for GameOver sound", screenWidth / 2 - 150, 280, 30, WHITE);
		DrawText("SlodkaBonanza for pop sound", screenWidth / 2 - 150, 320, 30, WHITE);
		DrawText("floraphonic for coin sound", screenWidth / 2 - 150, 360, 30, WHITE);
		DrawText("freesound for button sound", screenWidth / 2 - 150, 400, 30, WHITE);

		drawPageButton(creditsOn, creditsOn2);

		drawBackToMenu(menuOn, creditsOn2);
	}

	void drawBackToMenu(bool& boolTrue, bool& boolFalse)
	{
		ClearBackground(BLACK);

		drawButton(backToMenu);

		drawBackToMenuTitle();

		if (isButtonPressed(backToMenu))
		{
			PlaySound(buttonSound);
			boolTrue = true;
			boolFalse = false;
		}
	}

	void drawPause(bool& menuOn, bool& pauseOn)
	{

		ClearBackground(BLACK);

		DrawText(TextFormat("Pause game"), screenWidth / 2 - 150, screenHeight / 2 - 100, 50, WHITE);

		DrawText(TextFormat("What Will You Do"), screenWidth / 2 - 200, screenHeight / 2 - 30, 50, WHITE);


		drawButton(resumeGame);
		drawResumeGameTitle();

		if (isButtonPressed(resumeGame))
		{
			PlaySound(buttonSound);
			pauseOn = false;
		}


		drawBackToMenu(menuOn, pauseOn);
	}

	void drawPageButton(bool& creditsOn, bool& creditsOn2)
	{

		drawButton(page1);
		drawPage1Title();

		if (isButtonPressed(page1))
		{
			PlaySound(buttonSound);
			creditsOn = true;
			creditsOn2 = false;
		}

		drawButton(page2);
		drawPage2Title();

		if (isButtonPressed(page2))
		{
			PlaySound(buttonSound);
			creditsOn = false;
			creditsOn2 = true;
		}
	}

	void drawGameOver(bool& menuOn, bool& gameOver)
	{
		ClearBackground(BLACK);

		DrawText(TextFormat("Game Over"), screenWidth / 2 - 150, screenHeight / 2 - 100, 50, WHITE);

		DrawText(TextFormat("What Will You Do"), screenWidth / 2 - 200, screenHeight / 2 - 30, 50, WHITE);

		drawButton(playAgain);
		drawPlayAgainTitle();

		if (isButtonPressed(playAgain))
		{
			PlaySound(buttonSound);
			gameOver = false;
			resetGame();
		}

		drawBackToMenu(menuOn, gameOver);
	}

	void unloadMenu()
	{
		UnloadSound(buttonSound);
		UnloadSound(coin);
		UnloadSound(gameOverSound);
		UnloadSound(pop);
		UnloadSound(retroJump);

		UnloadMusicStream(menuMusic);
		UnloadMusicStream(gameMusic);

		UnloadTexture(controlsTex);
		UnloadTexture(menuBackground);
	}
}



