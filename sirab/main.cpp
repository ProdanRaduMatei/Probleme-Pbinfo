#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sirab.in");
ofstream fout("sirab.out");

int n, s, ok, sol[500];

void afis() {
    for (int i = 1; i <= n; ++i)
        fout << sol[i] << " ";
    fout << endl;
    ok = 1;
}

int valid(int k) {
    for (int i = 1; i < k; ++i)
        if (sol[k] <= sol[i] || ((sol[k] + sol[i]) % (sol[k] - sol[i]) != 0))
            return 0;
    return 1;
}

void bt(int k) {
    for (int i = 1; i <= s; ++i) {
        sol[k] = i;
        if (valid(k))
            if (k == n)
                afis();
            else
                bt(k + 1);
    }
}

int main()
{
    fin >> s >> n;
    bt(1);
    if (ok == 0)
        fout << 0;
    return 0;
}
