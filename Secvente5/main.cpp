#include <fstream>

using namespace std;

ifstream fin("secvente5.in");
ofstream fout("secvente5.out");

long long C, N, x, v[100001], prim[100001],ult[100001], s[100001], rest[100001], nrv, nrs, i, sc, r, smax, lgmax, lg, srest[100001], sumaseccurenta;

int main() {
    fin >> C >> N;
    for (i = 1; i <= N; i++) {
        fin >> x;
        if (x % N == 0) {
            nrv++;
            smax = max(smax, x);
        }
        s[i] = s[i - 1] + x;
        r = s[i] % N;
        if (r == 0) {
            smax = max(smax, s[i]);
            lgmax = max(lgmax, i);
        }
        if (r < 0)
            r = N + r;
        rest[r]++;
        if (prim[r] == 0)
            ult[r] = prim[r] = i;
        ult[r] = i;
        lg = i - prim[r];
        if (lg > 1 && lg > lgmax)
            lgmax = lg;
        if (rest[r] == 1)
             srest[r] = s[i];
        else {
            if (s[i] < srest[r])
               srest[r] = s[i];
           smax = max(smax, s[i] - srest[r]);
        }
    }
    nrs = rest[0];
    for (i = 0; i < N; i++)
        nrs = nrs + rest[i] * (rest[i] - 1) / 2;
    nrs = nrs - nrv;
    if (C == 1)
        fout << nrs << endl;
    else
        if (C == 2)
            fout << lgmax;
    else
        fout << smax;
    return 0;
}