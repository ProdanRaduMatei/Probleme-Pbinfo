#include <iostream>

using namespace std;

int suma(int v[], int n, int m) {
	int s = 0;
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			if (v[i] > v[j])
				swap(v[i], v[j]);
	for (int i = 0; i < m; ++i)
		s = s + v[i];
	return s;
}

int main() {
	int v[100], n, m;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	cin >> m;
	cout << suma(v, n, m);
	return 0;
}