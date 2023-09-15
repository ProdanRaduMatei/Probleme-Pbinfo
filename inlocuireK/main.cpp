#include <iostream>

using namespace std;

int main()
{
    int n, k, v[201], a, c;
    cin >> k >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        c = a / k;
        if ((c + 1) * k - a < a - c * k)
            v[i] = k * (c + 1);
        else
            v[i] = k * c;
    }
    for (int i = n; i >= 1; --i)
        cout << v[i] << " ";
    return 0;
}
