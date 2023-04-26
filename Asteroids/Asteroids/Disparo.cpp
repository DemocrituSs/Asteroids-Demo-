#include "Disparo.h"
Proyectil::Proyectil(Vector2 pos, Vector2 dir)
{
	position = pos;
	direction = dir;
}
Proyectil::~Proyectil()
{

}
void Proyectil::update(Vector2 pos, Vector2 dir)
{
	position = pos;
	direction = dir;
}
void Proyectil::mover()
{
	position.x += direction.x * 10.0f;
	position.y += direction.y * 10.0f;
}
void Proyectil::Draw()
{
	::DrawCircle((int)position.x, (int)position.y, 3, WHITE);
}
Vector2 Proyectil::getPosition()
{
	return position;
}
bool Proyectil::colision(Asteroide A)
{
	if (CheckCollisionPointCircle(position, A.center, A.Radio))
	{
		return true;
	}
	return false;
}