#include <iostream>
#include <string>

//& referenca - ne zauizna memoriju, nije varijabla, prati promjenu varijable
//* pointer - integer sadrži broj adrese u memoriji
//tip pointera nije bitan ako radimo samo sa adresama
//** dupli pointer - 

int main()
{
	int number = 5;
	int& tracker = number;
	int* ptr = &number;
	
	std::string* stringptr;
	std::string someWord = "nesto";
	
	stringptr = &someWord;
	int** doubleptr = &ptr;

	number = 9;
	std::cout << "Hello World" << std::endl;
	std::cout << "number:" << number << std::endl;
	std::cout << "tracker:" << tracker << std::endl;
	std::cout << "number" << ptr << std::endl;

	std::cout << "stringptr: " << stringptr << std::endl;
	std::cout << "derefference stringptr: " << *stringptr << std::endl;
	*stringptr = "nesto drugo";

	std::cout << "derefference stringptr take 2: " << *stringptr << std::endl;
	std::cout << "doubleptr ptr adress " << *doubleptr << std::endl;
	std::cout << "doubleptr ptr adress " << **doubleptr << std::endl;

	std::cin.get();
}