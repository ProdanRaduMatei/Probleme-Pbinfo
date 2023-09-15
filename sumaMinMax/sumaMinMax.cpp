#include <iostream>

using namespace std;

void sumaMinMax(int v[], int n, int a[]) {
	a[1] = { 0 };
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			if (v[i] > v[j])
				swap(v[i], v[j]);
	for (int i = 0; i < n - 1; ++i)
		a[0] = a[0] + v[i];
	for (int i = 1; i < n; ++i)
		a[1] = a[1] + v[i];
}

int main() {
	int v[100], n, a[2];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sumaMinMax(v, n, a);
	for (int i = 0; i <= 1; ++i)
		cout << a[i] << " ";
	return 0;
}