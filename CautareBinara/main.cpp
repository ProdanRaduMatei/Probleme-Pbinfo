#include <iostream>

using namespace std;

int n, x[25001];

int caut(int s, int d, int a) {
    if (s > d)
        return 0;
    else {
        int mj = (s + d) / 2;
        if (a == x[mj])
            return 1;
        if (a < x[mj])
            return caut(s, mj - 1, a);
        if (a > x[mj])
            return caut(mj + 1, d, a);
    }
}

int main()
{
    int m, y[200001], mj, s, d;
    cin >> n;
    mj = n / 2;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> y[i];
        cout << caut(1, n, y[i]) << " ";
    }
    return 0;
}
