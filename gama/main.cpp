#include <iostream>
#include <fstream>
#include <cmath>
#include <bitset>
#include <cstring>
#include <algorithm>

using namespace std;

string  nume = "gama";

ifstream fin(nume + ".in");
ofstream fout(nume + ".out");

typedef unsigned long long ull;
typedef long long  ll;

int main() {
	int n, k, v[1000];
	fin >> n >> k;
	for (int i = 1; i <= n; i++)
		fin >> v[i];
	for (int i = 1; i <= n && k; i++) {
		int minn = v[i], pozMin = i;
		for (int j = i + 1; j <= n && j <= i + k; j++) {
			if (minn > v[j]) {
				minn = v[j];
				pozMin = j;
			}
		}
		for (int j = pozMin; j > i; j--) {
			swap(v[j], v[j - 1]);
			k--;
		}
	}
	for (int i = 1; i <= n; i++)
		fout << v[i] << ' ';
}