#include <iostream>

using namespace std;

int main()
{
    long long n, exp2 = 0, exp5 = 0, num, nrz;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        while (num % 2 == 0) {
            ++exp2;
            num = num / 2;
        }
        while (num % 5 == 0) {
            ++exp5;
            num = num / 5;
        }
    }
    nrz = min(exp2, exp5);
    cout << nrz;
    return 0;
}
