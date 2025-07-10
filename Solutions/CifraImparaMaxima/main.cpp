#include <iostream>

using namespace std;

int main()
{
    long long n;
    int m = 0, u;
    cin >> n;
    while (n) {
        u = n % 10;
        if (u % 2 == 1 && u > m)
            m = u;
        n = n / 10;
    }
    if (m == 0)
        cout << "nu exista";
    else
        cout << m;
    return 0;
}
