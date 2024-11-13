#pragma once
#include "Background.h"
#include "Player.h"
#include "Enemy.h"
#include "vector"

class Juego
{
private:
	Background* background;
	Player* player;
	vector <Enemy*> enemies;

public:
	Juego(int widht, int height); 
	void mostrar(Graphics^ graphics);
	void mover(Graphics^ graphics);
	void moverTeclas(Graphics^ graphics, Movimiento movimiento);
};