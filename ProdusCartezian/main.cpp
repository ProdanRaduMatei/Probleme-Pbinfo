#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    cout << "{";
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (i != n || j != m)
                cout << "(" << i << "," << j << "),";
    cout << "(" << n << "," << m << ")}";
    return 0;
}
