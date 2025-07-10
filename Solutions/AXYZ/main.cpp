#include <fstream>

using namespace std;

ifstream fin("axyz.in");
ofstream fout("axyz.out");

int x[30001];

int main() {
    int N, A, B, C, NB, Z, i, k, j, poz, t, cer;
    fin >> cer >> A >> N;
    for (i = 1; i <= N; i++)
        fin >> x[i];
    if (cer == 1) {
        k = N - 1;
        while (k > 0 && x[k] <= x[k + 1])
            k--;
        poz = N;
        while (poz > k && x[poz] >= x[k])
            poz--;
        swap(x[k], x[poz]);
        for (i = 1; i <= k; i++)
            fout << x[i];
        for (i = N; i > k; i--)
            fout << x[i];
        fout << '\n';
    }
    else 
        if (A < 100) {
            B = A % 10;
            A = A / 10;
            Z = 0;
            NB = 0;
            for (i = N; i >= 1; i--)
                if (x[i] == B)
                    NB++;
                else if (x[i] == A)
                    Z += NB;
            fout << Z << '\n';
        }
        else {
            int i, C, NC = 0, NBC = 0, Z = 0;
            C = A % 10;
            A /= 10;
            B = A % 10;
            A /= 10;
            for (i = N; i >= 1; i--)
                if (x[i] == C)
                    NC++;
                else if (x[i] == B)
                    NBC += NC;
                    else if (x[i] == A)
                        Z += NBC;
            fout << Z << '\n';
        }
    return 0;
}