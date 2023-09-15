#include <iostream>

using namespace std;

int nr_cif_zero(long long n) {
    int cnt = 0;
    while (n) {
        if (n % 10 == 0)
            ++cnt;
        n = n / 10;
    }
    return cnt;
}

int main()
{
    long long n;
    cin >> n;
    cout << nr_cif_zero(n);
    return 0;
}
