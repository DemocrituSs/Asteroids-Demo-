#include "Game.h"
#include <string>

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
	disparo = jugador->disparar();
	if (disparo)
	{
		Proyectil* PUM = new Proyectil(jugador->getCentro(), jugador->getDireccion());
		Disparos.push_back(PUM);
	}
}
void Game::UpdateGame()
{
	for (auto P: Disparos)
	{
		P->mover();
	}
	Disparos.erase(std::remove_if(Disparos.begin(), Disparos.end(), [](Proyectil* d) {
		return d->getPosition().x < 0 || d->getPosition().x > 800 || d->getPosition().y < 0 || d->getPosition().y > 600;
		}), Disparos.end());
	/*
	for (auto it = Disparos.begin(); it !=Disparos.end(); ) {
		if (it->getPosition().x<0) {
			it = Disparos.erase(it); // borramos el elemento y actualizamos el iterador
		}
		else if (it->getPosition().x > 800)
		{
			it = Disparos.erase(it);
		}
		else if (it->getPosition().y < 0)
		{
			it = Disparos.erase(it);
		}
		else if (it->getPosition().y > 600)
		{
			it = Disparos.erase(it);
		}
		else {
			++it; // avanzamos al siguiente elemento
		}
	}*/
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
	//DrawTriangleLines(v1, v2, v3, WHITE);
	std::string texto = "cant proyectiles " + std::to_string(cont_Proyectiles);
	DrawText(texto.c_str(),10,10,20,WHITE);
	EndDrawing();
}