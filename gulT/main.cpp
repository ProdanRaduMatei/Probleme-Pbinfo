#include <iostream>

using namespace std;

int main()
{
    long long n;
    int s = 0;
    cin >> n;
    if (n % 2 == 0)
        s = s + 2;
    for (int d = 3; d * d <= n; d = d + 2)
        if (n % d == 0)
            s = s + d;
    cout << s;
    return 0;
}
