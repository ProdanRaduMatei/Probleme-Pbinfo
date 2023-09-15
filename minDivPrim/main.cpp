#include <iostream>

using namespace std;

int minDivPrim(int n)
{
    int d, fm, nr = 1;
    d = 2;
    do {
        fm = 0;
        while (n % d == 0) {
            fm = fm + 1;
            n = n / d;
        }
        if (fm > 0)
            nr = nr * d;
        d = d + 1;
        if (n > 1 && d * d > n)
            nr = nr * n, n = 1;
    } while (n > 1);
    return nr;
}

int main()
{
    int n;
    cin >> n;
    cout << minDivPrim(n);
    return 0;
}
