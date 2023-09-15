#include <fstream>

using namespace std;

ifstream fin("patrate3.in");
ofstream fout("patrate3.out");

int C, M, N, T;

int main()
{
    fin >> C;
    if (C == 1) {
        fin >> M;
        fout << M * 8;
    }
    else {
        fin >> N;
        bool ok = false;
        for (T = 1; ok == 0; ++T)
            if (4 * T * (T + 1) >= N)
                ok = 1;
        fout << T - 1;
    }
    return 0;
}
