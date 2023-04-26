#pragma once
#include "Nave.h"
#include "functions.h"
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
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
};

