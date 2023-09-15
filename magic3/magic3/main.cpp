#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("magic3.in");
ofstream fout("magic3.out");

int nrdivizori(int x)
{
    int c = 0;
    for (int d = 1; d * d <= x; ++d)
        if (x % d == 0)
        {
            ++c;
            if (x / d != d)
                ++c;
        }
    return c;
}

int main() {
    int n, x, c = 0, m = 100000000;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        int y = nrdivizori(x);
        if (y == m)
            ++c;
        if (y < m)
        {
            m = y;
            c = 1;
        }
    }
    cout << c;
    return 0;
}
