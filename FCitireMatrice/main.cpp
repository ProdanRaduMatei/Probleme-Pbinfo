#include <iostream>

using namespace std;

void citmat(int a[101][101], int &n, int &m) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
}

int main()
{
    int n, m, a[101][101];
    citmat(a, n, m);
    return 0;
}
