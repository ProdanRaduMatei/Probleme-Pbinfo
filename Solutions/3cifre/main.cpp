#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

ifstream fin("3cifre.in");
ofstream fout("3cifre.out");

long long int maxim = -1, minim = 999, ap, ap1, ans;
long long int st, dr, st1, dr1, nrf;
unordered_map<long long int, long long int> f;

inline void gen(unsigned int n) {
    long long int n1 = n;
    while (n > 99) {
        int nrf = n % 1000;
        if (nrf >= 100 && nrf <= 999) {
            if (nrf < minim) {
                minim = nrf;
                st = n1;
                dr = n1;
                ap = 1;
            }
            else if (nrf == minim) {
                ap++;
                dr = n1;
            }
            if (nrf > maxim) {
                maxim = nrf;
                st1 = n1;
                dr1 = n1;
                ap1 = 1;
            }
            else if (nrf == maxim) {
                ap1++;
                dr1 = n1;
            }
        }
        n = n / 10;
    }
}

inline void gen1(unsigned int n)
{
    vector<int> a;
    unsigned int n1 = n;
    while (n > 99) {
        int nrf = n % 1000;
        if (nrf >= 100 && nrf <= 999) {
            f[nrf]++;
            if (f[nrf] > ans)
                ans = f[nrf];
        }
        n = n / 10;
    }
}

long long int k;
int n, cer;

int main() {
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    fout.tie(NULL);
    fin >> n >> cer;
    if (cer == 1) {
        while (fin >> k)
            gen(k);
        fout << minim << ' ' << ap << ' ' << st << ' ' << dr << '\n';
        fout << maxim << ' ' << ap1 << ' ' << st1 << ' ' << dr1 << '\n';
    }
    else {
        while (fin >> k)
            gen1(k);
        fout << ans << '\n';
        for (int x = 100 ; x <= 999 ; x++)
            if (f[x] == ans)
                fout << x << ' ';
    }
}