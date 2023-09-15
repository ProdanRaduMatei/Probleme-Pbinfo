#include <iostream>

using namespace std;

int rad(int x)
{
    for (int d = 1; d * d <= x; ++d)
        if (d * d == x)
            return d;
    return 0;
}

int n;
long long v[26], m;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= n; ++i) {
        m = rad(v[i]);
        if (m != 0) {
            for (int j = i; j <= n; ++j) {
                v[j + 1] = v[j];
            }
            ++n;
            v[i] = m;
            ++i;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << v[i] << " ";
    return 0;
}
