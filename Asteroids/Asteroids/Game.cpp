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
void Game::condicionesIniciales()
{
	cont_Asteroides = 0;
	Puntuacion = 0;
	vidaJugador = 3;
	jugador->SetPositionInicial();
	NuevosAsteroides();
}
//Métodos más importantes
void Game::Initialize()
{
	SetTargetFPS(60);
	InitWindow(800, 600, "Asteroids");
	condicionesIniciales();
	
}
void Game::Runloop()
{
	while (!WindowShouldClose())
	{
		if (vidaJugador > 0) 
		{
			ProcessInput();
			UpdateGame();
			GenerateOutput();
		}
		else
		{
			condicionesIniciales();
		}
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
	if (cont_Asteroides ==0)
	{
		NuevosAsteroides();
		jugador->SetPositionInicial();
		vidaJugador++;
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
		return !d->vive() || d->getPosition().x < 0 || d->getPosition().x > 800 || d->getPosition().y < 0 || d->getPosition().y > 600;
		}), Disparos.end());
	for (auto it = Asteroides.begin(); it != Asteroides.end();) {
		if (!(*it)->vive()) {
			delete (*it);
			it = Asteroides.erase(it);
		}
		else {
			++it;
		}
	}
	jugador->colisionPantalla(Pantalla);
	colisionNave();
	jugador->actualizar();
	jugador->actualizarCentro();
	jugador->actualizardireccion();
}
void Game::GenerateOutput()
{
	BeginDrawing();
	ClearBackground(BLACK);
	jugador->Draw();
	for (auto P : Disparos)
	{
		P->Draw();
	}
	for (auto A : Asteroides)
	{
		A->Draw();
	}
	std::string texto = "Puntos: " + std::to_string(Puntuacion);
	DrawText(texto.c_str(),10,10,20,WHITE);
	std::string vidas = "Vidas: " + std::to_string(vidaJugador);
	DrawText(vidas.c_str(), 700, 10, 20, WHITE);
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
				cont_Asteroides--;
			}
		}
	}
}
void Game::colisionNave()
{
	for (auto A : Asteroides)
	{
		if (CheckCollisionCircles(A->getCenter(),A->getRadio(),jugador->getCentro(),50/3))
		{
			vidaJugador--;
			jugador->SetPositionInicial();
		}
	}
}
void Game::NuevosAsteroides()
{
	Asteroides.clear();
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Asteroide* Ast = new Asteroide();
		Asteroides.push_back(Ast);
		cont_Asteroides++;
	}
}