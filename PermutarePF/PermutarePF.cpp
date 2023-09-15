#include <iostream>

using namespace std;

int permutare(int a[], int n) {
	bool k = 1;
	for (int i = 0; i < n; ++i)
		if (a[i] == i + 1)
			k = 0;
	return k;
}

int main() {
	int n, a[100];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cout << permutare(a, n);
	return 0;
}