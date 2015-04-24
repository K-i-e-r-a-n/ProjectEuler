#include <iostream>
#include <math.h>


int getSumOfDigits(long double x)
{
	int sum = 0;
	while (x > 0)
	{
		sum += fmod(x, 10);
		x /= 10;
	}
	return sum;
}

int main (int argc, char* argv[])
{
    long double product = 1;
	for (int i = 1; i <= 100; i++)
	{
		if (i%10 == 0)
			product *= i/10;
		else
			product *= i;
		if (fmod(product, 10) == 0)
			product /= 10;
		
		std::cout << product << std::endl;
	}

	int sum = getSumOfDigits(sum);	
	std::cout << sum << std::endl;
}
