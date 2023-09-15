#include <iostream>

using namespace std;

int main()
{
    int n, v[1000], m = 0, s, c = 0, p, x;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    x = v[n];
    c = 1;
    s = n;
    for (int i = n - 1; i >= 1; --i) {
        if (v[i] == x)
            ++c;
        else
            if (c >= m) {
                m = c;
                p = s;
                s = i;
                c = 1;
                x = v[i];
            }
    }
    cout << p + 1 << " " << p + m;
    return 0;
}
