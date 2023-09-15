#include <iostream>

using namespace std;

int main()
{
    int n, t, v[200000], x, y;
    cin >> n >> t;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= t; ++i) {
        cin >> x >> y;
        int c = 0;
        for (int j = 1; j <= n; ++j)
            if (v[j] <= y && v[j] >= x)
                ++c;
        cout << c << endl;
    }
    return 0;
}
