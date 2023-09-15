#include <iostream>
#include <algorithm>

using namespace std;

int n, v[1001];
int main()
{
    cin >> n;
    for (int  i = 1; i <= n; ++i) {
        cin >> v[i];
        while (v[i] > 9)
            v[i] = v[i] / 10;
    }
    sort (v + 1, v + 1 + n);
    for (int i = 1; i <= n; ++i)
        cout << v[i];
    return 0;
}
