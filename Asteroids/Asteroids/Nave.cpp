#include "Nave.h"
#include <cmath>
//métodos útiles
float norma(Vector2 vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
}

Vector2 normalizar(Vector2 vec)
{
	return { vec.x / norma(vec),vec.y / norma(vec) };
}
Vector2 sumar(Vector2 v1, Vector2 v2)
{
	return { v1.x + v2.x,v1.y + v2.y };
}
Vector2 restar(Vector2 v1, Vector2 v2)
{
	return { v1.x - v2.x,v1.y - v2.y };
}
Vector2 rotarVector(Vector2 v, float angulo)
{
	double rad = (double)angulo * PI / 180.0;
	double x = cos(rad) * v.x - sin(rad) * v.y;
	double y = cos(rad) * v.y + sin(rad) * v.x;
	return { (float)x,(float)y };
}
Nave::Nave()
{
	int ancho = 800;
	int largo = 600;
	center = { ancho / 2.0f,largo / 2.0f };
	v1 = { center.x, center.y - (50 / 3) };
	v2 = { center.x - 10, center.y + (50 / 3) };
	v3 = { center.x + 10, center.x + (50 / 3) };
	direction = restar(v1,center);
	direction = normalizar(direction);
}
Nave::Nave(int ancho, int largo)
{
	center = { ancho / 2.0f,largo / 2.0f };
	v1 = {center.x, center.y-(50/3)};
	v2 = { center.x - 10, center.y + (50 / 3) };
	v3 = { center.x + 10, center.y + (50 / 3) };
	direction = restar(v1, center);
	direction = normalizar(direction);
}
/*
Nave::Nave(float posX, float posY)
{

}
*/
Nave::~Nave()
{

}
void Nave::move()
{
	if (IsKeyDown(KEY_UP))
	{
		speed = 3.0f;
		//direction.x *= speed;
		//direction.y *= speed;
		/*
		center = sumar(center, direction);
		v1 = sumar(v1, direction);
		v2 = sumar(v2, direction);
		v3 = sumar(v3, direction);
		*/
	}
	//Rotación

	if (IsKeyDown(KEY_LEFT))
	{
		angle = -10.0f;
		rotar(angle);
	}
	if (IsKeyDown(KEY_RIGHT))
	{
		angle = +10.0f;
		rotar(angle);
	}
	
}
void Nave::Draw()
{
	DrawTriangleLines(v1, v2, v3, WHITE);
}
void Nave::colisionPantalla(Rectangle pantalla)
{
	if (center.x - radio > pantalla.width)
	{
		v1.x = v1.x - pantalla.width;
		v2.x = v2.x - pantalla.width;
		v3.x = v3.x - pantalla.width;
	}
	if (center.x + radio < 0)
	{
		v1.x = v1.x + pantalla.width;
		v2.x = v2.x + pantalla.width;
		v3.x = v3.x + pantalla.width;
	}
	if (center.y - radio <0)
	{
		v1.y = v1.y + pantalla.height;
		v2.y = v2.y + pantalla.height;
		v3.y = v3.y + pantalla.height;
	}
	if (center.y + radio > pantalla.height)
	{
		v1.y = v1.y - pantalla.height;
		v2.y = v2.y - pantalla.height;
		v3.y = v3.y - pantalla.height;
	}
}
bool Nave::disparar()
{
	if (IsKeyPressed(KEY_SPACE))
	{
		return true;
	}
	return false;
}
//Setters
void Nave::SetPosition()
{

}
void Nave::SetRotation()
{

}
void Nave::SetSpeed()
{

}
void Nave::actualizarCentro()
{
	center = { (v1.x + v2.x + v3.x) / 3.0f,(v1.y + v2.y + v3.y) / 3.0f };
}
void Nave::actualizardireccion()
{
	direction = restar(v1, center);
	direction = normalizar(direction);
}
void Nave::rotar(float angle)
{
	v1 = restar(v1,center);
	v1 = rotarVector(v1, angle);
	v1 = sumar(v1,center);
	v2 = restar(v2,center);
	v2 = rotarVector(v2, angle);
	v2 = sumar(v2, center);
	v3 = restar(v3,center);
	v3 = rotarVector(v3, angle);
	v3 = sumar(v3, center);
}
void Nave::actualizar()
{
	if (speed > 3)
	{
		speed = 3.0f;
	}
	direction.x *= speed;
	direction.y *= speed;

	speed *= 0.9f;
	center = sumar(center, direction);
	v1 = sumar(v1, direction);
	v2 = sumar(v2, direction);
	v3 = sumar(v3, direction);
}
Vector2 Nave::getDireccion()
{
	return direction;
}
Vector2 Nave::getCentro()
{
	return center;
}