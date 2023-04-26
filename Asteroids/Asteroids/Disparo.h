#pragma once
#include "raylib.h"
class Proyectil
{
public:
	Proyectil(Vector2 pos,Vector2 dir);
	~Proyectil();
private:
	Vector2 position;
	Vector2 direction;
	float speed=10.0f;
};

