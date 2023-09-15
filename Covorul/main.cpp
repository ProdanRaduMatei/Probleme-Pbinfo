#include <iostream>

using namespace std;

int main()
{
    int n, m, c = 0;
    cin >> n >> m;
    cout << min(n, m) << " ";
    while (n > 0 && m > 0) {
        if (min(n, m) == n)
            m = m - n;
        else
            n = n - m;
        ++c;
    }
    cout << c;
    return 0;
}
