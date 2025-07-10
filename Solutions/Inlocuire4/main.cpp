#include <iostream>

using namespace std;

void citire(int &n, int v[]) {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> n;
}

void afisare(int n, int v[]) {
    for (int i = 1; i <= n; ++i)
        cout << v[i] << " ";
}

int redus(int n) {
    int m = 1, p, d = 2;
    while (n != 1) {
        p = 0;
        while (n % d == 0) {
            ++p;
            n = n / d;
        }
        if (p)
            m = m * d;
        ++d;
        if (n > 1 && d * d > n)
            d = n;
    }
    return m;
}

void inloc(int i, int j, int v[]) {
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void sortare (int n, int v[]) {
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (v[i] < v[j])
                inloc(i, j, v);
}

int main()
{
    int n, v[1001], x;
    citire(n, v);
    for (int i = 1; i <= n; ++i) {
        x = redus(v[i]);
        inloc(x, i, v);
    }
    sortare(n, v);
    afisare(n, v);
    return 0;
}
