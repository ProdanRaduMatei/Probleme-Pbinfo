#include <iostream>

using namespace std;

int main()
{
    int n, v[7][7], c;
    cin >> n;
    for (int i = 1; i <= 6; ++i)
        v[i][i]= 0;
    for (int i = 2; i <= 6; ++i) {
        v[i][1] = n % 10;
        v[1][i] = n % 10;
    }
    n = n / 10;
    for (int i = 3; i <= 6; ++i) {
        v[i][2] = n % 10;
        v[2][i] = n % 10;
    }
    n = n / 10;
    for (int i = 4; i <= 6; ++i) {
        v[i][3] = n % 10;
        v[3][i] = n % 10;
    }
    n = n / 10;
    for (int i = 5; i <= 6; ++i) {
        v[i][4] = n % 10;
        v[4][i] = n % 10;
    }
    n = n / 10;
    v[6][5] = n % 10;
    v[5][6] = n % 10;
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
