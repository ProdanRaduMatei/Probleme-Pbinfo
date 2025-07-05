#include <iostream>

using namespace std;

unsigned long long C, a[1001], k;
int n, M;

int main()
{
    cin >> n >> C;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        if (n == i && k + a[i] > C) {
            ++M;
            k = 0;
        }
        if (k + a[i] <= C)
            k = k + a[i];
        if (n != i && k + a[i + 1] > C) {
            ++M;
            k = 0;
        }
        if (n == i && k <= C)
            ++M;
    }
    cout << M;
    return 0;
}
