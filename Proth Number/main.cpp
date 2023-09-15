#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    --n;
    while (n % 2 == 0)
        n = n / 2;
    if (n % 2 == 0)
        cout << "NU";
    else
        cout << "DA";
    return 0;
}
