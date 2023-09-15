#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("siruri.in");
ofstream fout("siruri.out");

int n, m, s[16];

void afis() {
    for (int i = 1; i <= m; ++i)
        fout << s[i] << " ";
    fout << endl;
}

int valid(int k) {
    for (int i = 1; i < k; ++i)
        if (s[k] == s[i] || s[k] < s[i])
            return 0;
    if (k > 1 && s[k] - s[k - 1] > 2)
        return 0;
    return 1;
}

void bt(int k) {
    for (int i = 1; i <= n; ++i) {
        s[k] = i;
        if (valid(k))
            if (k == m)
                afis();
            else
                bt(k + 1);
    }
}

int main()
{
    fin >> n >> m;
    bt(1);
    return 0;
}
