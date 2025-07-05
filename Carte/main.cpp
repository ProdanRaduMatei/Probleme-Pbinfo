#include <fstream>

using namespace std;

ifstream fin("carte.in");
ofstream fout("carte.out");

int main() {
    int n, v[10000], i, nr, x, k, max = 0, zimax;
    fin >> n;
    for (i = 0; i < n; i++) {
        fin >> v[i];
        if (v[i] == 1)
            x = i; 
    }
    x = 0;
    nr = 0;
    while (x < n) {
        i = 0;
        k = 0;
        nr++;
        while (i < n) {
            if (v[i] == x + 1) {
                k++;
                x++;
            }
            i++;
        }
        if (k > max) {
            max = k;
            zimax = nr;
        }
    }
    fout << nr << ' ' << zimax << ' ' << max << endl;
    fin.close();
    fout.close();
    return 0;
}