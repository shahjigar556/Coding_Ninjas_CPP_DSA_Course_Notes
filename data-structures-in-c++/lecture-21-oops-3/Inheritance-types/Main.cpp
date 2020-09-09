#include <iostream>
using namespace std;
#include "Student.cpp"
#include "Teacher.cpp"
#include "TA.cpp"


int main() {
	TA a;

//	a.Student :: print(); // Student class's print() function is called through TA class's object

	a.print(); // TA class's print() function is called

	
	a.Teacher :: name = "abcd"; // Teacher class's name data member is accessed through TA class's object

}

/*
When TA class's object is created, Teacher and Student class's objects are also created as TA is multiple inherited Teacher and Student. Teacher and Student class's objects will be created in the same order as we mentioned while inheriting them. In this case, Teacher class's object is created first then Student class's object is created.

Both Teacher and Student Class has print() function which will create ambiguity. To get rid of it we have to specify which class's print() function to use. For that we need to use class name and scope operator (::). Syntax:
				obj.InheritedClassName::InheritedFunction();
This is common in case of multiple inheritance. If that function is available then that function is called if not specified otherwise there will be error due to ambiguity.
*/

