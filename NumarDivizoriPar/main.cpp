#include <iostream>

using namespace std;

int main()
{
    int n, d, cnt = 0;
    cin >> n;
    if (n <= 1)
        cout << 1;
    else
    {
        for (d = 2; d <= n / 2; d = d + 2)
            if (n % d == 0)
                ++cnt;
    }
    if (n % 2 == 0)
        ++cnt;
    cout << cnt;
    return 0;
}
