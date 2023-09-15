#include <iostream>

using namespace std;

void ordon123(int n, int a[]) {
	int v[4] = { 0 };
	for (int i = 0; i < n; ++i)
		++v[a[i]];
	for (int i = 0; i < n; ++i) {
		if (v[1] > 0) {
			a[i] = 1;
			--v[1];
		}
		else {
			if (v[2] > 0) {
				a[i] = 2;
				--v[2];
			}
			else if (v[3] > 0) {
				a[i] = 3;
				--v[3];
			}
		}
	}
}

int main() {
	int n, a[1000000];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	ordon123(n, a);
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
}