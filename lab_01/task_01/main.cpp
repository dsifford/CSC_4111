#include <iostream>
#include "stack.h"
using namespace std;

int main() {

	Stack<int> s;
	s.printElements();
	cout << "stack.isEmpty() == " << s.isEmpty() << endl;
	cout << "Pushing 5, 6, 7, 8" << endl;
	s.push(5);
	s.push(6);
	s.push(7);
	s.push(8);
	cout << "stack.isEmpty() == " << s.isEmpty() << endl;
	cout << "stack.numOfElements() == " << s.numOfElements() << endl;
	s.printElements();
	cout << "Popping 2..." << endl;
	s.pop();
	s.pop();
	cout << "stack.isEmpty() == " << s.isEmpty() << endl;
	cout << "stack.numOfElements() == " << s.numOfElements() << endl;
	s.printElements();
	
	return 0;
}
