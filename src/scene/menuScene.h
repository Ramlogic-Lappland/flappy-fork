#pragma once

#include "raylib.h"

namespace MenuScene
{
	extern Music gameMusic;
	extern Sound buttonSound;
	extern Sound coin;
	extern Sound gameOverSound;
	extern Sound pop;
	extern Sound retroJump;

	void initMenu();

	void drawMenu(bool& menuOn, bool& controlsOn, bool& creditsOn);

	void drawConstrols(bool& menuOn, bool& controlsOn);

	void drawCredits(bool& menuOn, bool& creditsOn, bool& creditsOn2);

	void drawSecondCredits(bool& menuOn, bool& creditsOn, bool& creditsOn2);

	void drawBackToMenu(bool& boolTrue, bool& boolFalse);

	void drawPause(bool& menuOn, bool& pauseOn);

	void drawPageButton(bool& creditsOn, bool& creditsOn2);

	void drawGameOver(bool& menuOn, bool& gameOver);

	void unloadMenu();
}


