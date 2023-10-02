#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("secvpal.in");
ofstream fout("secvpal.out");

int v[1000];

int main(void) {
    int n, left = 0, right = 0, i, j, k, m;
    bool valid = true;
    fin >> n;
    for (i = 0; i < n; i++)
        fin >> v[i];
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (v[i] == v[j]) {
                valid = true;
                for (k = i, m = j; k < m; k++, m--)
                    if (v[k] != v[m]) {
                        valid = false;
                        break;
                    }
                if (valid && j - i > right - left)
                    left = i, right = j;
            }
    fout << left + 1 << " " << right + 1;
    return 0;
}