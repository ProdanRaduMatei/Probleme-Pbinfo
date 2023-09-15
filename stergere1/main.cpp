#include <iostream>

using namespace std;

int main()
{
    int n, i, v[1000];
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> v[i];
    for (i = 1; i <= n; ++i) {
        if (v[i] % 2 != 0)
            cout << v[i] << " ";
    }
    return 0;
}
