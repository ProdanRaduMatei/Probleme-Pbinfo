#include <iostream>
#include <algorithm>

using namespace std;

int n, P[100001];

void next_perm(int n, int P[]) {
    int m = 1000000, poz, k = 1;
    while (P[k] < P[k + 1] && k <= n)
        ++k;
    ++k;
    for (int i = k; i <= n; ++i)
        if (P[i] < m && P[i] > P[k]) {
            m = P[i];
            poz = i;
        }
    int aux = P[poz];
    P[poz] = P[k];
    P[k] = aux;
    for (int i = k + 1; i < n; ++i)
        for (int j = k + 2; j <= n; ++j)
            if (P[i] > P[j]) {
                aux = P[i];
                P[i] = P[j];
                P[j] = aux;
            }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> P[i];
    next_perm(n, P);
    for (int i = 1; i <= n; ++i)
        cout << P[i] << " ";
    return 0;
}
