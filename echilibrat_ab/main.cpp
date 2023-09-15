#include <iostream>

using namespace std;

int main()
{
    int a, b, s = 0;
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        int x = i, c1 = 0, c2 = 0, uc;
        while (x != 0) {
            uc = x % 10;
            if (uc % 2 == 0)
                ++c1;
            else
                ++c2;
            x = x / 10;
        }
        if (c1 == c2)
            s = s + i;
    }
    cout << s;
    return 0;
}
