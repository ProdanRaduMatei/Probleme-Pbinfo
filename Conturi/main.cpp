#include <bits/stdc++.h>
using namespace std;
ifstream fin("conturi.in");
ofstream fout("conturi.out");
int main() {
    int n,x, a, maxi = 0;
    fin >> n >> x;
    for(int i = 0 ; i < n ; ++i) {
        fin >> a;
        int suma = a % 10000;
        if((a / 100000) % 10 == x) {
            if((a / 10000) % 10 == 1) {
                if(suma > maxi)
                    maxi = suma;
            }
        }
    }
    fout << maxi;

    fin.close();
    fout.close();

    return 0;
}
