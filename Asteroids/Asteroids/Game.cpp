#include "Game.h"


Game::Game()
{

}
Game::~Game()
{
	//delete jugador;
}
//Métodos más importantes
void Game::Initialize()
{
	SetTargetFPS(60);
	InitWindow(800, 600, "Asteroids");
}
void Game::Runloop()
{
	while (!WindowShouldClose())
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}
void Game::Shutdown()
{
	CloseWindow();
}
//Métodos del loop de juego
void Game::ProcessInput()
{
	jugador->move();
}
void Game::UpdateGame()
{
	jugador->colisionPantalla(Pantalla);
	jugador->actualizarCentro();
	jugador->actualizardireccion();
}
void Game::GenerateOutput()
{
	BeginDrawing();
	ClearBackground(BLACK);
	jugador->Draw();
	//DrawTriangleLines(v1, v2, v3, WHITE);
	EndDrawing();
}