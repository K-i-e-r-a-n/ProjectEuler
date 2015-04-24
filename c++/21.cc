#include <math.h>
#include <vector>
#include <iostream>

int factorSum (int x)
{
	int sum = 0;
	for (int i = 1; i < x; i++)
	{
		if (x%i == 0)
		{
			sum += i;
		}
	}
	return sum;
} 

bool inVector(int i, std::vector<int> amicables)
{
	for (int k = 0; k < amicables.size(); k++)
	{
		if (amicables[k] == i)
			return true;
	}
	return false;
}

int main (int argc, char* argv[])
{
	std::vector<int> amicables;
	int sum = 0;
    for (int i = 1; i < 10000; i++)
	{
		if (!inVector(i, amicables))
		{
			int j = factorSum(i);
			if (factorSum(j) == i && i != j)
			{
				amicables.push_back(j);
				amicables.push_back(i);
			}	
		}	
	}
	for (int i = 0; i < amicables.size(); i++)
	{
		sum += amicables[i];
	}	
	std::cout << sum << std::endl;
}
