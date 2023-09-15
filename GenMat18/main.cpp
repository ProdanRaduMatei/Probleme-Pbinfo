#include <iostream>

using namespace std;

int main()
{
    int n,v[7][7], a = 0, b = 1, c = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 != 0)
            if (i > 1)
                for (int j = 1; j <= n; ++j) {
                    v[i][j] = a + b;
                    c = a + b;
                    a = b;
                    b = c;
                }
            else {
                v[1][1] = 1;
                for (int j = 2; j <= n; ++j) {
                    v[i][j] = a + b;
                    c = a + b;
                    a = b;
                    b = c;
                }
            }
        else
            for (int j = n; j >= 1; --j) {
                v[i][j] = a + b;
                c = a + b;
                a = b;
                b = c;
            }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
