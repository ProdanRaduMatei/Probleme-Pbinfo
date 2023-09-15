#include <iostream>
#include <algorithm>

using namespace std;

int n, m = 0, v[1001], p;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        if (v[i] > m) {
            m = v[i];
            p = i;
        }
    }
    sort (v + 1, v  + p);
    sort (v + 1 + p, v + 1 + n);
    for (int i = 1; i <= p; ++i)
        cout << v[i] << " ";
    for (int i = n; i > p; --i)
        cout << v[i] << " ";
    return 0;
}
