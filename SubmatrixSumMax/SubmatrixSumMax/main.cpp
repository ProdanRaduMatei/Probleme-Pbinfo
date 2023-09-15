#include <iostream>

using namespace std;

int main() {
    int n , a[301][301] , maxi , sp , b[301];
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= n ; j++) {
            cin >> a[i][j];
            a[i][j] += a[i - 1][j];
        }
    maxi = -10000;
    for (int i = 1 ; i <= n ; i++)
        for (int j = i ; j <= n ; j++) {
            for (int k = 1 ; k <= n ; k++)
                b[k] = a[j][k] - a[i - 1][k];
            int sp = 0;
            for (int k = 1 ; k <= n ; k++) {
                sp += b[k];
                if (sp > maxi)
                    maxi = sp;
                if (sp < 0)
                    sp = 0;
            }
        }
    cout << maxi;
    return 0;
}
