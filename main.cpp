#include <iostream>
#include <string>
#include <vector>

//abstrakcija - 
//polimorfizam - 
//enkapsulacija - 
class Human
{
public:
	
	int hands;
	int feet;
	int eyes;

	void PrintType()
	{
		std::cout << "I am a human being!" << std::endl;
	}

private:

};

class Male : public Human
{

};

class Female : public Human
{

};


int main() {
	Human maleObject;
	maleObject.hands = 2;
	maleObject.feet = 2;
	maleObject.eyes = 2;

	maleObject.PrintType();
	std::cin.get();

}