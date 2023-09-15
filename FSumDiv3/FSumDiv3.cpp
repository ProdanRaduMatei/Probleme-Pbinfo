#include <iostream>

using namespace std;

int sum3(int v[], int n) {
	int s = 0;
	for (int i = 0; i < n; ++i)
		if (v[i] % 3 == 0)
			s = s + v[i];
	return s;
}

int main() {
	int v[100], n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	cout << sum3(v, n);
	return 0;
}