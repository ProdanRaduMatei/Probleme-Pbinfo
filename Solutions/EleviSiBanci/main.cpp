#include <iostream>

using namespace std;

int main()
{
    int n, m, e, b;
    int x, y;
    cin >> n >> m >> e >> b;
    y = ((b * m) + e) / (m - n);
    x = n * y + e;
    cout << x << endl << y;
    return 0;
}
