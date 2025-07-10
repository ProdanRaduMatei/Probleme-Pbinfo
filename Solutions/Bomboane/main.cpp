#include <fstream>

using namespace std;

ifstream fin("bomboane.in");
ofstream fout("bomboane.out");

int n, M, S, D, B, a[1001], b[1001], k, j;
double J, s;

int maxim(int * a, int n) {
    int maxa = a[1];
    for (int i = 1; i <= n; ++i)
        if (a[i] > maxa)
            maxa = a[i];
    return maxa;
}

int minim(int * a, int n) {
    int mina = a[1];
    for (int i = 1; i <= n; ++i)
        if (a[i] < mina)
            mina = a[i];
    return mina;
}

int f(int * a, int n, int N) {
    int k = 0;
    for (int i = 1; i <= n; ++i)
        if (a[i] != N)
            k++;
    return k;
}

int imax(int *a, int n) {
    for (int i = 1; i <= n; ++i)
        if (a[i] == maxim(a, n))
            return i;
}

int imin(int *a, int n) {
    for (int i = 1; i <= n; ++i)
        if(a[i] == minim(a, n))
            return i;
}

int main()
{
    fin >> n;
    for(int i = 1; i <= n; ++i) {
        fin >> a[i];
        b[i] = a[i];
        s += a[i];
    }
    J = s / n;
    j = s / n;
    if (j != J)
        fout << "-1";
    else {
        while(f(a, n, J) != 0) {
            ++M;
            k = J - minim(a, n);
            a[imin(a, n)] += k;
            a[imax(a, n)] -= k;
        }
        fout << M << endl;
        while (f(b, n, J) != 0) {
            S = imax(b, n);
            D = imin(b, n);
            ++M;
            k = J - minim(b, n);
            fout << S << " " << D << " " << k << endl;
            b[D] += k;
            b[S] -= k;
        }
    }
    return 0;
}
