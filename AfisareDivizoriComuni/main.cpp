#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b;
    c = __gcd(a, b);
    for (int i = 1; i <= c; ++i)
        if (c % i == 0)
            cout << i << " ";
    return 0;
}
