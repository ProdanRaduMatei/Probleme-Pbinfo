#include <iostream>

using namespace std;

int sumfactcif(int n) {
    int u, s = 0, p;
    while (n) {
        u = n % 10;
        p = 1;
        for (int i = 1; i <= u; ++i)
            p = p * i;
        if (u == 0)
            p = 1;
        s = s + p;
        n = n / 10;
    }
    return s;
}

int main()
{
    int n;
    cin >> n;
    cout << sumfactcif(n);
    return 0;
}
