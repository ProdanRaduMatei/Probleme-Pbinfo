#include <iostream>

using namespace std;

int main()
{
    int n, m, s, s1, a;
    cin >> n >> m;
    if (n == m) {
        s = (n * (n - 1)) / 2;
    }
    else if (n > m) {
        a = n * m;
        s1 = m * (m + 1) / 2;
        s = a - s1;
    }
    else if (m > n) {
        a = n * m;
        s1 = n * (n + 1) / 2;
        s = a - s1;
    }
    cout << s;
    return 0;
}
