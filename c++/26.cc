#include <iostream>
#include <math.h>
#include <vector>
#include <sstream>
//#include "headers/euler.h"

int getRepeatLength	(std::string s)
{
	std::string matching;
	int startIndex;
	int startValue;
	int longest = 0;
	int i = 2;
	for(int i = 2; i < s.length(); i++)
	{
		for (int j = i+1; j < s.length(); j++)
		{
			if (s[i] == s[j])
			{
				matching = "";
				int k = 0;
				while (s[i + k] == s[j + k]/* && s[i + k] != 0 && s[j+k] != 0*/)
				{
					if (i + k == j && s[i] == s[j + k])
					{			
						return matching.length();
					}
					matching += s[i + k];
					k++;
				}
			}
		}	
	}  
	return 0;
}

std::string longDivisionOne (int d)
{
	int n = 1;
	std::string dividend = "";
	std::stringstream s;
	int temp = 0;
	while (dividend.length() < 2*d + 1)
	{
		s.str("");
		if (n % d == 0)
		{
			s << (int)(n/d);
			dividend += s.str();
			break;
			
		}
		else if (d > n)
		{
			if (dividend.length() == 0)
				dividend += "0.";
			else if (d > 10*n)
				dividend += "0";
			n*= 10;
		}
		else
		{
			s << (int)(n/d);
			dividend += s.str();
			temp = n;
			n -=  d*(n/d);
		}
	}
	return dividend;

}

int main (int argc, char* argv[])
{
	using namespace std;
	int highest = 0;
	int highindex = 0;
	for (int i = 999; i > 0; i--)
	{
		if (getRepeatLength(longDivisionOne(i)) > highest)
		{
			highest = getRepeatLength(longDivisionOne(i));
			highindex = i;
		} 
	}
	cout <<  highindex << endl;
}
