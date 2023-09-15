#include <iostream>

using namespace std;

int main()
{
    int n, v[21], c = 0, ok = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        if (i > n / 2) {
            ok = 0;
            for (int j = 1; j <= n / 2; ++j)
                if (v[i] <= v[j])
                    ok = 1;
            if (ok == 0)
                ++c;
        }
    }
    cout << c;
    return 0;
}
