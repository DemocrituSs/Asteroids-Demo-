#pragma once
#include "functions.h"
#include "Disparo.h"
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
	float speed=0.0f;
	//Ángulo de rotación
	float angle = 0.0f;
	int life = 3;
	Nave();
	//Nave(float posX, float posY);
	Nave( int ancho, int largo);
	~Nave();
	void actualizar();
	void actualizardireccion();
	void actualizarCentro();
	void move();
	void Draw();
	void rotar(float angle);
	void colisionPantalla(Rectangle pantalla);
	bool disparar();
	//Setters
	void SetPositionInicial();
	//void SetRotation();
	//void SetSpeed();
	//Getters
	Vector2 getDireccion();
	Vector2 getCentro();
};

