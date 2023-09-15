#include <iostream>

using namespace std;

int n, c[10], x;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        while (x) {
            ++c[x % 10];
            x = x / 10;
        }
    }
    int m = 100000;
    for (int i = 1; i <= n; ++i)

    return 0;
}
