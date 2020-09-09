class Vehicle {
	private :
		int maxSpeed;

	protected :
		int numTyres;

	public :
		string color;

	/*
		Vehicle() {
		cout << "Vehicle's default constructor " << endl;
	}*/

	void print() {
		cout << "Vehicle" << endl;
	}


	Vehicle(int z) {
	cout << "Vehicle's Parametrized constructor " << z << endl;
		maxSpeed = z;
	}

	~Vehicle() {
		cout << "Vehicle's Destructor " << endl;
	}

};
