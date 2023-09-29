#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <cmath>

using namespace std;

#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL

ifstream cin("dominew.in");
ofstream cout("dominew.out");

int n, m, a[1000005], b[8005];

int main() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++i)
        cin >> a[i];
    cin >> m;
    for (int i = 1 ; i <= m ; ++i) {
        cin >> b[i];
        int st = 1, dr = n;
        int poz = 0;
        while (st <= dr) {
            int mij = (st + dr) / 2;
            if (a[mij] < b[i]) {
                poz = mij;
                st = mij + 1;
            }
            else
                dr = mij - 1;
        }
        for (int j = 1 ; j < i ; ++j)
            if (b[j] < b[i])
                poz++;
        cout << poz + 1 << ' ';
    }    
    return 0;
}