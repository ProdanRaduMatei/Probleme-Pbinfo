#include <bits/stdc++.h>
using namespace std;
ifstream fin ("lipsa.in");
ofstream fout ("lipsa.out");

const int nMAX = 10e3;
const int mMAX = 10e3;

int n;
int x[nMAX + 1];
int m;
int y[nMAX + 1];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    cin >> m;
    for (int i = 1; i <= m; ++i)
        cin >> y[i];
    int *minY = min_element(y + 1, y + m + 1);
    bool exista = false;
    for (int i = 1; i <= n; ++i)
        if (x[i] < *minY) {
            cout << x[i] << ' ';
            exista = true;
        }
    if (!exista)
        cout << "NU EXISTA";
}