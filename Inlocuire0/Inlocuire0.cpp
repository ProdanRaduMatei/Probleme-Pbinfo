#include <iostream>

using namespace std;

void num(int n, int v[]) {
	int p = v[0];
	for (int i = 0; i < n; ++i)
		if (v[i] <= p)
			v[i] = 0;
}

int main() {
	int n, v[50];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	num(n, v);
	for (int i = 0; i < n; ++i)
		cout << v[i] << " ";
}