#include <bits/stdc++.h>

using namespace std;

int n, nr, maxi = -1, aparitii;

int main() {
    ifstream f("sirmaxim.in");
    ofstream g("sirmaxim.out");
    f >> n;
    for(int i = 1; i <= n / 2; i++) {
        f >> nr;
        if(nr > maxi)
            maxi = nr;
    }
    for(int i = n / 2 + 1; i <= n; i++) {
        f >> nr;
        if(nr == maxi)
            aparitii++;
    }
    g << aparitii;
    return 0;
}
