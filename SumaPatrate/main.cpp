#include <iostream>
#include <algorithm>

using namespace std;

long long n, x;

int main()
{
    cin >> n;
    x = (((n % 10234573) * ((n + 1) % 10234573) * ((2 * n + 1) % 10234573)) / 6) % 10234573;
    cout << x;
    return 0;
}
