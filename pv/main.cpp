#include <iostream>

using namespace std;

int main()
{
    int n, i, v[100], sp = 0, spp = 0, cnt = 0, si = 0;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> v[i];
        if (v[i] % 2 == 0)
            sp = sp + v[i];
        if (i % 2 == 0)
            spp = spp + v[i];
        if (v[i] % 10 == 0)
            ++cnt;
        if (v[i] % 3 == 0 && i % 2 != 0)
            si = si + v[i];
    }
    for (i = n; i >= 1; --i)
        cout << v[i] << " ";
    cout << endl << sp << endl << spp << endl << cnt << endl << si;
    return 0;
}
