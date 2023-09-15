#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

struct elev{
    char nume[101], prenume[101];
    float m1, m2, m3, mg;
}e[101];

int main()
{
    int n, p, c = 0;
    float mgc = 0, s = 0;
    cin >> n >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> e[i].nume >> e[i].prenume >> e[i].m1 >> e[i].m2 >> e[i].m3;
        e[i].mg = float(e[i].m1 + e[i].m2 + e[i].m3) / 3;
        s = (float)s + e[i].mg;
    }
    mgc = (float)s / n;
    if (p == 1) {
        for (int i = 1; i <= n; ++i)
            if (e[i].mg >= mgc)
                ++c;
        cout << c;
    }
    else {
        cout << fixed <<setprecision(2) << mgc << endl;;
        for (int i = 1; i < n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (e[i].mg < e[j].mg)
                    swap(e[i], e[j]);
                else if (e[i].mg == e[j].mg) {
                    if (strcmp(e[i].nume, e[i].nume) > 0)
                        swap(e[i], e[j]);
                    else if (strcmp(e[i].nume, e[i].nume) == 0)
                        if (strcmp(e[i].prenume, e[i].prenume) > 0)
                            swap(e[i],e[j]);
                }
        for (int i = 1; i <= n; ++i)
            cout << e[i].nume << " " << e[i].prenume << " " << e[i].mg << endl;
    }
    return 0;
}
