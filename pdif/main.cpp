#include <fstream>

using namespace std;

int n, crnt, i, x, ct, mt, m, poz;
short int v[100001];
ifstream fin("pdif.in");
ofstream fout("pdif.out");

short int cif(int a) {
    if (a % 9 == 0)
        a = 9;
    else
        a %= 9;
    return a;
}

int main() {
    fin >> n >> crnt;
    for (i = 1; i <= n; i++) {
        fin >> x;
        v[i] = cif(x);
    }
    if (crnt == 1) {
        ct = 1;
        for (i = 2; i <= n; i++)
            if ((v[i] % 2 == 0 && v[i - 1] % 2 == 1) || (v[i] % 2 == 1 && v[i - 1] % 2 == 0))
                ct++;
            else {
                if (ct > m) {
                    m = ct;
                    mt = 1;
                }
                else if (ct == m)
                    mt++;
                ct = 1;
            }
        if (ct > m) {
            m = ct;
            mt = 1;
        }
        else if (ct == m)
            mt++;
        fout << m << ' ' << mt;
    }
    else {
        for (i = 2; i <= n; i++)
            if ((v[i] % 2 == 0 && v[i - 1] % 2 == 1) || (v[i] % 2 == 1 && v[i - 1] % 2 == 0))
                ct++;
            else {
                if (ct > m) {
                    m = ct;
                    poz = i - 1;
                }
                ct = 0;
            }
        if (ct > m) {
            poz = n;
            m = ct;
        }
        fout << poz - m << ' ' << poz;
    }
}