#include <iostream>

using namespace std;

int n, p;
long long x, v[26];
int main()
{
    cin >> n >> x >> p;
    ++n;
    for (int i = 1; i <= n; ++i) {
        if (i == p) {
            v[i] = x;
        }
        else
            cin >> v[i];
    }
    for (int i = 1; i <= n; ++i)
        cout << v[i] <<  " ";
    return 0;
}
