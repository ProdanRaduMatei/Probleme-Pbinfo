#include <iostream>

using namespace std;

int main()
{
    long long n;
    int a, z, l;
    cin >> n;
    z = n / 1000000 % 100;
    l = n / 100000000 % 100;
    a = n / 10000000000 % 100;
    if (a <= 9)
        cout << "0" << a << " ";
    else
        cout << a << " ";
    if (l <= 9)
        cout << "0" << l << " ";
    else
        cout << l << " ";
    if (z <= 9)
        cout << "0" << z;
    else
        cout << z;
    return 0;
}
