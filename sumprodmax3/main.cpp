#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    int r = n % 3;
    n = n / 3;
    if (r == 0)
        cout << n << " " << n << " " << n;
    if (r == 1)
        cout << n << " " << n << " " << n + 1;
    if (r == 2)
        cout << n << " " << n << " " << n + 2;
    return 0;
}
