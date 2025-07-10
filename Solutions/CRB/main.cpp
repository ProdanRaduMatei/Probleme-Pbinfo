#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("crb.in");
ofstream fout("crb.out");

int main()
{
    int n, v[1001], o[1001], c = 0;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> v[i];
        o[i] = v[i];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j)
            if (v[i] < v[j])
                swap (v[i], v[j]);
    }
    for (int i = 1; i <= n; ++i)
        if (v[i] == o[i])
            ++c;
    fout << c;
    return 0;
}
