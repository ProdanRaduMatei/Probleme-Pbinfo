#include <iostream>

using namespace std;

int main()
{
    int n, v[10], c;
    long long x;
    bool ok = 1;
    cin >> n;
    for (int a = 1; a <= n; ++a) {
        cin >> x;
        int y = x % 10, i = 0, j = 0, ok1 = 1, ok2 = 1 ;
        x = x / 10;
        if (x % 10 < y)
            ok = 1;
        else
            while (x != 0) {
                if (!ok2)
                    ++j;
                if (x % 10 > y && ok2)
                    ++i;
                else if (x % 10 < y) {
                    if (j == 0)
                        ++j;
                    ok2 = 0;
                }
                else
                    ok1 = 0;
                y = x % 10;
                x = x / 10;
            }
        if (ok1 && i != 0 && j != 0)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
