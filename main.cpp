#include <iostream>
#include <string>
#include <vector>


//po defaultu visibility klase je private!
//
//po defaultu visibility structure je public!
//kontejner podataka i manpulacija sa specifiènim podacima

class Entity 
{
public:
	Vector3 position;
private:
	std::string name;

};

struct Vector3 
{
	float x, y, z;
};

class Player : public Entity
{
public:

	Vector3 getPosition() {
		return position;
	}
	
	

};

class Enemy : public Entity
{
public:
	Vector3 getPosition() {
		return position;
	}

};

class Osoba {

public:
	std::string ime, prezime, adresa;


};

int main() {
	Entity entity = Entity();
	Vector3 vector = Vector3();

	Player player = Player();
	Enemy enemy = Enemy();

	player.position;
	enemy.position;

	
	//Zadatak napraviti klasu osobe, sadržaja ime, prezime, adresa, oib;
	//Konstrukor treba inicijalizirati sve membere osim oiba
	//posebna metoda za setanje oiba jel valjan ili postojeæi, na temelju toga 
	//namjestiti oib
	//napraviti program koji omoguæuje izradu novih osoba


	std::vector<> persons;

	std::cin.get();
}
