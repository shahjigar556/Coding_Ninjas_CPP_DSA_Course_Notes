#include <iostream>
#include <stack> // Inbuilt stack file
using namespace std;
// #include "StackUsingArray.h"
// #include "StackUsingLL.h"
// <> -> inbuilt
// "" -> self made

int main()
{
	/*
	StackUsingArray<int> s; // s stack is a integer stack
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	cout << s.top() << endl;

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	cout << s.size() << endl;

	cout << s.isEmpty() << endl;

	StackUsingArray<char> s2; // s2 is a character stack
	s2.push(100);
	s2.push(101);
	s2.push(102);
	s2.push(103);
	s2.push(104);

	cout << s2.top() << endl;

	cout << s2.pop() << endl;
	cout << s2.pop() << endl;
	cout << s2.pop() << endl;

	cout << s2.size() << endl;

	cout << s2.isEmpty() << endl;
	*/

	stack<int> s; // s stack is a integer stack
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	cout << s.top() << endl; // 50
	s.pop();				 // delete 50
	// for inbuilt stack, pop() only deletes the topmost element
	// s.pop() returns nothing. pop() is of return type void
	cout << s.top() << endl; // 40
	s.pop();				 // delete 40
	cout << s.top() << endl; // 30
	s.pop();				 // delete 30
	cout << s.top() << endl; //20

	cout << s.size() << endl; // 2

	// for inbuilt stack, isEmpty() -> empty()
	cout << s.empty() << endl; // 0 <- stack is not empty, so false is returned which is interpreted as 0
}
