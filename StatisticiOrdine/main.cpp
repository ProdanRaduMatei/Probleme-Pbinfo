#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("statisticiordine.in");
ofstream fout("statisticiordine.out");

int n, k, v[4000001], tmp[4000001];

void MergeSort(int st, int dr) {
    if (st < dr) {
        int m = (st + dr) / 2;
        MergeSort(st, m);
        MergeSort(m + 1, dr);
        int i = st, j = m + 1, k = 0;
        while (i <= m && j <= dr)
            if (v[i] < v[j])
                tmp[++k] = v[i++];
            else
                tmp[++k] = v[j++];
        while (i <= m)
            tmp[++k] = v[i++];
        while (j <= dr)
            tmp[++k] = v[j++];
        for (i = st, j = 1; i <= dr; ++i, j++)
            v[i] = tmp[j];
    }
}

int main()
{
    fin >> n, k;
    for (int i = 0; i < n; ++i)
        fin >> v[i];
    MergeSort(0, n - 1);
    fout << v[k - 1];
    return 0;
}
