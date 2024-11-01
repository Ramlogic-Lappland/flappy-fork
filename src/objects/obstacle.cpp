#include "objects/obstacle.h"

#include "objects/utils.h"



void initObstacle(Obstacle& o)
{
	o.position = { static_cast<float>(screenWidth),
				   static_cast<float>(GetRandomValue(screenHeightMin, screenHeight - o.height)) };

	o.speed = { 500.0f, 0.0f };

	o.width = 30;

	o.height = 200;
}

void loadObstacle()
{
}

void updateObstacle(Obstacle& o)
{
	if (o.position.x < static_cast<float>(screenWidthMin))
	{
		o.position.x = static_cast<float>(screenWidth);
		o.position.y = static_cast<float>(GetRandomValue(screenHeightMin, screenHeight - o.height));
	}

	o.position.x -= o.speed.x * GetFrameTime();

	
}

void drawObstacle(Obstacle& o)
{
	DrawRectangle(static_cast<int>(o.position.x), static_cast<int>(o.position.y), o.width, o.height, RED);
}

void unloadObstacle()
{
}
