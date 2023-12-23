#include <bits/stdc++.h>

#define VMAX 4000000

using namespace std;

int X,Y, auxx, auxy;
int Q;
int Maxp[VMAX+1], Nivel[VMAX+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i, j;
    Maxp[1] = 1;
    Nivel[1] = 0;
    for (i = 2; i <= VMAX; i++)
        if (Maxp[i] == 0) {
            Nivel[i] = 1;
            Maxp[i] = i;
            j = i + i;
            while (j <= VMAX) {
                Maxp[j] = i;
                Nivel[j] = 1 + Nivel[j / Maxp[j]];
                j = j + i;
            }
        }
    cin >> Q;
    for (i = 1; i <= Q; ++i) {
        cin >> X >> Y;
        if (X == Y) {
            cout << "0\n";
            continue;
        }
        auxx = X;
        auxy = Y;
        int cntx = 0, cnty = 0;
        while (X > 1 && X != Y && Y > 1){
            if (X > Y) {
                X /= Maxp[X];
                cntx++;
            }
            else if (Y > X) {
                Y /= Maxp[Y];
                cnty++;
            }
        }
        (X == Y) ? cout << (Nivel[auxx] - Nivel[X]) + (Nivel[auxy] - Nivel[X]) << "\n" : cout << (Nivel[auxx] + Nivel[auxy]) << "\n";
    }
    return 0;
}