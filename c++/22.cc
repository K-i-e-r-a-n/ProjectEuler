#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>    

int main(int argc, char* argv[])
{	
	using namespace std;
	vector<string> names;
	string temp;
	ifstream file("names.txt"); 
	int iterator = 0;
	while (!file.eof())
	{
		getline(file, temp, ',');
		names.push_back("");
		for (int j = 0; j < temp.size(); j++)
		{
			if(temp[j] != '"')
				names[iterator] += temp[j];
		}
		iterator++;
	}
	
	sort(names.begin() , names.end());
	long sum = 0;
	int letterSum = 0;
	for (int i = 0; i < names.size(); i++)
	{
		letterSum = 0;
		for (int j = 0; j < names[i].size(); j++)
		{
			letterSum += (int)(names[i][j]) - 64;
		}
		sum = sum + letterSum*(1+i);
		if (i == 937)
			cout << names[i] << " " << letterSum*(i+1) << endl;
    }
	cout << sum << endl;
}
