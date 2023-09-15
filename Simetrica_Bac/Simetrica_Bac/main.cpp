#include <iostream>

using namespace std;

int main()
{
    int l, c, v[102][102] = {0}, s = 0;
    cin >> l >> c;
    for (int i = 1; i <= l; ++i)
        for (int j = 1; j <= c; ++j)
            cin >> v[i][j];
    for (int i = 1; i <= l; ++i)
        for (int j = 1; j <= c / 2; ++j)
            if (v[i][j] != v[i][c - j + 1])
            {
                cout << "NU";
                return 0;
            }
    cout << "DA";
    return 0;
}
