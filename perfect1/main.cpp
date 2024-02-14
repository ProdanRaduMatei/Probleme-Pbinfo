#include <iostream>
#include <fstream>
#include <cmath>
#include <bitset>
#include <cstring>
#include <algorithm>
using namespace std;

ifstream fin("perfect1.in");
ofstream fout("perfect1.out");

typedef unsigned long long ull;

int main()
{
	int Perfecte[5] = { 0,8128,496,28,6 };
	int n;
	fin >> n;
	int v[101];
	for (int i = 1; i <= n; i++)
		fin >> v[i];
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			if (v[i] > v[j])
				swap(v[i], v[j]);
	for (int k = 1; k <= 4; k++)
	{
		int aux = Perfecte[k];
		for (int j = n; j >= 1; j--)
		{
			int valx = Perfecte[k];
			
			for (int i = j; i >= 1; i--)
                if (v[i])
			if (valx % v[i] == 0)
				valx /= v[i];
			aux = min(valx, aux);
		}
		if (aux == 1) 
		{
			fout << Perfecte[k];
			return 0;
		}
	}
	fout << "NU";
}