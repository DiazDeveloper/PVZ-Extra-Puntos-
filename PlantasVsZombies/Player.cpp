#include "Player.h"

Player::Player(int x, int y) : Entidad(x, y, "imagenes/zombies1.png", 3, 4)
{
	dx = dy = 10;  // movimiento jugador 
	movimiento = Abajo;
}

void Player::MoverTeclar(Graphics^ canvas, Movimiento movimiento)
{
	this->movimiento = movimiento;
	switch (movimiento)
	{
	case Arriba:
		y -= dy;
		indiceAlto = 0;
		break;
	case Abajo:
		y += dy;
		indiceAlto = 2;
		break;
	case Derecha:
		x += dx;
		indiceAlto = 1;
		break;
	case Izquierda:
		x -= dx;
		indiceAlto = 3;
		break;
	default:
		break;
	}
	if (x < 0)
	{
		x = 0;
	}

	if (y < 0)
	{
		y = 0;
	}

	if (x + ancho > canvas->VisibleClipBounds.Width)
	{
		x = canvas->VisibleClipBounds.Width - ancho;
	}

	if (y + alto > canvas->VisibleClipBounds.Height)
	{
		y = canvas->VisibleClipBounds.Height - alto;
	}

	indiceAncho++;
	if (indiceAncho > 2)
	{
		indiceAncho = 0;
	}

}

Movimiento Player::getMovimiento()
{
	return movimiento;
}
