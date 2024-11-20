#pragma once

namespace GameplayScene
{
	extern bool twoPlayers;
	extern int winner;

	void initGameplay();

	void loadGameplay();

	void updateGameplay(bool& menuOn, bool& gameOver);

	void checkCollision();

	void drawGameplay(bool& menuOn, bool& pauseOn);

	void initBackground();

	void updateBackground();

	void drawParalaxBackgournd();

	void resetGame();

	void unloadGameplay();

}
