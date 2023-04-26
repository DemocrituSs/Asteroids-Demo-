#include "Asteroid.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Asteroide::Asteroide()
{
	randomDir();
	randomPos();
}
Asteroide::~Asteroide()
{

}
void Asteroide::Draw()
{
	if (vida==true)
	{
		DrawPolyLines(center, 12, Radio, 0.0, WHITE);
	}
}
void Asteroide::mover()
{
    center.x += direccion.x;
    center.y += direccion.y;
}
void Asteroide::setDir(Vector2 dir)
{
    direccion = dir;
}
void Asteroide::randomDir()
{
    srand(time(NULL));
    float x = ((float)rand() / RAND_MAX)*2.0-1.0;
    float y = ((float)rand() / RAND_MAX) * 2.0 - 1.0;
    this->direccion.x = 2 * x;
	this->direccion.y = 2 * y;
}
void Asteroide::colisionPantalla(Rectangle pantalla)
{
	if (center.x - Radio > pantalla.width)
	{
		center.x += center.x - pantalla.width;
	}
	if (center.x + Radio < 0)
	{
		center.x = center.x + pantalla.width;
	}
	if (center.y - Radio < 0)
	{
		center.y = center.y + pantalla.height;
	}
	if (center.y + Radio > pantalla.height)
	{
		center.y = center.y - pantalla.height;
	}
}
void Asteroide::randomPos()
{
	float x = 0; float y = 0;
	srand(time(NULL));
	do
	{
		x = ((float)rand() / RAND_MAX) * 800;
		y = ((float)rand() / RAND_MAX) * 600;
	} while (CheckCollisionPointCircle({ x,y }, {400,300},60));
	center = { x,y };
}