#include <iostream>

using namespace std;

int main()
{
    int n, v[25][25];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i % 2 == 0)
                v[i][j] = j;
            else
                v[i][j] = i;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
