#include <bits/stdc++.h>
using namespace std;
ifstream fin("unupatru.in");
ofstream fout("unupatru.out");
int pat(long long n) {
    long long cnt = 0, n1 = n;
    while(1) {
        if(n == 1 || n == 4)
            break;
        cnt++;
        long long n1 = n;
        n = 0;
        while(n1 != 0) {
            n += (n1 % 10) * (n1 % 10);
            n1 /= 10;
        }
    }

    return cnt;
}
main() {
    long long n, x;
    fin >> n;
    for(int i = 1 ; i <= n ; ++i) {
        fin >> x;
        fout << pat(x) << " ";
    }

    fin.close();
    fout.close();

    return 0;
}
