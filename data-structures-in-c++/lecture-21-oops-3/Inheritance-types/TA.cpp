#include <iostream>
using namespace std;
#include "Teacher.cpp"
#include "Student.cpp"

class TA : public Teacher, public Student { // TA class is inheriting both Teacher class and Student Class

	public :
		void print() {
			cout << "TA " << endl;
		}
};
