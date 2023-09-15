#include <iostream>

using namespace std;

int main()
{
    int n, U[1001], P[1001];
    long long v[1001];
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        U[i] = v[i] % 10;
        long long c = v[i];
        while (c) {
            P[i] = c % 10;
            c = c / 10;
        }
    }
    for (int i = 1; i < n; ++i)
        if (U[i] == P[i + 1])
            cout << v[i] << " " << v[i + 1] << endl;
    return 0;
}
