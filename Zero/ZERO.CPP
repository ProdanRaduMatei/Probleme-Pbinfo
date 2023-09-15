#include <iostream>

using namespace std;

void zero(int n, int v[]) {
	for (int i = 1; i < 2 * n; ++i) {
		if (i % 2 == 0 && v[i] % 2 != 0) {
			int j = i + 1;
			int k = 0;
			while (j <= 2 * n && k == 0) {
				if (j % 2 != 0 && v[j] % 2 == 0)
					k = 1;
				++j;
			}
			swap(v[i], v[j - 1]);
		}
		else if (i % 2 != 0 && v[i] % 2 == 0) {
			int j = i + 1;
			int k = 0;
			while (j <= 2 * n && k == 0) {
				if (j % 2 == 0 && v[j] % 2 != 0)
					k = 1;
				++j;
			}
			swap(v[i], v[j - 1]);
		}
	}
}

int main() {
	int n, v[100];
	cin >> n;
	for (int i = 1; i <= 2 * n; ++i)
		cin >> v[i];
	zero(n, v);
	for (int i = 1; i <= 2 * n; ++i)
		cout << v[i] << " ";
}
