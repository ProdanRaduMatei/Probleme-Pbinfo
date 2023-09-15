#include <iostream>

using namespace std;

bool prim(int x) {
    if (x < 2)
        return 0;
    if (x == 0)
        return 1;
    if (x % 2 == 0)
        return 1;
    for (int i = 3; i * i <= x; i = i + 2)
        if (x % i == 0)
            return 0;
    return 1;
}

int main()
{
    int n, p = 1, cn;
    cin >> n;
    cn = n;
    while (n) {
        n = n / 10;
        p = p * 10;
    }
    n = cn;
    if (n == 0)
        cout << "NU";
    else {
        while (n) {
            if (prim(n) == 0) {
                cout << "NU";
                return 0;
            }
            n = n % p;
            p = p / 10;
        }
        cout << "DA";
    }
    return 0;
}
