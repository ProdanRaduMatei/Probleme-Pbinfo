#include <iostream>

using namespace std;

int main()
{
    int n, v[1000], p = 0, u = 0, s = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        if (v[i] % 2 == 1 && p == 0)
            p = i;
        if (v[i] % 2 == 1)
            u = i;
    }
    for (int i = p; i <= u; ++i)
        s = s + v[i];
    cout << s;
    return 0;
}
