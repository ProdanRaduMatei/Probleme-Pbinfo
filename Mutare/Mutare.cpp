#include <iostream>

using namespace std;

void sub(int n, int v[], int x) {
	int c = 0;
	for (int i = 0; i < n; ++i) {
		if (v[i] == x) {
			for (int j = i; j < 1; ++j)
				v[j] = v[j - 1];
			v[0] = x;
		}
	}
}

int main() {
	int n, v[100], x;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	cin >> x;
	sub(n, v, x);
	for (int i = 0; i < n; ++i)
		cout << v[i] << " ";
	return 0;
}