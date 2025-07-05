#include <iostream>

using namespace std;
int n, u, cnt, c;
int main()
{
    cin >> n;
    u = n % 10;
    n = n / 10;
    ++cnt;
    while (n) {
        c = n % 10;
        if (c == u)
            ++cnt;
        n = n / 10;
    }
    cout << cnt;
    return 0;
}
