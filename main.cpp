#include <iostream>
#include <string>
#include <vector>


//po defaultu visibility klase je private!
//
//po defaultu visibility structure je public!
//kontejner podataka i manipulacija sa specifiènim podacima
/*class Entity 
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
*/


class Person {

public:
	Person(std::string givenName, std::string givenLastName, std::string givenAdress) {
		_name = givenName;
		_lastName = givenLastName;
		_adress = givenAdress;
	}
	~Person();

	bool trySetSSN(std::string ssn) {
		if (_socialSecurityNumber != "") {
			std::cout << "Social security Number is already set!" << std::endl;
			std::cout << "Persons SSN cannot be changed!" << std::endl;
			return true;
		}
		if (ssn.size() != 11) {
			std::cout << "Social security number is invalid! Wrong number of characters!";
			return false;
		}
		for (size_t i = 0; i < ssn.size(); i++)
		{
			char current = ssn[i];
			if (current <= 48 || current => 57) {
				std::cout << "Social security number is invalid!" << std::endl;
				std::cout << "Character at index" << i << "is invalid" << std::endl;
				return false;
			}
		}
		_socialSecurityNumber = ssn;
		return true;
	}

	void print()
	{
		std::cout << "Name:" << _name << " " << _lastName << std::endl;
		std::cout << "Adress" << _adress << std::endl;
		std::cout << "Social security number" << _socialSecurityNumber << std::endl;
	}

private:
	std::string _name, _lastName, _adress, _socialSecurityNumber;
};

void displayPersons(std::vector<Person> persons) {
	for (size_t i = 0; i < persons.size(); i++)
	{
		persons[i].print();
	}
	}

void createPerson(std::vector<Person>& persons) {
	std::string name, lastName, adress;

	inputNewData("Enter new persons last name:", name);
	inputNewData("Enter new persons last name:", lastName);
	inputNewData("Enter new persons last name:", adress);


	Person person = Person(name, lastName, adress);

	while (true)
	{
		std::string ssn;
		inputNewData("Enter new social security number: ", ssn);
		
		if (person.trySetSSN(ssn)) {
			persons.push_back(person);
			return;
		}
	
	std::cin.clear();
	std::cin.ignore(10000, '\n');
}

}

void inputNewData(std::string message, std::string& data) {
	std::cout << message << std::endl;
	std::cin >> data;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
}


int main() {
	
	//Zadatak napraviti klasu osobe, sadržaja ime, prezime, adresa, oib;
	//Konstrukor treba inicijalizirati sve membere osim oiba
	//posebna metoda za setanje oiba jel valjan ili postojeæi, na temelju toga 
	//namjestiti oib
	//napraviti program koji omoguæuje izradu novih osoba

	//vektori - polja istog tipa, 
	//CTR + R - rename svih varijabli istog imena

	Person person = Person(name, lastName, adress);

	std::vector<Person> persons;

	bool valid = true;
	while (valid) {
		std::cout << "What do you want to do:" << std::endl;
		std::cout << "1-Add new person" << std::endl;
		std::cout << "2-Exit" << std::endl;

		int choice;

		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(10000, '\n');

		switch (choice) {
		case 1:
			createPerson(persons);
			break;
		case 2:
			valid = false;
			break;
		default:
			break;

		}
	}

	displayPersons(persons);
	
	std::cin.get();
}
