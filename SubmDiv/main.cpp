#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("submdiv.in");
ofstream fout("submdiv.out");

int x, m, v[100000000], s[100000000], nd;

void div(int n) {
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            v[++nd] = i;
            v[++nd] = n / i;
        }
    }
}

int valid(int k) {
    for (int i = 1; i < k; ++i)
        if (s[k] == s[i] || s[k] < s[i])
            return 0;
    return 1;
}

void afis() {
    for (int i = 1; i <= m; ++i)
        fout << s[i] << " ";
    fout << endl;
}

void bt(int k) {
    for (int i = 1; i <= nd; ++i) {
        s[k] = v[i];
        if (valid(k)) {
            if (k == m)
                afis();
            else
                bt(k + 1);
        }
    }
}

int main()
{
    fin >> x >> m;
    div(x);
    if (nd < m) {
        fout << "fara solutie";
        return 0;
    }
    sort(v + 1, v + 1 + nd);
    bt(1);
    return 0;
}
