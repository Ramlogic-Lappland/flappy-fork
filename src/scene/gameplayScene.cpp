#include "scene/gameplayScene.h"

#include "objects/player.h"
#include "objects/obstacle.h"

void initGameplay()
{
	initPlayer(player);
	initObstacle(obstacle);
}

void loadGameplay()
{
}

void updateGameplay()
{
	updatePlayer(player);
	updateObstacle(obstacle);
}

void drawGameplay()
{
	drawPlayer(player);
	drawObstacle(obstacle);
}

void resetGame()
{
}

void unloadGameplay()
{
}
