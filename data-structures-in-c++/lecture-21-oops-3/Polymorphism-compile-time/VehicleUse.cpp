#include <iostream>
using namespace std;
#include "Vehicle.cpp"
#include "Car.cpp"

int main() {
	Vehicle v;

	Car c;

	v.print();

	c.print();


	Vehicle *v1 = new Vehicle;

	Vehicle *v2;
	// v2 = &v;

	v2 = &c; 

	v1 -> print();

	v2 -> print(); // The print() function of Vehicle that was inherited by Car is called

    cout << v2 -> num2 << endl;
    // cout << v2 -> num1 << endl; // It is not inherited by Car so we can't call it.

}

