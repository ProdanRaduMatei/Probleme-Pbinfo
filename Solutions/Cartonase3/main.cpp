#include <fstream>

using namespace std;

ifstream  fin("cartonase.in");
ofstream fout("cartonase.out");

int main() {
    int i, n, task; /// cerinta
    int a1, b1; /// a1, b1 = valorile de pe cartonasul precedent
    int a2, b2; /// a2, b2 = valorile de pe cartonasul curent
    int nrPerechi; /// pentru cerinta 1
    int maxLen, L, cnt;
    /// maxLen = lungimea maxima a unei secvente de cartonase
    /// cnt = numarul secventelor maximale
    fin >> task >> n;

    if (task == 1) {
        nrPerechi = 0;
        fin >> a1 >> b1;
        for (i = 2; i <= n; i++) {
            fin >> a2 >> b2;
            if (a2 == b1)
                nrPerechi++;
            a1 = a2; b1 = b2;
        }
        fout << nrPerechi << "\n";
    }
    else {
        fin >> a1 >> b1;
        maxLen = 1; cnt = 1; L = 1;
        for (i = 2; i <= n; i++) {
            fin >> a2 >> b2;
            if (a2 == b1)
                L++;
            else
                L = 1;
            if (maxLen < L) {
                maxLen = L;
                cnt = 1;
            }
            else if (maxLen == L)
                cnt++;
            a1 = a2;
            b1 = b2;
        }
        if (task == 2)
            fout << maxLen << "\n";
        else
            fout << cnt << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}