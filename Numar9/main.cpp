#include <iostream>
#include <fstream>
using namespace std;
long long unsigned s, x, r, con;
long long nrnoua, nrnouamic;
ifstream fin ("numar9.in");
ofstream fout ("numar9.out");
int unsigned k, i, v[2200001];
int main() {
    fin >> s >> k;
    r = s % 9;
    nrnoua = s / 9;
    nrnouamic = nrnoua / 6;
    for (int i = 1; i <= nrnouamic; ++i)
        v[i] = 999999;
    for (int i = nrnouamic + 1; i <= nrnouamic + nrnoua % 6; ++i)
        v[i] = 9;
    if (r != 0 && s!= 0)
        v[0] = r;
    x = 0;
    if (v[0] != 0)
        for (int i = 0; i <= nrnouamic + nrnoua % 6; ++i) {
            fout << v[i];
            if (v[i] < 10)
                x = (x * 10 + v[i]) % k;
            else {
                while (v[i] != 0) {
                    x = (x * 10 + v[i] % 10) % k;
                    v[i] = v[i] / 10;
                }
            }
        }
    else
        for (int i = 1; i <= nrnouamic + nrnoua % 6; ++i) {
            fout << v[i];
            if (v[i] < 10)
                x = (x * 10 + v[i]) % k;
            else {
                while (v[i] != 0) {
                    x = (x * 10 + v[i] % 10) % k;
                    v[i] = v[i] / 10;
                }
            }
        }
    fout << ' ' << x;
//cout<<con*6+nrnouamic%6;
    return 0;
}
