#include <iostream>

using namespace std;

int cmmnr(long long n) {
    int v[10] = {0}, m = 0;
    while (n) {
        ++v[n % 10];
        n = n / 10;
    }
    for (int i = 9; i >= 0; --i) {
        while (v[i] > 0) {
            m = m * 10 + i;
            --v[i];
        }
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
