#include <iostream>

using namespace std;

int u, p = 1, cnt;
long long n;
int main()
{
    cin >> n;
    while (n) {
        u = n % 10;
        if (u % 2 != 0) {
            p = p * u;
            ++cnt;
        }
        n = n / 10;
    }
    if (cnt == 0)
        cout << "-1";
    else
        cout << p;
    return 0;
}
