#include <iostream>

using namespace std;

int cautare(int n, double x[], double v) {
	int p = -1;
	for (int i = 0; i < n; ++i)
		if (x[i] == v)
			p = i;
	return p;
}

int main() {
	int n;
	double x[100], v;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i];
	cin >> v;
	cout << cautare(n, x, v);
	return 0;
}