#include <iostream>

using namespace std;

int sub(int n, int v[], int k) {
	int i = 0, s = 0;
	while (k && i < n) {
		if (v[i] % 2 == 1) {
			--k;
			s = s + v[i];
		}
		++i;
	}
	if (k > 0)
		return -1;
	return s;
}

int main() {
	int n, v[100], k;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	cin >> k;
	cout << sub(n, v, k);
	return 0;
}