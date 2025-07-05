#include <iostream>

using namespace std;

void aranjare(int v[], int n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (v[i] % 2 == 0 && v[j] % 2 != 0)
                swap (v[i], v[j]);
}

int main()
{
    int n, v[10000];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    aranjare(v, n);
    for (int i = 0; i < n; ++i)
        cout << v[i] << " ";
    return 0;
}
