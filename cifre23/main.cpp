#include <iostream>

using namespace std;

int main()
{
    long long n;
    int nr2 = 0, nr3 = 0, cif;
    cin >> n;
    while (n) {
        cif = n % 10;
        if (cif == 2)
            ++nr2;
        else
            ++nr3;
        n = n / 10;
    }
    if (nr2 == nr3)
        cout << 2 << " " << 3;
    else if (nr2 < nr3)
        cout << 3;
    else
        cout << 2;
    return 0;
}
