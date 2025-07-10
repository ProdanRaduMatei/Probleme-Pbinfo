#include <iostream>

using namespace std;

int cmmnr(long long n) {
    int v[10] = {0}, m = 0;
    while (n) {
        ++v[n % 10];
        n = n / 10;
    }
    int i = 0;
    if (v[0] > 0) {
        ++i;
        while (v[i] == 0)
            ++i;
        m = v[i];
    }
    i = 0;
    while (v[i] >= 0 && i <= 9) {
        m = m * 10 + v[i];
        if (v[i] > 0)
            --v[i];
        else
            ++i;
    }
    return m;
}

int main()
{
    long long n;
    cin >> n;
    cout << cmmnr(n);
    return 0;
}
