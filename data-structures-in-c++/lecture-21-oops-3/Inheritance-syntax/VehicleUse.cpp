#include <iostream>
using namespace std;
#include "Vehicle.cpp"
#include "Car.cpp"

int main() {
	Vehicle v;

	v.color = "Blue"; // It is accessible as it is a public property of the Vehicle Class
	// v.maxSpeed = 100;
	// v.numTyres = 4; // It is protected member of the Vehicle class and it is only accessible by it's derived class


	Car c;
	c.color = "Black";
//	c.numTyres = 4;
	c.numGears = 5; // public property of the Car class


}

