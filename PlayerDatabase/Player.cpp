#include "Player.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::assignName(Player& _player, int i)
{
	cout << "Enter name for player" << "[" << i << "]" << ", 9 characters or less:" << endl;
	cin >> _player.name;
	//Invalid input check
	while (sizeof(_player.name) > 10)
	{
		cout << "Name too long, please try again:" << endl;
		cin >> _player.name;
	}
}

void Player::defend(Player& _player)
{
	//Initialize random eenmy attack value
	float enemyAttack;
	srand(time(NULL));
	enemyAttack = rand() % 20 + 80;
	if ((enemyAttack - _player.defense) > 0)
	{
		_player.currentHealth -= (enemyAttack - _player.defense);
		cout << "Enemy attacks " << _player.name << " for " << 
				(enemyAttack - _player.defense) << " damage! " << 
				_player.currentHealth << " health remaining." << endl;
	}

	//If player defense exceeds enemy attack
	else
	{
		cout << "Enemy's attack misses!" << endl;
	}

	//Dead player
	if (_player.currentHealth <= 0)
	{
		_player.alive = false;
	}
}

void Player::buy(Player& _player)
{
	//Store
	int playerInput;
	cout << "What would you like to buy?" << endl;
	cout << "Select item number:\n" <<
		"1) Stick of Stamina: 78g\n" <<
		"2) Fire Staff: 163g\n" <<
		"3) Celestial Sledge Hammer: 327g\n" <<
		"4) Demon Hide: 84g\n" <<
		"5) Adamantite Armor: 135g" << 
		"6) Health Pot: 25g" << endl;

	cin >> playerInput;
	switch (playerInput)
	{
		case 1: _player.magicPower += 20;
			_player.gold -= 78;
			cout << _player.name << "'s magic power increased by 20." << endl;
			cout << _player.gold << " gold remaining." << endl;
			break;
		case 2: _player.magicPower += 100;
			_player.gold -= 163;
			cout << _player.name << "'s magic power increased by 100." << endl;
			cout << _player.gold << " gold remaining." << endl;
			break;
		case 3: _player.magicPower += 500;
			_player.gold -= 327;
			cout << _player.name << "'s magic power increased by 500." << endl;
			cout << _player.gold << " gold remaining." << endl;
			break;
		case 4: _player.defense += 25;
			_player.gold -= 84;
			cout << _player.name << "'s defense power increased by 25." << endl;
			cout << _player.gold << " gold remaining." << endl;
			break;
		case 5: _player.defense += 35;
			_player.gold -= 135;
			cout << _player.name << "'s defense power increased by 35." << endl;
			cout << _player.gold << " gold remaining." << endl;
			break;
		case 6: _player.currentHealth += 50;
			_player.gold -= 25;
			cout << _player.name << "'s current health increased by 50." << endl;
			cout << "Health: " << _player.currentHealth << endl;
			cout << _player.gold << " gold remaining." << endl;
			break;
	}
}

//Level up increases player stats
void Player::levelUp(Player& _player)
{
	_player.maxHealth += 50;
	_player.currentHealth = _player.maxHealth;
	_player.defense += 10;
	_player.magicPower += 75;
	cout << _player.name << "'s Max Health increased by 50, Defense increased by 10, " <<
		"and Magic Power increased by 100.\n" << endl;
}
