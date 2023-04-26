#pragma once
#include "raylib.h"
#include "Asteroid.h"

class Asteroide;
class Proyectil
{
public:
	Proyectil(Vector2 pos,Vector2 dir);
	~Proyectil();
	void update(Vector2 pos, Vector2 dir);
	void mover();
	void Draw();
	//bool colision();
	void colision(Asteroide* A);
	Vector2 getPosition();
	void destroid() { vida = false; };
	bool vive() { return vida; };
private:
	Vector2 position;
	Vector2 direction;
	float speed=10.0f;
	bool vida = true;
};

