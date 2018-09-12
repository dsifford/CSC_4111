#include "derek.h"
using namespace std;

Derek::Derek(): Offense("Derek") {}

void Derek::printStats() const {
	cout << "Hi from Derek class" << endl;
	Offense::printStats();
	cout << "Bye from Derek class" << endl;
}
