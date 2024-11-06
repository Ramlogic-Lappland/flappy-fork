//#include "raylib.h"
//
//#include "objects/utils.h"
//#include "objects/player.h"
//#include "objects/obstacle.h"
//#include "scene/gameplayScene.h"
//
//
//
//int screenWidth = 800;
//int screenHeight = 600;
//int screenWidthMin = 0;
//int screenHeightMin = 0;
//
//int main()
//{
//	// Inicialización
//
//	InitWindow(screenWidth, screenHeight, "Mi juego");
//	
//	initGameplay();
//
//	// Loop
//	while (!WindowShouldClose())
//	{
//		// Chequeo de Input
//
//		updateGameplay();
//
//		// Actualización
//
//		// Dibujado
//		BeginDrawing();
//		ClearBackground(WHITE); // system("cls");
//
//		drawGameplay();
//
//		EndDrawing();
//	}
//
//	// Cierre
//	CloseWindow();
//}

#include "game.h"

int main()
{
	run();
}