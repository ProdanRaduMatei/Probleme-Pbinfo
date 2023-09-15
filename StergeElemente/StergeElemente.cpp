#include <iostream>

using namespace std;

void sterge(int v[], int& n, int i, int j)  {
	int p, ii = i;
	for (p = j + 1; p <= n; p++)
	{
		v[i] = v[p];
		i++;
	}
	n = n - (j - ii + 1);
}

int main() {
	int v[100], n, i, j;
	cin >> n;
	for (int k = 1; k <= n; ++k)
		cin >> v[k];
	cin >> i >> j;
	sterge(v, n, i, j);
	for (int k = 1; k <= n; ++k)
		cout << v[k] << " ";
	return 0;
}