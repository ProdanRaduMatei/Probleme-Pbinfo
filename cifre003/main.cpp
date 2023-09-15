#include <iostream>

using namespace std;

int main()
{
    long long n;
    int c[11] = {0}, i = 0, s = 0, cn = 0;
    cin >> n;
    while (n) {
        s = s + n % 10;
        c[i] = n % 10;
        n = n / 10;
        ++i;
    }
    for (int j = 0; j < i; ++j)
        if ((s - c[j]) % 3 == 0)
            ++cn;
    cout << cn;
    return 0;
}
