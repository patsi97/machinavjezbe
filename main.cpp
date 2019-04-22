#include <iostream>
#include <string>

//klase - "kontejner" za varijable
//funkcije unutar klasa su metode

class Player {

public:
	Player(int positionX, int positionY, int currentVelocity, int hitPoints)
	{
		x = positionX;
		y = positionY;
		velocity = 10;
		hp = hitPoints;
	}

	int x, y, velocity, hp, strength;
	std::string userName;

	void move() {
		x += velocity;
		y += velocity;

	}
	void damage(int amount) {
		hp -= amount;
	}

};

void move(int& x, int& y, int& velocity) {

	x += velocity;
	y += velocity;
}

int main()
{
	Player playerOne = Player(0, 0, 10, 30);
	playerOne.userName = "Chaos";
	playerOne.strength = 12;

	Player playerTwo = Player(10, 15, 10, 30);
	playerTwo.userName = "Robi256";
	playerTwo.strength = 11;


	playerOne.move();
	playerTwo.move();

	std::string losingPLayer;
	std::string winningPlayer;

	while (playerOne.hp > 0 && playerTwo.hp > 0) 
	{
		int check;
		std::cout << "Chose which player you want to hit: ";
		std::cin >> check;
		std::cout << std::endl;

		std::cin.ignore(1000, '\n');
		std::cin.clear();

		switch (check)
		{
		case 1:
			playerOne.damage(playerTwo.strength);
			std::cout << "Player one lost 5 hitpoints" << std::endl;
			break;
		case 2:
			playerTwo.damage(playerOne.strength);
			std::cout << "Player two lost 5 hitpoints" << std::endl;
			break;
		default:
			break;
		}
		std::cout << "Player one: " << playerOne.hp << std::endl;
		std::cout << "Player two: " << playerTwo.hp << std::endl;
		std::cout << std::endl;

		if (playerOne.hp <= 0) {
			losingPLayer = playerOne.userName;
			winningPlayer = playerTwo.userName;
		}
		else if (playerTwo.hp <= 0) {
			losingPLayer = playerTwo.userName;
			winningPlayer = playerOne.userName;
		}
	}

	std::cout << winningPlayer << "  wins! Congratulations! " << std::endl;
	std::cout << losingPLayer << "  lost! Better luck next time! " << std::endl;

	//napraviti treceg playera, te postaviti moguænost za biranje usernamea(korisnik sam unosi username)
	//prosiriti moguænost damaganja playera tako da se bira koji æe kojeg udariti;


	std::cin.get();
}