#include <iostream>

using namespace std;

int n, m, cnt, u;
int main()
{
    cin >> n;
    while (n) {
        u = n % 10;
        n = n / 10;
        if (u == m)
            ++cnt;
        if (u > m) {
            m = u;
            cnt = 1;
        }
    }
    cout << m << " " << cnt;
    return 0;
}
