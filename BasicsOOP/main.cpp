#include <iostream>
#include <string>
#include <vector>

//abstrakcija 
//polimorfizam 
//enkapsulacija 
//naslje�ivanje
class Human
{
public:

	int hands;
	int feet;
	int eyes;

	virtual void PrintType()
	{
		std::cout << "I am a human being!" << std::endl;
	}

private:

};

class Male : public Human
{
public:
	void PrintType()
	{
		std::cout << "I am a male human being!" << std::endl;
	}
};

class Female : public Human
{
public:
	void PrintType()
	{
		std::cout << "I am a female human being!" << std::endl;
	}
};


int main()
{
	Male* maleObject = new Male();
	
	maleObject->hands = 2;
	maleObject->feet = 2;
	maleObject->eyes = 2;

	Female* femaleObject = new Female();

	femaleObject->PrintType();
	maleObject->PrintType();
	

	//zbog naslje�ivanja imamo ovu mogu�nost, ali �e se ispisati human object, a ne female object
	Human* humanObject = new Human();
	humanObject->PrintType();
	
	std::vector<Human*> humans;
	humans.push_back(maleObject);
	humans.push_back(femaleObject);
	humans.push_back(humanObject);

	std::cout << "===============================" << std::endl;
	for (size_t i = 0; i < humans.size(); i++)
	{
		humans[i]->PrintType();
	}
	std::cin.get();

}