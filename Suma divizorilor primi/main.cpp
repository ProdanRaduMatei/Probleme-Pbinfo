#include <iostream>

using namespace std;

void sum_div_prim(int n, int &s) {
    s = 0;
    if (n % 2 == 0) {
        s = s + 2;
        while (n % 2 == 0)
            n = n / 2;
    }
    int d = 3;
    while (d * d <= n) {
        if (n % d == 0) {
            s = s + d;
            while (n % d == 0)
                n = n / d;
        }
        d = d + 2;
    }
    if (n > 1)
        s = s + n;
}

int main()
{
    int n, s;
    cin >> s;
    sum_div_prim(n, s);
    cout << s;
    return 0;
}
