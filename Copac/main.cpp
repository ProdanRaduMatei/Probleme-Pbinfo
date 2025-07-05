#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    unsigned long long int ar = 2, au = 2, ru = 3;
    unsigned long long int cntar = 2 , cntau = 2 , cntru = 3;
    for(int i = 0 ; i <= n ; ++i) {
        while(cntar) {
            ar++;
            au++;
            ru++;
            cntar--;
            ar--;
        }
        while(cntau) {
            au--;
            ar++;
            ru++;
            cntau--;
        }
        while(cntru) {
            ru--;
            au++;
            ru++;
            cntru--;
        }
        cntar=ar;
        cntau=au;
        cntru=ru;
    }
    cout << ar << ' ' << au << ' ' << ru;
}
