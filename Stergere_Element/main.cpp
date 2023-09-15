#include <iostream>

using namespace std;

int main()
{
    int n, p, i, v[1500];
    cin >> n >> p;
    for (i = 1; i <= n; ++i)
        cin >> v[i];
    for (i = 1; i < p; ++i)
        cout << v[i] << " ";
    for (i = p + 1; i <= n; ++i)
        cout << v[i] << " ";
    return 0;
}
