class Car : public Vehicle { // Inheriting Vehicle Class Publically
	public :
		int numGears;


		void print() {
			cout << "NumTyres : " << numTyres << endl;
			cout << "Color : " << color << endl;
			cout << "Num gears : " << numGears << endl;
	//		cout << "Max Speed : " << maxSpeed << endl; // maxSpeed is private property in the Vehicle class so, Car will not inherit it.
		}


};

/*
Car only inherited the Public and Protected properties of the Vehicle Class. Private properties can never be inherited.

'public'-ally Inheriting means that inherited Public properties will stay as public and the inherited Protected properties will stay as protected in the child CLass.

'protected'-ly Inheriting means that Protected members will stay as Protected members in the derived class. BUT the inherited Public members will also become Protected members in the derives class.

'private'-ly Inheriting means that both inherited Protected and Public members will become Private members in the derived class.

By default Parent class is inherited privately if we did not specify a access modifier at the time of inheritance.
*/