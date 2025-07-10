#include <iostream>

using namespace std;

int kpn(int a, int b, int k)
{
    int i = a;
    while (k && i <= b)
    {
        int s = i + 1;
        for (int d = 2; d * d <= i; ++d)
            if (i % d == 0)
            {
                s = s + d;
                if (d != i / d)
                    s = s + i / d;
            }
        if (s % 2 == i % 2)
            --k;
        ++i;
    }
    if (k > 0)
        return -1;
    return --i;
}

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    cout << kpn(a, b, k);
    return 0;
}
