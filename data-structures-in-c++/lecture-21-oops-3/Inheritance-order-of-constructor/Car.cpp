class Car : public Vehicle {
	public :
		int numGears;

		Car(int x, int y) : Vehicle(x) { // Using Initialization List to initialize a parameterized constructor
			cout << "Car's constructor " << endl;
			numGears = y;
		}

		~Car() {
			cout << "Car's Destructor " << endl;
		}


		void print() {
			cout << "NumTyres : " << numTyres << endl;
			cout << "Color : " << color << endl;
			cout << "Num gears : " << numGears << endl;
			//		cout << "Max Speed : " << maxSpeed << endl;
		}



};


/*
Initialization List automatically initializes a data members or parent's constructor, so that they will not have any garbage values at the time of object initialization.Initialization list is first executed then code in the constructor is executed.

Impilicitly, the default constructor of the parent clas is called. To, explicitly initialize a parameterized constructor, we need to explicitly declare it or use a initialization list.
*/