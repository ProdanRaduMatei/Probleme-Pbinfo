#include <bits/stdc++.h>
using namespace std;
ifstream fin("benzinarii.in");
ofstream fout("benzinarii.out");
int pal(int n) {
    long long ogl = 0, n1 = n;
    while(n1 != 0) {
        ogl = ogl * 10 + n1 % 10;
        n1 /= 10;
    }
    if(ogl == n)
        return 1;
    else
        return 0;
}

int main() {
    long long n, mini = 1000000000, d1 = 0, p = 1;
    fin >> n;
    long long n1 = n, n2 = n;
    while(p != 0) {
        d1++;
        if(pal(n1+1))
            p = 0;
        else
            n1++;
    }
    if(d1 < mini)
        mini = d1;
    int d2 = 0 ;
    p = 1;
    while(p != 0) {
        d2++;
        if(pal(n-1))
            p = 0;
        else
            n--;
    }
    if(d2 < mini)
        mini = d2;
    fout << mini << ' ' << mini + 1LL*n2;

    fin.close();
    fout.close();

    return 0;
}
