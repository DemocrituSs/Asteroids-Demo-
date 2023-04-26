#pragma once
#include "Nave.h"
class Asteroide
{
    Vector2 direccion = { 1.0f,1.0f };
    float Radio = 40.0f;
    Vector2 center = { 800 / 2, 600 / 2 };
    int size = 12;
    bool vida = true;
public:
	Asteroide();
	~Asteroide();
    void Draw();
    void randomDir();
    void mover();
    void setDir(Vector2 dir);
    void colisionPantalla(Rectangle pantalla);
    void randomPos();
    Vector2 getCenter();
    float getRadio();
    void destroid();
    bool vive() { return vida; };
    // inicializar();
};

