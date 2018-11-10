#pragma once
#include<iostream>
#include <vector>
using namespace std;

void Normalize(std::vector<int> &u);

void toComplementary(std::vector<int> &u);

std::vector<int> Converter(int a);

int Check(string a, int n);

string Load(std::vector<int>u);

void Generate(string &a, string &b);
