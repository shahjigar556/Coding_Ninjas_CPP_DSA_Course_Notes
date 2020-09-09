class Car : public Vehicle {
	public :
		int numGears;


		void print() { // Overriding Vehicle's print();
			cout << "Car" << endl;
		}


};
