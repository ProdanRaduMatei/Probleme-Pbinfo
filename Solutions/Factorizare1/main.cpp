#include <iostream>

using namespace std;

int main()
{
    long long n, d, fm, fact, maxx = 0;
    cin >> n;
    d = 2;
    do {
        fm = 0;
        while (n % d == 0) {
            ++fm;
            n = n / d;
        }
        if ((fm > 0) && (fm >= maxx))
            maxx = fm, fact = d;
        ++d;
        if ((n > 1) && (d * d > n))
            if (maxx > 1)
                n = 1;
        else
            fact = n, n = 1;
    }while (n > 1);
    cout << fact;
    return 0;
}
