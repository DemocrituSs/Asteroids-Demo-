#include "Game.h"
#include <string>
#include<ctime>

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
	//A->randomDir();
	//A->randomPos();
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Asteroide* Ast = new Asteroide();
		Asteroides.push_back(Ast);
	}
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
	disparo = jugador->disparar();
	//A->mover();
	if (disparo)
	{
		Proyectil* PUM = new Proyectil(jugador->getCentro(), jugador->getDireccion());
		Disparos.push_back(PUM);
	}
}
void Game::UpdateGame()
{
	for (auto A : Asteroides)
	{
		A->mover();
		A->colisionPantalla(Pantalla);
	}
	for (auto P: Disparos)
	{
		P->mover();
	}
	ColisionDispAsteroide();
	Disparos.erase(std::remove_if(Disparos.begin(), Disparos.end(), [](Proyectil* d) {
		return !d->vive();
		}), Disparos.end());
	jugador->colisionPantalla(Pantalla);
	jugador->actualizar();
	jugador->actualizarCentro();
	jugador->actualizardireccion();
}
void Game::GenerateOutput()
{
	BeginDrawing();
	ClearBackground(BLACK);
	jugador->Draw();
	cont_Proyectiles = 0;
	for (auto P : Disparos)
	{
		P->Draw();
		cont_Proyectiles++;
	}
	for (auto A : Asteroides)
	{
		if (A->vive())
		{
			A->Draw();
		}
	}
	/*
	if (dibujar)
	{
		A->Draw();
	}
	*/
	//DrawTriangleLines(v1, v2, v3, WHITE);
	std::string texto = "Puntos: " + std::to_string(Puntuacion);
	DrawText(texto.c_str(),10,10,20,WHITE);
	EndDrawing();
}
void Game::ColisionDispAsteroide()
{
	for (auto P : Disparos)
	{
		for (auto A : Asteroides)
		{
			if (CheckCollisionPointCircle(P->getPosition(), A->getCenter(), A->getRadio()))
			{
				P->destroid();
				A->destroid();
				Puntuacion += 10;
			}
		}
	}
}