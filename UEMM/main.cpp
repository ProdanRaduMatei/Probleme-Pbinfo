#include <iostream>

using namespace std;

int main()
{
    int n, v[1001], m = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= n; ++i) {
        int j = i + 1;
        m = 0;
        while (j <= n && m == 0) {
            if (v[i] < v[j])
                m = 1;
            ++j;
        }
        if (m == 1)
            cout << v[j - 1] << " ";
        else
            cout << "-1 ";
    }
    return 0;
}
