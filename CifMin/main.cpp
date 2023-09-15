#include <iostream>

using namespace std;

int main()
{
    int n, a, c[10] = {0}, m = 9;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        m = 9;
        while (a) {
            if (a % 10 < m)
                m = a % 10;
            a = a / 10;
        }
        ++c[m];
    }
    if (c[0] != 0) {
        int i = 1;
        while (c[i] == 0)
            ++i;
        cout << i;
        --c[i];
        for (i = 0; i <= 9; ++i) {
            while (c[i] > 0) {
                cout << i;
                --c[i];
            }
        }
    }
    return 0;
}
