#include <iostream>
#include <algorithm>

using namespace std;

int cmmnr (int n) {
    long long int v[10], o = 0, p = 0, cnt = 0;
    while (n) {
        if (n % 10 == 0)
            cnt++;
        else {
            v[p] = n % 10;
            p++;
        }
        n /= 10;
    }
    sort(v, v + p);
    int ok = 0;
    for (int i = 0; i < p; ++i) {
        o = o * 10 + v[i];
        ok++;
        if (ok == 1)
            for (int i = 0; i < cnt; ++i)
                o = o * 10;
    }
        return o;
}
int main()
{
    int n;
    cin >> n;
    cout << cmmnr(n);
    return 0;
}
