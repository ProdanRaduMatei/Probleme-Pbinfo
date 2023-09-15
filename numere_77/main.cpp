#include <iostream>

using namespace std;

int main()
{
    long long a, b, s = 0;
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        int x = i, sp = 0, si = 0, uc;
        while (x != 0) {
            uc = x % 10;
            if (uc % 2 == 0)
                sp = sp + uc;
            else
                si = si + uc;
            x = x / 10;
        }
        if (sp == si)
            s = s + i;
    }
    cout << s;
    return 0;
}
