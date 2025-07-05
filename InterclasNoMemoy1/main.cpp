#include <fstream>
using namespace std;

int main() {
    ifstream fin1 ("file.in");
    ifstream fin2 ("file.in");
    ofstream fout ("file.out");

    int n, m, x, y, i, j;
    fin1 >> n >> m;
    fin2 >> x >> x;
    for (i = 1; i <= n; ++i)
        fin2 >> x;
    fin1 >> x;
    fin2 >> y;
    i = j = 1;
    while (i <= n && j <= m) {
        if (x <= y) {
            fout << x << ' ';
            fin1 >> x;
            i++;
        }
        else {
            fout << y << ' ';
            fin2 >> y;
            j++;
        }
    }
    while (i <= n) {
        fout << x << ' ';
        fin1 >> x;
        i++;
    }
    while (j <= m) {
        fout << y << ' ';
        fin2 >> y;
        j++;
    }
    return 0;
}