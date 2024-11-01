#include "objects/obstacle.h"

#include "objects/utils.h"

Obstacle obstacle;

void initObstacle(Obstacle& o)
{
	o.position = { static_cast<float>(screenWidth) + 50,
				   static_cast<float>(screenHeight) - 200 };

	o.speed = { 100.0f, 0.0f };

	o.width = 30;

	o.height = 200;
}

void loadObstacle()
{
}

void updateObstacle(Obstacle& o)
{
	if (o.position.x < static_cast<float>(screenWidthMin))
		o.position.x = static_cast<float>(screenWidth);
		
	if (o.position.x > static_cast<float>(screenWidth))
		o.position.x = static_cast<float>(screenWidthMin);
		
	if (o.position.y < static_cast<float>(screenHeightMin))
		o.position.y = static_cast<float>(screenHeight);
		
	if (o.position.y > static_cast<float>(screenHeight))
		o.position.y = static_cast<float>(screenHeightMin);

	o.position.x -= o.speed.x * GetFrameTime();


	
}

void drawObstacle(Obstacle& o)
{
	DrawRectangle(static_cast<int>(o.position.x), static_cast<int>(o.position.y), o.width, o.height, RED);
}

void unloadObstacle()
{
}
