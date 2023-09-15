#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nrapp.in");
ofstream fout("nrapp.out");

int main()
{
    int n, v[100001], q, e;
    char c;
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    fin >> q;
    for (int i = 1; i <= q; ++i) {
        fin >> c >> e;
        if (c == 'S') {
            int x = 0;
            for (int j = 1; j < e; ++j)
                if (v[j] < v[e])
                    x = j;
            fout << x << endl;
        }
        else {
            int x = n + 1;
            for (int j = n; j > e; --j)
                if (v[j] < v[e])
                    x = j;
            fout << x << endl;
        }
    }
    return 0;
}
