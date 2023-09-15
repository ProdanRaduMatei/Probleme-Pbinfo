#include <iostream>

using namespace std;

void citire(int &n, int v[]) {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
}

void afisare(int n, int v[]) {
    for (int i = 1; i <= n; ++i)
        cout << v[i] << " ";
}

int prim(int n) {
    if (n <= 1)
        return 0;
    if (n % 2 == 0) {
        if (n == 2)
            return 1;
        else
            return 0;
    }
    for (int i = 3; i * i <= n; i = i + 2)
        if (n % i == 0)
            return 0;
    return 1;
}

int urmatorul_prim(int n) {
    int m;
    bool k = 1;
    if (n % 2 == 0)
        m = n + 1;
    else
        m = n + 2;
    while (prim(m) == 0)
        m = m + 2;
        return m;
}

void inloc(int x, int i, int v[]) {
    v[i] = x;
}

int main()
{
    int n, v[1001], x;
    citire(n, v);
    for (int i = 1; i <= n; ++i)
        if (prim(v[i]) == 0) {
            x = urmatorul_prim(v[i]);
            inloc(x, i, v);
        }
    afisare(n, v);
    return 0;
}
