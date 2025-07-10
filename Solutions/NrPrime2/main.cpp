#include <iostream>

using namespace std;

int NrPrime(long long n) {
    int v[10] = {0}, cnt = 0;
    while (n) {
        ++v[n % 10];
        n = n / 10;
    }
    cnt = v[3] + v[5] + v[2] + v[7];
    return cnt;
}

int main()
{
    long long n;
    cin >> n;
    cout << NrPrime(n);
    return 0;
}
