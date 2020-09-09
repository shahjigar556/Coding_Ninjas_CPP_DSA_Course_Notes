class Car : public Vehicle {
	public :
		int numGears;

		Car(int x, int y) : Vehicle(x) {
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
