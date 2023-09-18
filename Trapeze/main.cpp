#include <fstream>
#include <vector>

using namespace std;

ifstream fin("trapeze.in");
ofstream fout("trapeze.out");

vector <int> vp, psta, pstb;
int n1, n2, a[100001], b[100001];
int i, j;
long long ariahdr, ariahst, ariamax, nrperechi, rez;

int main() {
    fin >> n1;
    for (i = 0; i < n1; ++i)
        fin >> a[i];
    fin >> n2;
    for (i = 0; i < n2; ++i)
        fin >> b[i];
    i = j = 0;
    while (i < n1 && j < n2)
        if (a[i] == b[j]) {
            vp.push_back(a[i]);
            psta.push_back(i);
            pstb.push_back(j);
            ++i;
            ++j;
        }
        else
            if (a[i] < b[j])
                ++i;
            else
                ++j;
    nrperechi = vp.size();
    long long nrsta, nrstb, nrdra, nrdrb, baza1, baza2;
    for (i = 0; i < (int)vp.size(); ++i) {
            nrsta = psta[i];
            nrstb = pstb[i];
            nrdra = n1 - 1 - psta[i];
            nrdrb = n2 - 1 - pstb[i];
            long long nrtrapst = nrsta * nrstb - i;
            long long nrtrapdr = nrdra * nrdrb - (nrperechi - i - 1);
            rez += nrtrapdr + nrtrapst;
        }
    fout << rez << '\n';
    int xa1, xa2, xb1, xb2;
    xa1 = xb1 = vp[0];
    nrdra = n1 - 1 - psta[0];
    nrdrb = n2 - 1 - pstb[0];
    if (nrdra == 0 || nrdrb == 0)
        ariahst = 0;
    else
        if (a[n1 - 1] != b[n2 - 1]) {
            xa2 = a[n1 - 1];
            xb2 = b[n2 - 1];
            baza1 = xa2 - xa1;
            baza2 = xb2 - xb1;
            ariahst = baza1 + baza2;
        }
        else {
            if (nrdra == 1 && nrdrb == 1)
                ariahst = 0;
            if (nrdra == 1 && nrdrb > 1) {
                xa2 = a[n1 - 1];
                xb2 = b[n2 - 2];
                baza1 = xa2 - xa1;
                baza2 = xb2 - xb1;
                ariahst = baza1 + baza2;
            }
            if (nrdra > 1 && nrdrb == 1) {
                xa2 = a[n1 - 2];
                xb2 = b[n2 - 1];
                baza1 = xa2 - xa1;
                baza2 = xb2 - xb1;
                ariahst = baza1 + baza2;
            }
            if (nrdra > 1 && nrdrb > 1) {
                xa2 = a[n1 - 1];
                xb2 = b[n2 - 2];
                baza1 = xa2 - xa1;
                baza2 = xb2 - xb1;
                ariahst = baza1 + baza2;
                xa2 = a[n1 - 2];
                xb2 = b[n2 - 1];
                baza1 = xa2 - xa1;
                baza2 = xb2 - xb1;
                if (baza1 + baza2 > ariahst)
                    ariahst = baza1 + baza2;
            }
        }
    xa2 = xb2 = vp[nrperechi - 1];
    nrsta = psta.size() - 1;
    nrstb = pstb.size() - 1;
    if (nrsta == 0 || nrstb == 0)
        ariahdr = 0;
    else
        if (a[0] != b[0]) {
            xa1 = a[0];
            xb1 = b[0];
            baza1 = xa2 - xa1;
            baza2 = xb2 - xb1;
            ariahdr = baza1 + baza2;
        }
        else {
            if (nrsta == 1 && nrstb == 1)
                ariahdr = 0;
            if (nrsta == 1 && nrstb > 1) {
                xa1 = a[0];
                xb1 = b[1];
                baza1 = xa2 - xa1;
                baza2 = xb2 - xb1;
                ariahdr = baza1 + baza2;
            }
            if (nrsta > 1 && nrstb == 1) {
                xa1 = a[1];
                xb1 = b[0];
                baza1 = xa2 - xa1;
                baza2 = xb2 - xb1;
                ariahdr = baza1 + baza2;
            }
            if (nrdra > 1 && nrdrb > 1) {
                xa1 = a[0];
                xb1 = b[1];
                baza1 = xa2 - xa1;
                baza2 = xb2 - xb1;
                ariahdr = baza1 + baza2;
                xa1 = a[1];
                xb1 = b[0];
                baza1 = xa2 - xa1;
                baza2 = xb2 - xb1;
                if (baza1 + baza2 > ariahdr)
                    ariahdr = baza1 + baza2;
            }
        }
    ariamax = ariahdr > ariahst ? ariahdr : ariahst;
    fout << ariamax << '\n';
    return 0;
}