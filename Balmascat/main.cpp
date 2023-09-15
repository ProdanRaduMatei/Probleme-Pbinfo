#include <bits/stdc++.h>
using namespace std;
ifstream fin("balmascat.in");
ofstream fout("balmascat.out");
int main() {
    long long int n, p, cnt = 0, c,  rez = 0;
    fin >> n >> p;
    cnt= n / p;
    if(n % p != 0)
        cnt++;
    if(cnt % 10 == 9)
        c = 8;
    else
        c = cnt%10+1;
    for(int i = 1 ; i <= p ; ++i) {
        rez = rez *100+c*10+cnt%10;
    }
    fout << rez/10;
    return 0;
}
