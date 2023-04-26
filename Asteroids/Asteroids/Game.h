#pragma once
#include "Nave.h"
#include "functions.h"
#include <vector>
class Game
{
public:
	Game();
	~Game();
	void Initialize();
	void Runloop();
	void Shutdown();
private:
	//Atributos
	//float radio = 50 / 3;
	Rectangle Pantalla = { 0,0,800,600 };
	Nave* jugador = new Nave(800,600);
	std::vector<Proyectil*> Disparos;
	std::vector<Asteroide*> Asteroides;
	//Asteroide* A = new Asteroide();
	int cont_Asteroides=0;
	int Puntuacion = 0;
	int vidaJugador = 3;
	bool disparo;
	bool dibujar = true;
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void ColisionDispAsteroide();
	void colisionNave();
	void condicionesIniciales();
	void NuevosAsteroides();
};

