class Car : virtual public Vehicle {
	public :
		int numGears;

		Car() : Vehicle(3){
			cout << "Car's default constructor " << endl;
		}


		/*
		Car(int x, int y) : Vehicle(x) {
			cout << "Car's constructor " << endl;
			numGears = y;
		}*/

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
