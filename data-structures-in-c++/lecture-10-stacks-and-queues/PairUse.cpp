#include <iostream>
#include "Pair.cpp"
using namespace std;

int main()
{
    /*
    Pair<int> p1; // For p1, the data type of template T is int as defined in <>
    p1.setX(10);
    p1.setY(20);
    cout << p1.getX() << " " << p1.getY() << endl;

    Pair<double> p2; // for p2, the data type of template T is double as defined in <>
    p2.setX(100.34);
    p2.setY(34.21);
    cout << p2.getX() << " " << p2.getY() << endl;
    */

    /*
    Pair<int, double> p3; // for p3, T is int and V is double
    p3.setX(100.34);
    p3.setY(100.34);
    cout << p3.getX() << " " << p3.getY() << endl;
    */

    Pair<Pair<int, int>, int> p4;
    // p4 is a object where the first type is a object type of Pair with two types both int
    // and the second type of p4 is int
    // here V is int BUT T is a Pair datatype
    // i.e, the variables with T datatype are objects of the Pair class
    p4.setY(10);
    Pair<int, int> p5;
    p5.setX(5);
    p5.setY(16);
    p4.setX(p5); // We are assigning the object p5 to the first type (x) of p4
    // So internally copy assignment operator is called
    // We are setting a whole object here
    // x is a object of the Pair class
    // p4.getX() will give us an object
    cout << p4.getX().getX() << " " << p4.getX().getY() << " " << p4.getY() << endl;
    // p4.getX().getX() => p5.getX()
}