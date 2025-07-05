#include <iostream>

using namespace std;

int count(double a[], int n) {
	double m = 0;
	int c = 0;
	for (int i = 0; i < n; ++i)
		m =(double) m + a[i];
	m = (double)m / n;
	for (int i = 0; i < n; ++i)
		if (a[i] >= m)
			++c;
	return c;
}

int main() {
	double a[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cout << count(a, n);
	return 0;
}