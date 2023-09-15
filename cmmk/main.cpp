#include <iostream>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    while (n) {
        if (n % 10 > k) {
            cout << "NU";
            return 0;
        }
        n = n / 10;
    }
    cout << "DA";
    return 0;
}
