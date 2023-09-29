#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long v[100001];
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        v[i] = a * a + (b * b);
    }
    sort(v, v + n);
    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        int st = 0, dr = n - 1, poz = -1;
        x = x * x;
        while (st <= dr) {
            int m = (st + dr) / 2;
            if (v[m] <= x) {
                poz = m;
                st = m + 1;
            }
            else
                dr = m - 1;
        }
        cout << poz+1 << ' ';
    }
}