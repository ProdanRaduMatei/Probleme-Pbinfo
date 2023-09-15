#include <iostream>

using namespace std;

int main()
{
    int n, v[10000], cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= n; ++i)
        cout << v[i] << " ";
    cout << "\n";
    do {
        cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (v[i] % 2 == v[i + 1] % 2 && v[i] != v[i + 1]) {
                ++n;
                for (int j = n; j > i; --j)
                    v[j] = v[j - 1];
                v[i + 1] = (v[i] + v[i + 2]) / 2;
                ++i;
                if (v[i - 1] % 2 == v[i - 2] % 2 && v[i - 2] != v[i - 1])
                    ++cnt;
                if (v[i - 1] % 2 == v[i] % 2 && v[i] != v[i - 1])
                    ++cnt;
            }
        }
        for (int i = 1; i <= n; ++i)
            cout << v[i] << " ";
        cout << "\n";
    }while (cnt != 0);
    return 0;
}
