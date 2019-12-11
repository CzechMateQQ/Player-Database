#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;

class Player
{
public:
	Player();
	~Player();

	void assignName(Player& _player, int i);
	void defend(Player& _player);
	void buy(Player& _player);
	void levelUp(Player& _player);
	bool alive;
	char name[10];

protected: 
	float maxHealth = 300.0f;
	float currentHealth = 300.0f;
	float defense = 50.0f;
	int magicPower = 200;
	int gold = 1000;
};

