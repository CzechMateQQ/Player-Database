#pragma once
#include <iostream>

class Player
{
public:
	Player();
	~Player();

	void defend(Player _player, float enemyAttack);
	void buy(Player _player, int cost);
	void sell(Player _player, int price);

	char name[10];
	float health;
	float attack;
	float defense;
	int gold;
	bool alive;
};

