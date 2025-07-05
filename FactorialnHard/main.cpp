#include <bits/stdc++.h>

using namespace std;

int n, a[100005], b[100005], c[100005];

void produsmare() {
    int t = 0;
    c[0] = a[0] + b[0] - 1;
    for (int i = 1; i <= a[0] + b[0]; i++)
        c[i] = 0;
    for (int i = 1; i <= a[0]; i++)
        for (int j = 1; j <= b[0]; j++)
            c[i + j - 1] += a[i] * b[j];
    for (int i = 1; i <= c[0]; i++) {
        t += c[i];
        c[i] = t % 10;
        t /= 10;
    }
    if (t > 0)
        c[++c[0]] = t;
}

void produsmic(int x) {
    int t = 0;
    for (int i = 1; i <= a[0]; i++) {
        t = t + a[i] * x;
        a[i] = t % 10;
        t /= 10;
    }
    while(t) {
        a[++a[0]] = t % 10;
        t /= 10;
    }
}

void muta(int a[],int c[]) {
    a[0] = c[0];
    for (int i = 1; i <= c[0]; i++)
        a[i] = c[i];
}

void afisare() {
    for (int i = a[0]; i >= 1; i--)
        cout << a[i];
}

int main() {
    cin >> n;
    a[0] = a[1] = 1;
    for (int i = 2; i <= n; i++)
        produsmic(i);
    muta(b, a);
    for (int i = 2; i <= n; i++)
        produsmare(), muta(a, c);
    afisare();
    return 0;
}