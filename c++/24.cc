#include <iostream>
#include <algorithm>

int main (int argc, char* argv[])
{
	using namespace std;
	int perm[10] = {0,1,2,3,4,5,6,7,8,9};
	for (int i = 1; i < 1000000; i++)
		next_permutation(perm, perm + 10);
	for (int i = 0; i < 10; i++)
		cout << perm[i];
} 
