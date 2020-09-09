#include <iostream>
using namespace std;
#include "Vehicle.cpp"
#include "Car.cpp"
#include "HondaCity.cpp"


int main() {

	HondaCity h(4, 5);
	
	
	//	Vehicle v;

	//v.color = "Blue";
	// v.maxSpeed = 100;
	// v.numTyres = 4;



//	Car c(5);
	
	
	
	//c.color = "Black";
//	c.numTyres = 4;
	// c.numGears = 5;


}

/*


If C isinheriting B and B is inheriting A then if we want to create an object of C then we need to first initialize B as C has some properties of B. Similarly, forinitializing B class, we will first need to initialize A as B is inheriting some properties of A. So, for creating an object od C, first A's constructor will be called then B's constructor will be called then C's constructor will be called. The parent constructors are implicitly get called. We don't need to call them implicitly. First Parent's constructor is called then child's constructor is called. C can only call B's constructor, but not A's constructor. So, a child can only call it's parent's constructor.

In case of destructor, the order is opposite. First child's destructor is called then Parent's destructor is called.
*/