#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("summit.in");
ofstream fout("summit.out");

long long n, S[100000001];

int caut(int s, long long d, int x) {
    if (s > d)
        return 0;
    else {
        int mj = (s + d) / 2;
        if (x == S[mj])
            return mj;
        if (x < S[mj])
            return caut(s, mj - 1, x);
        if (x > S[mj])
            return caut(mj + 1, d, x);
    }
}

int main()
{
    long long v[100000001];
    S[0] = 0;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> v[i];
        S[i] = S[i - 1] + v[i];
    }
    for (int i = 1; i <= n; ++i) {
        fout << caut(1, n, v[i]);
    }
    return 0;
}
