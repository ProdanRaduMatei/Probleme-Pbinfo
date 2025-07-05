#include <iostream>

using namespace std;

int main()
{
    long long a, b, c;
    int cn = 0;
    bool ok = 1;
    cin >> a >> b;
    for (long long i = a; i <= b; ++i) {
        c = i;
        ok = 1;
        while (c && ok == 1) {
            if (c % 10 != 0)
                if (i % (c % 10) != 0)
                    ok = 0;
            c = c / 10;
        }
        if (ok == 1)
            ++cn;
    }
    cout << cn;
    return 0;
}
