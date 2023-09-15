#include <iostream>

using namespace std;

int main()
{
    int n, v[21][21], c = 2;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (c % 3 != 0 && c % 2 == 0)
                v[i][j] = c;
            else {
                c = c + 2;
                v[i][j] = c;
            }
            c = c + 2;
        }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
