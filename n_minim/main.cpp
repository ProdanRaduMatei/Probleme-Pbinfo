#include <iostream>

using namespace std;

int main()
{
    int n, i;
    long long int a, m = 1000000000;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> a;
        if (a < m)
            m = a;
    }
    cout << m;
    return 0;
}
