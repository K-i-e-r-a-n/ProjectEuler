#include <iostream>
#include <cmath>
#include "eulerUtils.hpp"

long quadForm (int n, int a, int b)
{
	return pow(n,2) + a*n + b;
}

int main (int argc, char* argv[])
{
	int longest = 0;
	int longest_a = 0;
	int longest_b = 0;	
	for (int b = -999; b < 1000; b++)
	{
		for (int a = -999; a < 1000; a++)
		{
			int n = 0;
			while (utils::isPrime(quadForm(n, a, b)))
			{
				n++;
			}
			if (n > longest)
			{
				longest = n;
				longest_a = a;
				longest_b = b;
			}
		}
	}
	std::cout << longest_a << "*" << longest_b << " = " << longest_a * longest_b << std::endl;
}

