
#include "Entidad.h"

void Entidad::cambiarImagen(char* nombreArchivo)
{
	strcpy(imagen, nombreArchivo);
	Bitmap^ sprite =
		gcnew Bitmap(gcnew System::String(imagen));
	ancho = sprite->Width / framesAncho;
	alto = sprite->Height / framesAlto;
	delete sprite;
}

void Entidad::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
	canvas->DrawImage(sprite, zoom, corte, GraphicsUnit::Pixel);
}

Entidad::Entidad()
{
}

Entidad::Entidad(int x, int y, char* imagen, int frames)
{
	this->indiceAncho = 0;
	this->indiceAlto = 0;
	this->x = x;
	this->y = y;
	this->imagen = new char[48];
	this->framesAncho = frames;
	this->framesAlto = frames;
	cambiarImagen(imagen);
}

Entidad::Entidad(int x, int y, char* imagen, int framesAncho, int framesAlto)
{
	this->indiceAncho = 0;
	this->indiceAlto = 0;
	this->x = x;
	this->y = y;
	this->imagen = new char[48];
	this->framesAncho = framesAncho;
	this->framesAlto = framesAlto;
	cambiarImagen(imagen);
}

Entidad::~Entidad()
{

}

void Entidad::mostrar(Graphics^ graphics)
{
	//4)
	Bitmap^ sprite = gcnew Bitmap(gcnew System::String(imagen));
	Rectangle corte = Rectangle(indiceAncho * ancho, indiceAlto * alto,
		ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho, alto);
	dibujarImagen(graphics, sprite, zoom, corte);
}

void Entidad::mover(Graphics^ graphics)
{
}

Rectangle Entidad::getRectangle()
{
	return Rectangle(x, y, ancho, alto);
}

int Entidad::getX()
{
	return x;
}

int Entidad::getY()
{
	return y;
}

int Entidad::getAncho()
{
	return ancho;
}

int Entidad::getAlto()
{
	return alto;
}

bool Entidad::hayColision(Entidad* entidad)
{
	return entidad->getRectangle().IntersectsWith(getRectangle());
}

int Entidad::getXAncho()
{
	return getX() + getAncho();
}

int Entidad::getYAlto()
{
	return getAlto() + getY();
}


void Entidad::setX(int x)
{
	this->x = x;
}

void Entidad::setY(int y)
{
	this->y = y;
}

