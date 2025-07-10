#include <iostream>
#include <algorithm>

using namespace std;

int n, a[300001], b[300001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a, a + n + 1);
    int j = 1;
    for (int i = 1; i <= n; i += 2) {
        b[i] = a[j];
        b[i + 1] = a[n / 2 + j];
        j++;
    }
    if (n % 4 != 0) {
        int aux = b[n];
        b[n] = b[n - 1];
        b[n - 1] = aux;
    }
    bool da = 1;
    for (int i = 1; i <= n && da; i += 2)
        if (b[i] == b[i + 1]) {
            for (int i = 1; i <= n; i++)
                cout << a[i] << " "; da = 0;
        }
    if (da)
        for (int i = 1; i <= n; i++)
            cout << b[i] << " ";
}