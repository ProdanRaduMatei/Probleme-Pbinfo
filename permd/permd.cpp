#include <iostream>

using namespace std;

int PermD(int a[], int n) {
	int v[1000000] = { 0 };
	for (int i = 0; i < n; ++i) {
		++v[a[i]];
		if (v[a[i]] > 1)
			return a[i];
	}
}

int main() {
	int a[100], n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cout << PermD(a, n);
	return 0;
}