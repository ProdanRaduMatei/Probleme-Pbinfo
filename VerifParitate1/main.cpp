#include <iostream>

using namespace std;

const int nMAX = 200;

int n;
int v[nMAX + 1];

int main() {
    int i;
    bool ok;
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> v[i];
    ok = true;
    for (i = 1; i <= n/2; ++i)
        if (v[i] % 2 != v[n - i + 1] % 2)
            ok = false;
    cout << (ok ? "DA" : "NU");
}