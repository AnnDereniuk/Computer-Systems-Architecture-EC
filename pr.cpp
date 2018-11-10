#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

void Normalize(std::vector<int> &u)
{
	int z = (int)u.size() - 1; //Avoiding overflow
	u[z] = u[z] + 1;
	if (u[z] == 2)
	{
		for (int i = (int)u.size(); i >= 0; i--)
		{
			if ((i == 0) && (u[i] == 2))
			{
				u[i] = 0;
				u.insert(u.begin(), 1);
			}
			if (u[i] == 2)
			{
				u[i] = 0;
				u[i - 1]++;
			}
		}
	}
}

void toComplementary(std::vector<int> &u)
{
	for (int i = 0;i<u.size();i++)
	{
		if (u[i] == 1)
			u[i] = 0;
		else
			u[i] = 1;
	}
}
std::vector<int> Converter(int a)
{
	std::vector<int> b;
	int temp = a;
	while (temp>0)
	{
		b.push_back(temp % 2);
		temp = temp / 2;
	}
	int start = 0;
	int end = (int)b.size() - 1;
	while (end>start)
	{
		swap(b[start], b[end]);
		start++;
		end--;
	}
	return b;

}

int Check(string a, int n)
{
	int u = 0;
	if (n == 1)
	{
		for (int i = 0;i<(int)a.size();i++)
		{
			if (a[i] == *"1")
				u++;
		}
	}
	else
		if (n == 0)
		{
			for (int i = 0;i<(int)a.size();i++)
			{
				if (a[i] == *"0")
					u++;
			}
		}
	return u;
}
string Load(std::vector<int>u)
{
	int w;
	string temp;
	if ((int)u.size()>30)
	{
		while (u.size() != 30)
			u.erase(u.begin());
		temp += to_string(u[0]);
		temp += to_string(u[1]);
		temp += " ";
		w = 4;
		for (int i = 2; i<u.size();i++)
		{
			temp += to_string(u[i]);
			w++;
			if (w % 4 == 0)
				temp += " ";
		}
	}
	else
	{
		int z = 30 - (int)u.size();
		for (int i = 0;i<z;i++)
		{
			if (i<2)
			{
				temp += "0";
				if (i == 1)
				{
					temp += " ";
					w = (int)temp.size() + 1;
				}
			}
			else
			{
				temp += "0";
				w++;
				if (w % 4 == 0)
					temp += " ";
			}
		}
		for (int i = 0;i<u.size();i++)
		{
			temp += to_string(u[i]);
			if ((i + 1) % 4 == 0)
			{
				temp += " ";
			}

		}
	}
	return temp;
}

void Generate(string &a, string &b)
{
	a = "10 0101 0111 0110 0100 1000 0110 0001";
	b = "00 0000 1100 1001 0001 1001 0100 0010";
}

