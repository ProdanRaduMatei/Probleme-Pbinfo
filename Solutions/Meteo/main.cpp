#include <fstream>

using namespace std;

ifstream fin("meteo.in");
ofstream fout("meteo.out");

int v[1005], n, lmax, ll, poz;

int main() {
    fin >> n;
    fin >> v[1];
    ll = 0;
    poz = 1;
    for (int i = 2; i <= n; i++) {
        fin >> v[i];
        if ((v[i] < 0 && v[i - 1] > 0) || (v[i] > 0 && v[i - 1] < 0) || (v[i - 1] < 0 && v[i] == 0) || (v[i - 1] == 0 && v[i] < 0))
            ll++;
        else {
            if (ll >= lmax) {
                lmax = ll;
                poz = i - ll - 1;
            }
            ll = 0;
        }
    }
    if (ll >= lmax) {
        lmax = ll;
        poz = n - ll;
    }
    if (lmax) {
        fout << lmax + 1 << "\n";
        if (poz == 0)
            poz++;
        for (int i = poz; i <= poz + lmax; i++)
            fout << v[i] << " ";
    }
    else
        fout << 0;
    return 0;
}