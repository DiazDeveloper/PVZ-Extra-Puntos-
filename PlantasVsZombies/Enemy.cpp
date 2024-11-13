#include "Enemy.h"

Enemy::Enemy(int x, int y, int direccion, int tipo) : Entidad(x, y, "imagenes/plantas.png", 8, 1)
{
	dx = dy = 15;
	this->direccion = direccion;
	this->tipo = tipo; 
	this->indiceAncho = tipo;
}

void Enemy::mover(Graphics^ canvas)
{
	if (direccion == 1)
	{
		if (x + ancho > canvas->VisibleClipBounds.Width || x < 0)
		{
			dx *= -1;
		}

		x += dx;
	}

	else
	{
		if (y + alto > canvas->VisibleClipBounds.Height || y < 0)
		{
			dy *= -1;
		}

		y += dy;
	}

}
