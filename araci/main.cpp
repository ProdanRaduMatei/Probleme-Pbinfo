#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define Inf 0x3f3f3f3f
#define mod 123457

int n, k, a[100005];

int main() {
    cin >> n >> k;
    for(int i = 1 ; i <= n ; ++i)
        cin >> a[i];
    int st = 1,dr = n;
    int rez;
    while(st <= dr) {
        int mij = (st + dr) / 2;
        int araci = 0;
        for (int i = 1 ; i <= n ; ++i)
            araci += (a[i] / mij);
        if (araci >= k) {
            rez = mij;
            st = mij + 1;
        }
        else
            dr = mij - 1;
    }
    cout << rez;
    return 0;
}