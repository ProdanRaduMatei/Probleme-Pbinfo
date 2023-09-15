#include <iostream>

using namespace std;

int cmmdp(int n) {
    int d = 2, p = 0, var = 0;
    while (n > 1) {
        p = 0;
        while (n % d == 0) {
            p++;
            n /= d;
        }
        if (p != 0)
            var = d;
        d++;
        if (d * d > n)
            d = n;
    }
    return var;
}

int main()
{
    int n;
    cin >> n;
    int tmp;
    long long int s = 0;
    for (int i = 1 ; i <= n ; ++i) {
        cin >> tmp;
        s += cmmdp(tmp);
    }
    cout << s;
    return 0;
}
