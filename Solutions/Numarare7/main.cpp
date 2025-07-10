#include <iostream>

using namespace std;

int main()
{
    int n, i, cnt = 0;
    double V[200], M, m;
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> V[i];
    if (V[1] < V[n]) {
        m = V[1];
        M = V[n];
    }
    if (V[1] > V[n]) {
        m = V[n];
        M = V[1];
    }
    for (i = 1; i <= n; ++i) {
        if (V[i] > m && V[i] < M)
            ++cnt;
    }
    cout << cnt;
    return 0;
}
