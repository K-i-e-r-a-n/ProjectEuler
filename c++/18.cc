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
	reader.open ("smallTriangle.txt", ios::in);
	int triangle[15][15];
	
	for (int i = 0; i < 15; i++)
	{	
		for (int j = 0; j <= i; j++)
		{
			reader >> triangle[i][j];		
		}
	}
	
	for (int i = 14; i >= 0; i--)
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
	
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << (int)(triangle[i][j]) << " ";
		}
		cout << endl;
	}
}










