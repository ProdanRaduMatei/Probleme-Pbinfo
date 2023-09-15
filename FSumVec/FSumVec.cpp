#include <iostream>

using namespace std;

int suma(int v[], int n, int i, int j) {
	int s = 0;
	for (int k = 1; k < i; ++k)
		s = s + v[k];
	for (int k = j + 1; k <= n; ++k)
		s = s + v[k];
	return s;
}

int main() {
	int v[100], n, i, j;
	cin >> n;
	for (int k = 1; k <= n; ++k)
		cin >> v[k];
	cin >> i >> j;
	cout << suma(v, n, i, j);
	return 0;
}