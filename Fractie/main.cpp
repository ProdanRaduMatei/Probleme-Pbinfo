#include <iostream>

using namespace std;

int main()
{
    int n, m, x = 0, num;
    cin >> n >> m;
    num = m;
    while (num <= n) {
        x = x + n / num;
        num = num * m;
    }
    cout << x;
    return 0;
}
