#include <fstream>

using namespace std;

int main() {
    int c,n;
    ifstream fin("oneout.in");
    fin >> c >> n;
    int a[n + 1];
    int Max = 0;
    for (int i = 1; i <= n; ++i) {
        fin >> a[i];
        Max = max(a[i], Max);
    }
    int nlp[Max + 1];
    for (int i = 1; i <= Max; ++i)
        nlp[i] = 0;
    for (int i = 2; i * i <= Max; ++i)
        for (int j = i * i; j <= Max; j += i * i)
            nlp[j] = 1;
    ofstream fout("oneout.out");
    if (c == 1) {
        int sol = 0;
        for (int i = 1; i <= n; ++i)
            if (!nlp[a[i]])
                ++sol;
                fout << sol << '\n';
    }
    else {
        int Secv, Smax = 0, N = 1, I, Imax[10000], J, Jmax[10000];
        for (int i = 2; i < n; ++i)
            if (!nlp[a[i - 1]] && nlp[a[i]] && !nlp[a[i + 1]]) {
                Secv = 0;
                I = i - 1;
                while (!nlp[a[I]]) {
                    ++Secv;
                    if (I > 1)
                        --I;
                    else
                        break;
                }
                if (nlp[a[I]])
                    ++I;
                J = i + 1;
                while (!nlp[a[J]]) {
                    ++Secv;
                    if (J < n)
                        ++J;
                    else
                        break;
                }
                if (nlp[a[J]])
                    --J;
                if (Secv >= Smax) {
                    if (Secv == Smax)
                        ++N;
                    else {
                        N = 1;
                        Smax = 0;
                    }
                    Smax = Secv;
                    Imax[N] = I;
                    Jmax[N] = J;
                }
            }
        fout << Smax << ' ' << N << '\n';
        for (int i = 1; i <= N; ++i)
            fout << Imax[i] << ' ' << Jmax[i] << '\n';
    }
    return 0;
}