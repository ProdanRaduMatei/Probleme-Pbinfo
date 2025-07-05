#include <iostream>

using namespace std;
int ndivp(int x)
{
    int m, rez = 0;
    for (int d = 2; d * d <= x; d = d + 2) {
        if (d * d == x)
            ++rez;
        else if (x % d == 0)
            ++rez;
        m = x / d;
        if (x % m == 0)
            ++rez;
    }
    return rez;
}
int main()
{
    int a, b, n = 0, ma = 0, i, cnt, j = 0, p;
    long long mi = 10000000, v[1000], s[1000];
    cin >> a >> b;
    for (i = a; i <= b; ++i) {
        v[j] = i;
        s[j] = ndivp(i);
        if (s[j] >= n) {
            if (s[j] == n)
                ++cnt;
            else {
                n = s[j];
                cnt = 1;
            }
        }
        ++j;
    }
    p = j;
    for (j = 0; j < p; ++j){
        if (s[j] == n)
            if (v[j] < mi)
                mi = v[j];
            else if (v[j] > ma)
                ma = v[j];
    }
    cout << n << " " << mi << " " << ma;
    return 0;
}
