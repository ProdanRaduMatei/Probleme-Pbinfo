#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <map>
#include <cmath>
#include <chrono>

using namespace std;

#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL
#define mod 1000000007
#define lsb (i & -i)

int n, x, m, sp[100005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        sp[i] = sp[i - 1] + x;
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> x;
        int st = 1, dr = n, poz = n + 1;
        while (st <= dr) {
            int mij = (st + dr) / 2;
            if (sp[mij] >= x) {
                poz = mij;
                dr = mij - 1;
            }
            else
                st = mij + 1;
        }
        cout << poz << ' ';
    }
    return 0;
}