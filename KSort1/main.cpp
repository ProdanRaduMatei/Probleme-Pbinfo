#include <iostream>

using namespace std;

int main()
{
    int n, v[1001], k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int p = 1; p <= k; ++p)
        for (int i = p; i <= n; i = i + k)
            for (int j = i; j <= n; j = j + k)
                if (v[i] > v[j])
                    swap (v[i], v[j]);
    for (int i = 1; i <= n; ++i)
        cout << v[i] << " ";
    return 0;
}
