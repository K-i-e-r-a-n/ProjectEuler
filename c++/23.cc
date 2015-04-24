#include <iostream>
#include <vector>
#include <math.h>

bool isAbundant(int n)
{
	int sum = 0;
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(n%i == 0)
		{
			if (i == sqrt(n))
			{
				sum += sqrt(n);
			}
			else
			{
				sum += i;
				sum += n/i;
			}	
		}
	}
	if (sum > n)
		return true;
	return false;	
}

int main(int argc, char* argv[])
{
	using namespace std;
	vector<int> abundants;
	for (int i = 28123; i > 0 ; i--)
	{
		if (isAbundant(i))
		{
			abundants.push_back(i);
			cout << i << endl;
		}
	}

	cout << "Abundant List generated, with " << abundants.size() << " abundant numbers" << endl;
	
	bool abunSum;
	long sum = 0;
	vector<int> notSums;
	for (int i = 0; i <= 28123; i++)
	{
		notSums.push_back(i);
	}
	for (int i = 0; i < abundants.size(); i++)
	{
		for (int j = i; j < abundants.size(); j++)
		{
			if (abundants[i] + abundants[j] <= 28123)
			{
				notSums[abundants[i] + abundants[j]] = 0;
			}
		} 
	}
	for (int i = 0; i < notSums.size(); i++)
		sum += notSums[i];
	cout << sum << endl;
}


