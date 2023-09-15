#include <bits/stdc++.h>
using namespace std;
ifstream fin("centrale.in");
ofstream fout("centrale.out");
int pat(int n) {
    int n1 = n / 10, pc = n1 % 10, ok = 0;
    while(n1 > 9) {
        if(n1 % 10 != pc)
            ok = 1;
        n1 /= 10;
    }
    if(ok == 0)
        return 1;
    else
        return 0;
}
int main() {
    long long n, x, cnt = 0;
    fin >> n;
    for(int i = 1 ; i <= n ; ++i) {
        fin >> x;
        if(pat(x))
            cnt++;
    }
    fout << cnt;

    fin.close();
    fout.close();

    return 0;
}
