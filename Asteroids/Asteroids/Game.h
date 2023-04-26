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
	std::vector<Asteroide> Asteroides;
	Asteroide A;
	int cont_Proyectiles=0;
	bool disparo;
	bool dibujar = true;
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
};

