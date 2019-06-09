#include <iostream>
#include <string>
#include <vector>

//Polimorfizam radi samo na heapu! Ne na stacku! Omoguæuje transformaciju objekata iste hijerarhije,
//da možemo lakše grupirati podatke
//enkapsulacija 
//nasljeðivanje
//pure virtual function - funckija bez implementacije, used for interface


/*class Human
{
public:

	int hands;
	int feet;
	int eyes;

	virtual void PrintType()
	{
		std::cout << "I am a human being!" << std::endl;
	}
	//pure virtual funtion - has no implementation, no instance
	virtual int getNumberOfHands() = 0;

private:

};

class Male : public Human
{
public:
	void PrintType()
	{
		std::cout << "I am a male human being!" << std::endl;
	}
	//virtual funtion implemented here
	int getNumberOfHands() 
	{
		return hands;
	}

};

class Female : public Human
{
public:
	void PrintType()
	{
		std::cout << "I am a female human being!" << std::endl;
	}
	int getNumberOfHands() {
		return hands;
	}
	
};


int main()
{
	//Pointer na memoriju heapa, ne èisti se nakon izlaska iz ove funkcije
	//memory leak - we don't have pointer on memory adress, cant access
	Male* maleObject = new Male();
	
	maleObject->hands = 2;
	maleObject->feet = 2;
	maleObject->eyes = 2;

	maleObject->PrintType();
	Female* femaleObject = new Female();

	femaleObject->PrintType();
	
	
	//zbog nasljeðivanja imamo ovu moguænost, ali æe se ispisati human object, a ne female object
	//Human* humanObject = new Human();
	//humanObject->PrintType();
	
	std::vector<Human*> humans;
	humans.push_back(maleObject);
	humans.push_back(femaleObject);
	//humans.push_back(humanObject);

	std::cout << "===============================" << std::endl;
	for (size_t i = 0; i < humans.size(); i++)
	{
		humans[i]->PrintType();
		std::cout << humans[i]->getNumberOfHands() << std::endl;
	}
	std::cin.get();
	//good practice to delete from heap on the end of function
	delete femaleObject;
	delete maleObject;
}
*/

//ZADATAK:
//Napraviti interface Shape koji ima metode Area i Size 
//Napraviti klase Triangle, Circle, Square koji implementiraju interface Shape
//Napraviti objekte svake podklase i ispisati Area i Size!

class Shape
{
public:
	
	virtual double getArea() = 0; 
	virtual double getPerimeter() = 0;
	virtual std::string getName() = 0;
private:
	 
};

class Triangle:public Shape
{
public:
	
	float a, b, c;

	double getPerimeter() {
		return a+b+c;
	}
	double getArea() {
		double s = getPerimeter()/2;
		return sqrt(s*(s - a)*(s - b)*(s - c));
	}
	std::string getName() {
		return "Triangle";
	}
};

class Circle: public Shape 
{
public:
	

	float r;
	double getPerimeter() {
		return 2*r*_Pi;
	}
	double getArea() {
		
		return r*r*_Pi/2;
	}
	std::string getName() {
		return "Circle";
	}
private:
	float _Pi = 3.14;
};

class Rectangle: public Shape 
{
public:
	float a, b;

	
	double getPerimeter() {
		return 2 * a + 2 * b;
	}
	double getArea() {
		return a * b;
	}
	std::string getName() {
		return "Rectangle";
	}
};

void printShapeInfo(Shape* shape) {
	
		std::cout << "Shape name " << shape->getName() << std::endl;
		std::cout << "Area " << shape->getArea() << std::endl;
		std::cout << "Perimeter " << shape->getPerimeter() << std::endl;
		std::cout << "=============================" << std::endl;
	}



int main() {

	
	Rectangle* rectangleObject = new Rectangle();
	rectangleObject->a = 5.0f;
	rectangleObject->b = 7.0f;

	Circle* circleObject = new Circle();
	circleObject->r = 10.0f;

	Triangle* triangleObject = new Triangle();
	triangleObject->a = 5.0f;
	triangleObject->b = 7.0f;
	triangleObject->c = 9.0f;
	
	std::vector<Shape*> shapes;
	shapes.push_back(rectangleObject);
	shapes.push_back(circleObject);
	shapes.push_back(triangleObject);
	
	for (Shape* i : shapes)
	{
		printShapeInfo(i);
	}

	std::cin.get();
	return 0;
}