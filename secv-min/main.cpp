#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <cmath>
#include <map>

using namespace std;
#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL

ifstream cin("secvmin.in");
ofstream cout("secvmin.out");

int n, x, k, a[1000005], kth[6], last[6];
long long rez;

int main() {
    cin >> n >> k;
    for (int i = 1 ; i <= n ; ++i)
        cin >> a[i];
    int mini = Inf, minianterior = -Inf;
    for (int i = 1 ; i <= k ; ++i) {
        mini = Inf;
        for (int j = 1 ; j <= n ; ++j)
            if (a[j] < mini && a[j] > minianterior)
                mini = a[j];
        minianterior = mini;
        kth[i] = mini;
    }
    for (int i = 1 ; i <= n ; ++i) {
        int cnt = n + 1;
        for (int j = 1 ; j <= k ; ++j) {
            if (a[i] == kth[j])
                last[j] = i;
            cnt = min(cnt,last[j]);
        }
        rez += cnt;
    }
    cout << rez;
    return 0;
}