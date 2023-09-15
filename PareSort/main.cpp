#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
ifstream fin("paresort.in");
ofstream fout("paresort.out");
int n, v[1001], p[1001], j = 1, a, cnt;
int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++ i)
        p[i] = -1;
    for (int i = 1; i <= n; ++i) {
        fin >> v[i];
        if (v[i] % 2 == 0) {
            ++cnt;
            p[j] = v[i];
            ++j;
        }
    }
    if (p[1] == -1)
        fout << "nu exista";
    else {
        fout << cnt << endl;
        a = j;
        j = 1;
        sort(p + 1, p + a);
        for (j = 1; j < a; ++j)
        	fout << p[j] << " ";
    }
    return 0;
}
