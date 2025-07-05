#include <bits/stdc++.h>
using namespace std;
ifstream fin("numere3.in");
ofstream fout("numere3.out");
int sum(int n) {
    int s = 0;
    while(n != 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}
int main() {
    int a , b , c , p;
    fin >> p >>a >> b >> c;
    if(p == 1)
        fout << sum(a) + sum(b) + sum(c);
    else {
        fout << a <<" " << c << endl;
        while(a < b && c > b) {
            a = a + sum(a);
            c = c - sum(c);
            fout << a <<" "<< c << endl;
        }
        if(a >= b && c <=b)
            fout << 0;
        else if(a >= b && c > b)
            fout << 1;
        else fout << 2;
    }
    fin.close();
    fout.close();
    return 0;
}
