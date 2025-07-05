#include <iostream>

using namespace std;

int main()
{
    long long n, a, m = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        while (a) {
            if (a % 10 > m)
                m = a % 10;
            a = a / 10;
        }
    }
    cout << m + 1;
    return 0;
}
