#include <iostream>
using namespace std;
const int dm = 101;
int n, m, cant[dm], magazine[dm][dm];
int main() {
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> cant[i];
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> magazine[i][j];
    long long mini = 100000000;
    for (int i = 0; i < n; i++) {
        bool nueste = true;
        int S = 0;
        for (int j = 0; j < m && nueste; j++) {
            if (magazine[i][j] == -1)
                nueste = false;
            S += magazine[i][j] * cant[j];
        }
        if (nueste && S < mini)
            mini = S;
    }
    cout << mini;
    return 0;
}
