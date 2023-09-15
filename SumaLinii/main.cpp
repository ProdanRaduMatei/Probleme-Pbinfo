#include <iostream>

using namespace std;

int main()
{
    int n, m, i, j, v[100][100], S[100], M = 0, c, C[100];
    cin >> n >> m;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= m; ++j) {
            cin >> v[i][j];
        }
    }
    for (i = 1; i <= n; ++i) {
        M = 0;
        c = 0;
        for (j = 1; j <= m; ++j) {
            if (v[i][j] >= M) {
                if (v[i][j] == M)
                    ++c;
                if (v[i][j] > M) {
                    M = v[i][j];
                    c = 1;
                }
            }
        }
        C[i] = c;
        S[i] = 0;
        for (j = 1; j <= m; ++j) {
            if (v[i][j] != M)
                S[i] = S[i] + v[i][j];
            if (v[i][j] == M && C[i] < 1) {
                S[i] = S[i] + v[i][j];
                --C[i];
            }
        }
    }
    for (i = 1; i <= n; ++i)
        cout << S[i] << " ";
    return 0;
}
