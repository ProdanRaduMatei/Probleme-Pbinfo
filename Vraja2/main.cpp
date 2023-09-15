#include <iostream>
using namespace std;
long long a[1001], n;
int result, sst, slen, mt;
bool ram;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    while (true) {
        ram = false;
        for (int i = 1; i <= n; ++i)
            if (a[i])
                ram = true;
        if (!ram)
            break;
        sst = 0;
        slen = 0;
        for (int i = 1; i <= n; ++i) {
            if (sst == 0 && a[i])
                sst = i;
            if (sst > 0 && a[i])
                ++slen;
            if (sst > 0 && !a[i])
                break;
        }
        mt = a[sst];
        for (int i = sst; i < sst + slen; ++i)
            if (mt > a[i])
                mt = a[i];
        for (int i = sst; i < sst + slen; ++i)
            a[i] = a[i] - mt;
        ++result;
    }
    cout << result;
    return 0;
}
