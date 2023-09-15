#include <iostream>

using namespace std;

void citire(int &n, int v[]) {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
}

int palindrom(int n) {
    int m = 0, p = 1, c, u;
    c = n;
    while (c) {
        u = c % 10;
        m = m * 10 + u;
        c = c / 10;
    }
    if (n == m)
        return 1;
    return 0;
}

void eliminare(int i, int &n, int v[]) {
    for (int j = i; j < n; ++j)
        v[j] = v[j + 1];
    --n;
}

void afisare(int n, int v[]) {
    for (int i = 1; i <= n; ++i)
        cout << v[i] << " ";
}

int main()
{
    int n, v[1001];
    citire(n, v);
    for (int i = 1; i <= n; ++i)
        if (palindrom(v[i]) == 1) {
            eliminare(i, n, v);
            --i;
        }
    afisare(n, v);
    return 0;
}
