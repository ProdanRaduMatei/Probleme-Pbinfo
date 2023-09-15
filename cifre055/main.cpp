#include <iostream>

using namespace std;

int main()
{
    int n, r, cn = 0;
    long long x;
    cin >> n >> r;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (x % 9 == r)
            ++cn;
    }
    cout << cn;
    return 0;
}
