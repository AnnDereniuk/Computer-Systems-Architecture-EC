#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "pr.h"
using namespace std;

int main() {
	int c, num;
	int tact, com, RS;
	vector<int> u;
	string command, temp, a, b, method, registr;
	char get[50];
	ifstream inpFile("input");
	inpFile.open("input.txt");
	if (!inpFile.is_open()) 
		cout << "Error with opening file\n";
	// inp.getline(get,50);
	cin.get();
	com = 1;tact = 1;RS = 0;
	Generate(a, b);
	while (inpFile.good())
	{ if (tact == 2)
		{ if (method == "Load")
			{ if (c<0) RS = 1;
				else   RS = 0;
				if (registr == "R1") a = Load(u);
				if (registr == "R2") b = Load(u);
				cout << "Command" << command << "\n";
				cout << "R1 = " << a << "\n";
				//cout<<temp<<"\n";
				cout << "R2 = " << b << "\n" << "Ins = " << temp << "\n";
				cout << "tact = " << tact << "\n" << "Command = " << com << "\n";
				cout << "RS = " << RS << "\n";
				cin.get();
				tact = 1;
				com++;
			}
			if (method == "Check") { RS = 0;
				if (registr == "R1")
				{ u = Converter(Check(a, num));
					while (u.size() % 4 != 0) u.insert(u.begin(), 0); a = Load(u);
				}
				if (registr == "R2")
				{ u = Converter(Check(b, num));
				while (u.size() % 4 != 0) u.insert(u.begin(), 0); b = Load(u);
				}
				cout << "Command = " << command << "\n";
				cout << "R1 = " << a << "\n";
				//cout<<temp<<"\n";
				cout << "R2 = " << b << "\n" << "Ins = " << temp << "\n";
				cout << "tact = " << tact << "\n" << "Command = " << com << "\n";
				cout << "RS = " << RS << "\n";
				cin.get();
				com++; tact = 1;
			}
		}
		else
		{
			temp = "";
			command = "";
			inpFile >> get;
			temp += get;
			method = temp;
			if ((temp == "Load") || (temp == "Check"))
			{
				command += get; command += " ";	temp += " | "; inpFile >> get; registr = get; 
				command += get; temp += get; temp += " | "; inpFile >> get; command += get; 
				inpFile >> c; command += to_string(c);
				if (method == "Load")
				{
					if (c<0)
					{
						u = Converter(abs(c));
						while (u.size() != 30)
							u.insert(u.begin(), 0);
						toComplementary(u);
						Normalize(u);
					}
					else
						u = Converter(c);
					while (u.size() % 4 != 0)
						u.insert(u.begin(), 0);
					for (int i = 0;i<u.size();i++)
					{
						temp += to_string(u[i]);
						// cout<<u[i];
						if ((i + 1) % 4 == 0)
						{
							cout << " ";
							temp += " ";
						}
					}
				}
				if (method == "Check")
				{
					num = c;
					temp += to_string(num);
				}
				cout << "Command= " << command << "\n";
				cout << "R1 = " << a << "\n";
				//cout<<temp<<"\n";
				cout << "R2 = " << b << "\n" << "Ins = " << temp << "\n";
				cout << "tact = " << tact << "\n" << "Command = " << com << "\n";
				cout << "RS = " << RS << "\n";
				cin.get();
				tact++;
				inpFile.getline(get, 50);
			}
			else
				inpFile.getline(get, 50);

		}
	}
	inpFile.close();

	return 0;
}