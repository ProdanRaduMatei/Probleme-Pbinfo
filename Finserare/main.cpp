#include <iostream>

using namespace std;

void inserare(long long &n) {
    short v[11], j = -1, i, dif;
    long long m = n;
    for (i = 0; i < 11; ++i)
        v[i] = 0;
    while (m) {
        v[++j] = m % 10;
        ++j;
        m = m / 10;
    }
    for (int i = 1; i < j - 1; i = i + 2) {
            dif = v[i + 1] - v[i - 1];
            if (dif > 0)
                v[i] = dif;
            else
                v[i] = - dif;
    }
    for (i = j - 1; i >= 0; --i)
        m = m * 10 + v[i];
    n = m;
}

int main()
{
    long long n;
    cin >> n;
    inserare(n);
    cout << n;
    return 0;
}
