#include <iostream>
using namespace std;

class Bus {
	public :
		void print(); // print declared
};

void test(); // test declared

class Truck {
	private :
		int x;

	protected :
		int y;

	public :
		int z;

		friend class Bus;

	// friend void Bus :: print(); // Bus class's print function is made friend function of the Truck class
    
    // friend class
    friend class Bus; // Now all the members of the Bus class has access to all the members(including private and public) of the Truck class
    // Bus is a friend class of Truck but the vice-versa is not true

	friend void test(); // test is made friend function of Truck class 
	

};

void Bus :: print() { // print is able to access all the private and protected properties of Truck
	Truck t;
	t.x = 10;
	t.y = 20;
	cout << t.x << " " << t.y << endl;
}

void test() { // test is able to access all the private and protected properties of Truck
	// Access truck private
	Truck t;
	t.x = 10;
	t.y = 20;
	cout << t.x << " " << t.y << endl;

}

int main() {
	Bus b;
	b.print();

	test();

}

/*
A friend function lets us access the private and protected properties of a class.

We use 'friend' keyword to declare a friend function.

We can not define the friend function inside the class it's friend of. We will need to define it outside of that class.

Friend functions do not have access to 'this' pointer.

We can add friend functions under any access modifier

If we declare a class as a friend of another way then we call it a friend class and all of the friend class's members have access to all of friended class's members including public and protected members. But this friendship is one way. friended class is not a friend of the friend class by default. 
*/