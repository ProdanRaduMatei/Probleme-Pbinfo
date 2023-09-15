#include <iostream>

using namespace std;

int main()
{
    int n, m, a, b, c, re, pe, rt = 0, pt = 0, s = 100000;
    bool k = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b;
        rt = rt + a;
        pt = pt + b;
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        if (a >= pt && b >= rt) {
            k = 1;
            if (c < s)
                s = c;
        }
    }
    if (k == 1)
        cout << s;
    else
        cout << "-1";
    return 0;
}
