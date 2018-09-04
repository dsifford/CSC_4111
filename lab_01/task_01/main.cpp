#include <iostream>
#include "stack.h"
using namespace std;

int main() {

	Stack<int> s;
	s.push(5);
	s.printElements();
	s.push(6);
	s.printElements();

	return 0;
}
