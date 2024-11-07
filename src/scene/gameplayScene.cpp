#include "scene/gameplayScene.h"

#include "objects/player.h"
#include "objects/obstacle.h"
#include "objects/utils.h"
#include "scene/menuScene.h"

Player player;
Obstacle obstacle;

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
		//player.life--;          
	}

}

void drawGameplay()
{
	ClearBackground(GREEN);
	drawPlayer(player);
	drawObstacle(obstacle);

	DrawText(TextFormat(" Life %01i", player.life), screenWidthMin , screenHeightMin , 30, RED);
}

void resetGame()
{
	initPlayer(player);
	initObstacle(obstacle);
}

void unloadGameplay()
{
}
