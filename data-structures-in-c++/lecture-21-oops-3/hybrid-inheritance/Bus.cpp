class Bus : public Car, public Truck {
	public :

		Bus() : Vehicle(5) {
			cout << "Bus's constructor " << endl;
		}

		/*
		void print() {
			cout << "BUs" << endl;
		}*/
};

/*
As, Vehicle is Car's and Truck's virtual base class so, Bus will directly call Vehicle constructor.

Without virtual Vehicle will be called twice but now with Vehicle being virtual base class, Vehicle is called once.

In case of virtual base classes, we can say that the derived classes do not have the base class. It only has a pointer that is pointing towards the base class object, it does not have actual object.

Bus now have actual objects of Car, Truck and Vehicle.

Normally, a derived class can only call it's immediate parent class. But if the Grandparent class is 'virtual'-ly inherited by the parents then the base class can call it'e grandparent class.

If we replaced the default constructor of Vehicle then Car, Truck and Bus need to explicitly call the parameterized constructor. 
*/