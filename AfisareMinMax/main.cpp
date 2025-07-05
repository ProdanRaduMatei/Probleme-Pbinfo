#include <iostream>

using namespace std;

int main()
{
    int n;
    long long v[1001], m = 1000000, p, M = 0, P;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        if (v[i] < m) {
            p = i;
            m = v[i];
        }
        if (v[i] > M) {
            P = i;
            M = v[i];
        }
    }
    for (int i = p; i <= P; ++i)
        cout << v[i] << " ";
    for (int i = P; i <= p; ++i)
        cout << v[i] << " ";
    return 0;
}
