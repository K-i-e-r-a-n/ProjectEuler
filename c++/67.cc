#include <fstream>
#include <iostream>
#include <sstream>

////////////////////////////////
// Project Euler Solution #18 //
////////////////////////////////

int main (int argc, char* argv[])
{
	using namespace std;
	fstream reader;
	reader.open ("bigTriangle.txt", ios::in);
	int triangle[100][100];
	
	for (int i = 0; i < 100; i++)
	{	
		for (int j = 0; j <= i; j++)
		{
			reader >> triangle[i][j];		
		}
	}
	
	for (int i = 99; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{	
			if (triangle[i][j] > triangle[i][j+1])
			{
				triangle[i-1][j] += triangle[i][j]; 
			}
			else
			{	
				triangle[i-1][j] += triangle[i][j+1];
			} 
		}
	}
	
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << (int)(triangle[i][j]) << " ";
		}
		cout << endl;
	}
}










