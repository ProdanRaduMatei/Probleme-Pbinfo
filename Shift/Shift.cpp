#include <iostream>

using namespace std;

void shift(int x[], int n) {
	int p;
	p = x[0];
	for (int i = 0; i < n - 1; ++i)
		x[i] = x[i + 1];
	x[n - 1] = p;
}

int main() {
	int n, x[100];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i];
	shift(x, n);
	for (int i = 0; i < n; ++i)
		cout << x[i] << " ";
	return 0;
}