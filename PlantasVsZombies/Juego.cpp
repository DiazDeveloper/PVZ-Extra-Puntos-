#include "Juego.h"

Juego::Juego(int widht, int height)
{
	background = new Background();
	player = new Player(10, 150); 

	Random r;
	for (int i = 0; i < 5; i++)
	{
		int direccion = r.Next(1, 3);
		int tipo = r.Next(1, 8);
		int PosicionX = r.Next(0, widht - 57);
		int PosicionY = r.Next(0, height - 57);
		enemies.push_back(new Enemy(PosicionX, PosicionY, direccion, tipo));
	}
}

void Juego::mostrar(Graphics^ graphics)
{
	background->mostrar(graphics);
	player->mostrar(graphics);

	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i]->mostrar(graphics);
	}
}

void Juego::mover(Graphics^ graphics)
{
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i]->mover(graphics); 
	}
}

void Juego::moverTeclas(Graphics^ graphics, Movimiento movimiento)
{
	player->MoverTeclar(graphics, movimiento); 
}
