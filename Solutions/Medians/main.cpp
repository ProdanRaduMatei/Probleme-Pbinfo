#include <fstream>

#define MOD 666013
#define Nmax 100001
#define Add 100000
#define int long long

using namespace std;

int n, k, V[Nmax], S[Nmax];

ifstream fin("medians.in");
ofstream fout("medians.out");

int aib[Nmax * 2];

void Update(int pos, int val) {
    for (int i = pos; i < Nmax * 2; i += i & -i)
        aib[i] += val;
}

int Query(int pos) {
    int sum = 0;
    for (int i = pos; i > 0; i -= i & -i)
        sum += aib[i];
    return sum;
}

int Fx(int k) {
    for (int i = 0; i < Nmax * 2; ++i)
        aib[i] = 0;
    for (int i = 1; i <= n; ++i)
        if (V[i] > k)
            S[i] = -1;
        else
            S[i] = 1;
    for (int i = 2; i <= n ;++i)
        S[i] += S[i - 1];
    for (int i = 1; i <= n; ++i)
        Update(S[i] + Add, 1);
    int s = 0;
    for (int i = 1; i <= n; ++i){
        s += Query(S[i] + Add - 1);
        if (S[i] < 0)
            ++s;
        Update(S[i] + Add, -1);
    }
    return s;
}

main() {
    fin >> n >> k;
    for (int i = 1; i <= n; ++i)
        fin >> V[i];
    int sk = Fx(k);
    int skk = Fx(k - 1);
    fout << abs(sk - skk);
    return 0;
}