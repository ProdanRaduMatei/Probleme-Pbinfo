#include <iostream>

using namespace std;

void  numar(int n, int a[], int &k) {
	int p = 1, M = 0, m = 999999, c;
	for (int i = 0; i < n; ++i) {
		if (a[i] < m)
			m = a[i];
		if (a[i] > M)
			M = a[i];
	}
	c = m;
	while (c) {
		c = c / 10;
		p = p * 10;
	}
	k = M * p + m;
}

int main() {
	int a[100], n, k;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	numar(n, a, k);
	cout << k;
	return 0;
}