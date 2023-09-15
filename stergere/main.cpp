#include <iostream>

using namespace std;

int prim(int x)
{
    if (x <= 1)
        return 0;
    if (x == 2)
        return 1;
    if (x % 2 == 0)
        return 0;
    for (int d = 3; d * d <= x; ++d)
        if (x % d == 0)
            return 0;
    return 1;
}
int n, v[1001];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= n; ++i) {
        if (prim(v[i]) == 1) {
            for (int j = i; j < n; ++j)
                v[j] = v[j + 1];
            --n;
            --i;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << v[i] << " ";
    return 0;
}
