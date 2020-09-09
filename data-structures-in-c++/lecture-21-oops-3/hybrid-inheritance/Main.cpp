#include <iostream>
using namespace std;
#include "Vehicle.cpp"
#include "Car.cpp"
#include "Truck.cpp"
#include "Bus.cpp"

int main() {
	Bus b;

	b.print();

	//b.Car :: print(); // Car's print() is called. If Car does not have then Vehicle's print() is called

}

/*
When Bus constructor is called, Car class's constructor is called which will in turn call Vehicle class's constructor first. After Car's concstructor is called, now Trucks constructor is going to be called which in turn first call Vehicle's constructor and now Bus's constructor will be called.
            Vehicle(Due to Car) -> Car -> Vehicle(Due to Truck) -> Truck -> Bus

Bus is inheriting both Car and Truck who have inherited Vehicle. So, Bus has inherited Vehicle twice through them which will create ambiguity. So, the DIAMOND PROBLEM has occured.

To get rid of this ambiguity we can do any of the following:
1. define a print() function(function that is creating ambuguity) in Bus(last level derived class) itself. But Vehicle is still inherited twice.
2. We can expliitly mention the class whose function we want to use to get rid of the ambuguity. But Vehicle is still inherited twice.

Two stop inheriting of Vehicle twice, we need to make sure that Vehicle is inherited 'virtual'-ly by both Truck and Car.
'virtual' will make sure that Vehicle is not inherited twice.
*/

