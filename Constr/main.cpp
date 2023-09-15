#include <iostream>

using namespace std;

int main()
{
    int n, s, v[201], y[201], c;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        s = 0;
        c = v[i];
        while (c) {
            s = s + c % 10;
            c = c / 10;
        }
        y[i] = v[i] % s;
    }
    for (int i = 1; i <= n; ++i)
        cout << y[i] << " ";
    return 0;
}
