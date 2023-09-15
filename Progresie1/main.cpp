#include <iostream>

using namespace std;

int main()
{
    int n, v[201][201], a, r;
    cin >> a >> r  >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            v[j][i] = a;
            a = a + r;
        }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
