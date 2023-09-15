#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("interclasare2.in");
ofstream fout("interclasare2.out");

int main()
{
    int n, m, v[100000], w[100000], i, j, cnt = 0;
    fin >> n;
    for (i = 1; i <= n; ++i)
        fin >> v[i];
    fin >> m;
    for (j = 1; j <= m; ++j)
        fin >> w[j];
    i = 1;
    j = 1;
    while (i <= n && j <= m) {
        if (v[i] < w[j])
            ++i;
        else if (v[i] > w[j])
            ++j;
        else if (v[i] == w[j]) {
            fout << v[i] << " ";
            ++i;
            ++j;
            ++cnt;
            if(cnt % 10 == 0)
                fout << endl;
        }
    }
    return 0;
}
