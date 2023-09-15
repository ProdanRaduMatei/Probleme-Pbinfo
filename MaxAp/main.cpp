#include <iostream>

using namespace std;

int main()
{
    int n, m, v[101][101], cnt = 0, M = 0;
    long long int c[1000001] = {0};
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j){
            cin >> v[i][j];
            ++c[v[i][j]];
            if (v[i][j] > M)
                M = v[i][j];
        }
    }
    for (int i = 0; i <= M; ++i)
        if (cnt < c[i])
            cnt = c[i];
    for (int i = 0; i <= M; ++i)
        if (c[i] == cnt)
            cout << i << " ";
    return 0;
}
