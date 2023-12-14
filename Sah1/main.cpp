#include <fstream>
#include <cstring>
using namespace std;

ifstream cin ("sah1.in");
ofstream cout ("sah1.out");

struct poz {
    int i, j;
    void citeste() {
        cin >> i >> j;
    }
};

int main() {
    int c, n, m, i;
    cin >> c >> n >> m;
    poz rege, ture[m];
    rege.citeste();
    for (i = 0; i < m; ++i)
        ture[i].citeste();
    if (c == 1) {
        int ture_sah = 0;
        for (poz tura : ture)
            if (tura.i == rege.i || tura.j == rege.j)
                ture_sah ++;
        cout << ture_sah;
    }
    else {
        bool ture_lin[n], ture_col[n];
        int lin_libere, col_libere;
        memset(ture_lin, 0, n);
        memset(ture_col, 0, n);
        for (poz tura : ture) {
            ture_lin[tura.i - 1] = true;
            ture_col[tura.j - 1] = true;
        }
        lin_libere = 0;
        col_libere = 0;
        for (i = 0; i < n; ++i) {
            if (ture_lin[i] == false)
                lin_libere++;
            if (ture_col[i] == false)
                col_libere++;
        }
        cout << lin_libere * col_libere;
    }
    return 0;
}