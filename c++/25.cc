#include <iostream>
#include <math.h>

int main (int arc, char* argv[])
{
	using namespace std;
	long double currentTerm = 1;
	long double previousTerm = 0;
	long double temp = 0;
	long double limit = 1e+999;
	int currentTermNumber = 1;
	while (currentTerm < limit)
	{
		temp = currentTerm;
		currentTerm += previousTerm;
		previousTerm = temp;
		currentTermNumber++;
	}
	cout << currentTerm << endl;
	cout << currentTermNumber;
}
