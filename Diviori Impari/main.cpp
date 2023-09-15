#include <iostream>

using namespace std;

int main()
{
    int n;
    long long x;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        while (x % 2 == 0)
            x = x / 2;
        cout << x << " ";
    }
    return 0;
}
