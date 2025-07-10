#include <iostream>

using namespace std;

int main()
{
    int n, i, x = 0, v[1000], p, y = 0;
    cin >> n;
    for (i = 1, p = 1; i <= n; ++i, p + p * 10) {
        cin >> v[i];
        x = x * 10 + v[i];
        y = y + v[i] * p;
    }
    cout << x << endl;
    if (x == y)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
