#include <iostream>
#include <conio.h>
#include <string.h>

struct Student {
	int age;
	float height;
};

enum Weekdays {
	Monday = 0,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday,
};

class shape {
	// a e b são private por default - diferente de em structs
	int a, b;
public:
	shape(int comprimento, int largura) {
		a = comprimento;
		b = largura;
		std::cout << "comprimento e: " << a << " largura e: " << b <<
			std::endl;
	}
	void area() {
		std::cout << "Area e de: " << a * b << std::endl;
	}
};

class Shapex {
protected:
	float a, b;
public:
	void setValues(float _length, float _width)
	{
		a = _length;
		b = _width;
		std::cout << "length is: " << a << " width is: " << b <<
			std::endl;
	}
	void setValues(float _radio)
	{
		a = _radio;
		std::cout << "radio is: " << a << std::endl;
	}
	void area() {
		std::cout << "Area is: " << a * b << std::endl;
	}
};

class triangle : public Shapex {
public:
	void area() {
		std::cout << "Area of a Triangle is: " << 0.5f * a * b <<
			std::endl;
	}
};

class circle : public Shapex
{
public:
	void area() {
		std::cout << "Area of a Circle is: " << 3.14f * a * a << std::endl;
	}
};

int main() {
	// start
	int n1 = 42;
	std::cout << "Ola, Mundo " << n1 << "!!!" << std::endl;
	// variables
	bool a1 = false;
	char b1 = 'b';
	float c1 = 3.1416f;
	unsigned int d1 = -82;
	std::cout << "Value of a is : " << a1 << std::endl;
	std::cout << "Value of b is : " << b1 << std::endl;
	std::cout << "Value of c is : " << c1 << std::endl;
	std::cout << "Value of d is : " << d1 << std::endl;
	std::string name = "The Dude";
	std::cout << "String name is : " << name << std::endl;
	// operators
	int a2 = 36;
	int b2 = 5;
	std::cout << "Value of a: " << a2 << "\nValue of b: " << b2 << std::endl;
	std::cout << "Value of a + b is : " << a2 + b2 << std::endl;
	std::cout << "Value of a - b is : " << a2 - b2 << std::endl;
	std::cout << "Value of a * b is : " << a2 * b2 << std::endl;
	std::cout << "Value of a / b is : " << a2 / b2 << std::endl;
	std::cout << "Value of a % b is : " << a2 % b2 << std::endl;
	// loops
	int x = 10;
	int n2 = 0;
	while (n2 < x) {
		std::cout << "value of n is: " << n2 << std::endl;
		n2++;
	}
	//functions
	//arrays
	int matrix[4][4] = { {2, 8, 10, -5},{15, 21, 22, 32},{3, 0, 19, 5},{5, 7, -23, 18} };
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			std::cout << matrix[x][y] << " ";
		}
		std::cout << "" << std::endl;
	}

	// Pointers
	int agex = 10;
	int* location = &agex;
	*location = 12;
	std::cout << location << std::endl;
	std::cout << agex << std::endl;

	int* ptr = nullptr;
	int ages[5] = { 12, 6, 18 , 7, 9 };
	ptr = ages;
	std::cout << *ptr << std::endl;
	ptr++;
	std::cout << *ptr << std::endl;
	std::cout << *(ptr + 3) << std::endl;
	std::cout << *ptr << std::endl;

	//Struct
	Student section[3];
	section[0].age = 17;
	section[0].height = 39.45f;
	section[1].age = 12;
	section[1].height = 29.45f;
	section[2].age = 8;
	section[2].height = 13.45f;
	for (int i = 0; i < 3; i++) {
		std::cout << "student " << i << " age: " << section[i].age <<
			" height: " << section[i].height << std::endl;
	}
	//enums
	Weekdays today;
	today = Friday;
	if (today == Friday) {
		std::cout << "sextou!!!!" << std::endl;
		std::cout << "The weekend is here !!!!" << std::endl;
	}
	else {
		std::cout << "não sextou!!!!" << std::endl;
	}
	//Classes
	shape square(8, 8);
	square.area();
	shape rectangle(12, 20);
	rectangle.area();

	Shapex rectanglex;
	rectanglex.setValues(8.0f, 12.0f);
	rectanglex.area();
	triangle tri;
	tri.setValues(3.0f, 23.0f);
	tri.area();
	circle c;
	c.setValues(5.0f);
	c.area();

	_getch();
	return 0;
}