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
	playerOne.userName = "Player1";
	playerOne.strength = 12;

	Player playerTwo = Player(10, 15, 10, 30);
	playerTwo.userName = "Player2";
	playerTwo.strength = 11;

	Player playerThree = Player(0, 0, 10, 30);
	playerThree.userName = "Player3";
	playerThree.strength = 12;
	
	
	playerOne.move();
	playerTwo.move();
	playerThree.move();

	std::string losingPlayer;
	std::string winningPlayer;
	
	int playerNumber;
	std:: string username;
	
	
	
	
	std::cout<< "Enter which player you want to be (1,2,3) ";
	std::cin >> playerNumber;
	
	std::cout<< "Enter your username: ";
	std::cin >> username;
	
			switch (playerNumber)
		{
		case 1:
			playerOne.userName = username;
			break;
		case 2:
			playerTwo.userName = username;
			break;
		case 3:
			playerThree.userName = username;
			break;
		default:
			break;
		
}
	while (playerOne.hp > 0 && playerTwo.hp > 0 && playerThree.hp > 0) 
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
			std::cout << "Player " << playerOne.userName <<" lost 5 hitpoints" << std::endl;
			break;
		case 2:
			playerTwo.damage(playerOne.strength);
			std::cout << "Player "<< playerTwo.userName <<" lost 5 hitpoints" << std::endl;
			break;
		case 3:
			playerThree.damage(playerThree.strength);
			std::cout << "Player "<< playerThree.userName <<" lost 5 hitpoints" << std::endl;
		default:
			break;
		}
		std::cout << "Player " << playerOne.userName <<  " hp: " << playerOne.hp << std::endl;
		std::cout << "Player " << playerTwo.userName <<  " hp: " << playerTwo.hp << std::endl;
		std::cout << "Player " << playerThree.userName <<  " hp: " << playerThree.hp << std::endl;
		std::cout << std::endl;

		if (playerOne.hp <= 0) {
			losingPlayer = playerOne.userName;
			winningPlayer = playerTwo.userName;
		}
		else if (playerTwo.hp <= 0) {
			losingPlayer = playerTwo.userName;
			winningPlayer = playerOne.userName;
		}else if(playerThree.hp <=0){
			losingPlayer = playerThree.userName;
			winningPlayer = playerOne.userName;
		}
	}

	std::cout << winningPlayer << "  wins! Congratulations! " << std::endl;
	std::cout << losingPlayer << "  lost! Better luck next time! " << std::endl;


	//napraviti treceg playera, te postaviti moguænost za biranje usernamea(korisnik sam unosi username)
	//prosiriti moguænost damaganja playera tako da se bira koji æe kojeg udariti;


	std::cin.get();
}

