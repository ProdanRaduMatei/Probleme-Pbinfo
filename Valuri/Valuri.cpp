#include <iostream>

using namespace std;

void valuri(int n, int v[]) {
	for (int i = 0; i < 2 * n; i = i + 2)
		v[i] = i + 1;
	for (int i = 1; i < 2 * n; i = i + 2)
		v[i] = 2 * n - i + 1;
}

int main() {
	int n, v[100] = { 0 };
	cin >> n;
	valuri(n, v);
	for (int i = 0; i < 2 * n; ++i)
		cout << v[i] << " ";
	return 0;
}