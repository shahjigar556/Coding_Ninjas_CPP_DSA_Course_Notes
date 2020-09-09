class HondaCity : public Car {
	public :

		HondaCity(int x, int y) : Car(x, y) {
			cout << "Honda city constructor " << endl;
		}

		~HondaCity() {
			cout << "Honda city destructor " << endl;

		}
};
