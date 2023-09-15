#include <iostream>

using namespace std;

int main()
{
    int n, m, i, q, a, b, c, d;
    long long v[100000];
    cin >> n >> m;
    for (i = 1; i <= n; ++i)
        cin >> v[i];
    cin >> q;
    while (q >= 0) {
        cin >> a >> b >> c >> d;
        s = 0;
        for (i = a; i <= c; ++i) {
            if (v[i] > b && v[i] < d) {
                s = s + v[i] - b;
            }
            else if (v[i] > b && v[i] > d) {
                s = s +
            }
        }
    }
    return 0;
}
