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
}

void updateGameplay()
{
	updatePlayer(player);
	updateObstacle(obstacle);

	checkCollision();

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
	drawPlayer(player);
	drawObstacle(obstacle);

	DrawText("0.1", screenWidth - 50, screenHeight - 50, 30, RED);

	DrawText(TextFormat(" Life %01i", player.life), screenWidthMin , screenHeightMin , 30, RED);

}

void resetGame()
{
}

void unloadGameplay()
{
}
