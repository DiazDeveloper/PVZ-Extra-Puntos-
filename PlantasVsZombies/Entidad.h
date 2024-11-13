#pragma once
#include <string>
#include <iostream>
using namespace std;
using namespace System;
using namespace System::Drawing;
enum Movimiento {
	Arriba, Abajo, Derecha, Izquierda, Ninguno
};
class Entidad
{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int indiceAncho;
	int indiceAlto;
	int tipo;
	int vidas;
	char* imagen;
	int framesAncho;
	int framesAlto;
	Movimiento movimiento;
	void cambiarImagen(char* nombreArchivo);
	virtual void dibujarImagen(Graphics^ canvas,
		Bitmap^ sprite, Rectangle zoom, Rectangle corte);
public:
	Entidad();
	Entidad(int x, int y, char* imagen, int framesAncho);
	Entidad(int x, int y, char* imagen, int framesAncho,
		int framesAlto);
	~Entidad();
	virtual void mostrar(Graphics^ graphics);
	virtual void mover(Graphics^ graphics);
	Rectangle getRectangle();
	int getX();
	int getY();
	int getAlto();
	int getAncho();
	bool hayColision(Entidad* entidad);
	int getXAncho();
	int getYAlto();
	void setX(int x);
	void setY(int y);
};