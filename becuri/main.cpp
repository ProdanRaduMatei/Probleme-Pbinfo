#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("becuri.in");
ofstream fout("becuri.out");

int main()
{
    int k, i, cnt = 0;
    long long v[10000000], n;
    fin >> n;
    for (k = 1; k <= n; ++k)
        v[k] = 0;
    for (k = 1; k <= n; ++k) {
        for (i = 1; i <= n; ++i) {
            if (i % k == 0) {
                if (v[i] == 0) {
                    v[i] = 1;
                    ++cnt;
                }
                else {
                    v[i] = 0;
                    --cnt;
                }
            }
        }
    }
    fout << cnt;
    fin.close();
    fout.close();
    return 0;
}
