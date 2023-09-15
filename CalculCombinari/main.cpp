#include <iostream>

using namespace std;

int main()
{
    long long fn = 1, fk = 1;
    int n, k;
    cin >> n >> k;
    for (int i = n - k + 1; i <= n; ++i)
        fn = fn * i;
    for (int i = 1; i <= k; ++i)
        fk = fk * i;
    cout << fn / fk;
    return 0;
}
