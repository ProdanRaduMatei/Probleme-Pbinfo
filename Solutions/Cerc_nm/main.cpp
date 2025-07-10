#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int v[101], n, m, ok = 0;

void afisare(int k) {
    for (int i = 1; i <= k; i++)
        cout << v[i] << " ";
    exit(0);
}

bool verifica(int k) {
    if (k == 1) return true;
    for (int i = 1; i < k; i++)
        if (v[i] == v[k])
            return false;
    if (sqrt(v[k] + v[k - 1]) != (int)(sqrt(v[k] + v[k - 1])))
        return false;
    if (k == m) {
        if (sqrt(v[k] + v[1]) != (int)(sqrt(v[k] + v[1]))) 
            return false;
    }
    return true;
}

void back(int k) {
    for (int i = 1; i <= n; i++) {
        v[k] = i;
        if (verifica(k)) {
            if (k == m) {
                afisare(m);
                ok = 1;
            }
            else
                back(k + 1);
        }
    }
}

int main()
{
    cin >> n >> m;
    back(1);
    if (!ok)
        cout << "nu exista";
    return 0;
}