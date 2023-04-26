#pragma once
#include "raylib.h"
#include "functions.h"
#include "utilidades.h"

class Nave
{
private:
	//Texture2D texture;
	//Rectangle Rec;
	//Vertices
public:
	Vector2 v1;
	Vector2 v2;
	Vector2 v3;
	Vector2 center;
	Vector2 direction;
	float radio=50/3;
	int Speed=1;
	//Ángulo de rotación
	float angle = 0.0f;
	int life = 3;
	Nave();
	//Nave(float posX, float posY);
	Nave( int ancho, int largo);
	~Nave();
	void actualizardireccion();
	void actualizarCentro();
	void move();
	void Draw();
	void rotar(float angle);
	void colisionPantalla(Rectangle pantalla);
	bool disparar();
	//Setters
	void SetPosition();
	void SetRotation();
	void SetSpeed();
	//Getters
};

