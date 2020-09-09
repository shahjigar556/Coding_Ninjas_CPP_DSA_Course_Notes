class Truck : virtual public Vehicle {
	public :

		Truck() : Vehicle(4) {
			cout << "Truck's constructor " << endl;
		}
};
