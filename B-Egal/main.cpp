#include <iostream>

using namespace std;

int Egal(long long n) {
    int v[10] = {0};
    bool ok = 1;
    int u = 0;
    while (n) {
        if ((n % 10) % 2 != 0) {
            if (u == 0)
                u = n % 10;
            else {
                if (u != n % 10)
                    ok = 0;
            }
        }
        n = n / 10;
    }
    return ok;
}

int main()
{
    long long n;
    cin >> n;
    cout << Egal(n);
    return 0;
}
