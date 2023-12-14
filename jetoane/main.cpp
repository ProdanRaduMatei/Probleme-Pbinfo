#include<fstream>
#define nmax 280001
#define inf "jetoane.in"
#define outf "jetoane.out"
using namespace std;
unsigned a[nmax];
int n,m;
int main() {
    int i, j, l, k1, k2;
    unsigned x;
    ifstream f(inf);
    ofstream g(outf);
    f >> m;
    f >> n;
    for (i = 0; i < nmax; i++)
        a[i] = 0;
    for (i = 1; i <= m; i++) {
        f >> x;
        a[x] = 1;
    }
    for (i = 1; i <= n; i++) {
        f >> x;
        a[x] += 2;
    }
    i = 0;
    while (i < nmax && a[i] != 3)
        i++;
    j = nmax - 1;
    while (j > i && a[j] != 3)
        j--;
    if (i > nmax)
        g << "0 0 -1\n";
    else if (i == j)
        g << i << " 0 -1\n";
    else {
        g << i << ' ' << j << ' ';
        k1 = k2 = 0;
        for (l = 0; l < i; l++)
            if (a[l] == 1) 
                k1++;
            else if (a[l] == 2)
                k2++;
        for (l = j + 1; l <= nmax; l++)
            if (a[l] == 1)
                k1++;
            else if (a[l] == 2)
                k2++;
        if (k1 == k2)
            g << 0 << '\n';
        else if (k1 > k2)
            g << 1 << '\n';
        else
            g << 2 << '\n';
    }
    g.close();
    return 0;
}