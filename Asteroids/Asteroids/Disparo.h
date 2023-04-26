#pragma once
#include "raylib.h"
class Proyectil
{
public:
	Proyectil(Vector2 pos,Vector2 dir);
	~Proyectil();
	void update(Vector2 pos, Vector2 dir);
	void mover();
	void Draw();
	bool colision();
	Vector2 getPosition();
private:
	Vector2 position;
	Vector2 direction;
	float speed=10.0f;
};

