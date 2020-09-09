#include <iostream>
using namespace std;
#include "Vehicle.cpp"
#include "Car.cpp"

int main() {
	// Vehicle v;

	Car c;

	/*
	Car c;

	v.print();

	c.print();


	Vehicle *v1 = new Vehicle;

	Vehicle *v2;
	// v2 = &v;

	v2 = &c;

	v1 -> print();

	v2 -> print();
	*/

}

/*
Pure Virtual functions are those which do not have any definitions
            virtual returnType functionName() = 0;
Any class containing a pure virtual function becomes an abstract function.

Abstract means incomplete. So, abstact cllases are incomplete as they contain a virtual function without definition.

We can't create object of a abstract class. It will give an error, because when we create objects, all it's properties are initialized but if one of it's properties isi incomplete, how can we initialize that incomplete property. That's why we can not create an object of a abstract class.

If a class inherits a abstract class then it has two options:
1. implement all the pure virtual functions
2. leave the pure virtual functions for one of it's derive classes to implement. But this will make the class a abstract class itself as it has inherited the pure virtual functions from it's parent class so, it's incomplete too.

When we can not make a decision in our current class then we make the function pure virtual function so that a derived class can take the decision or if we want to force the derived class to implement some functionality, we use pure virtual function.

*/