#include <iostream>

using namespace std;

void F(int n, int a[], int& k) {
	k = 0;
	int c = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] % 2 == 0) {
			k = k * 10 + a[i];
			++c;
		}
	if (c == 0)
		k = -1;
}

int main() {
	int n, a[9], k;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	F(n, a, k);
	cout << k;
	return 0;
}