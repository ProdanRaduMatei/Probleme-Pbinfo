#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("bibinar.in");
ofstream fout("bibinar.out");

int main()
{
    int n, s, cnt, c1, c2, x;
    long long a, m[100000000], c, p;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> a;
        m[100000000] = {0};
        cnt = 1;
        while (a) {
            m[cnt] = a % 2;
            a = a / 2;
            ++cnt;
        }
        p = 1;
        s = 0;
        for (int i = cnt; i > 1; --i) {
            c2 = m[i];
            for (int j = i - 1; j >= 1; --j) {
                c1 = m[j];
                s = s + c2 * 1 + c1 * 2;
            }
        }
        cout << s << " "    ;
    }
    return 0;
}
