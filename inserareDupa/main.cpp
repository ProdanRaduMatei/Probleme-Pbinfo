#include <iostream>

using namespace std;

int main()
{
    int n, i, v[55], j;
    cin >> n;
    for (i = 0; i < n; ++i)
        cin >> v[i];
    for (i = 0; i < n; ++i) {
        if (v[i] % 2 == 0) {
            for (j = n + 1; j > i; --j)
                v[j] = v[j - 1];
            ++n;
            v[i + 1] = 2 * v[i];
            ++i;
        }
    }
    for (i = 0; i < n; ++i)
        cout << v[i] << " ";
    return 0;
}
