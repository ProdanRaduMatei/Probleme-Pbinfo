#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <tuple>

using namespace std;
#define Inf 0x3f3f3f3f
#define mod 1e9+7

int n;
struct range {
    int l, r, index;
    bool operator < (const range &other) const {
        if (l == other.l)
            return r > other.r;
        return l < other.l;
    }
};

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<range> ranges(n);
    vector<bool> contained(n);
    vector<bool>contains(n);
    for (int i = 0 ; i < n ; ++i) {
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].index = i;
    }
    sort(ranges.begin(), ranges.end());
    int right = 0;
    for (int i = 0 ; i < n ; ++i) {
        if (ranges[i].r <= right)
            contained[ranges[i].index] = true;
        right = max(right,ranges[i].r);
    }
    int left = Inf;
    for (int i = n - 1 ; i >= 0 ; --i) {
        if (ranges[i].r >= left)
            contains[ranges[i].index] = true;
        left = min(left, ranges[i].r);
    }
    for (int i = 0 ; i < n ; ++i)
        cout << contains[i] << ' ';
    cout << '\n';
    for (int i = 0 ; i < n ; ++i)
        cout << contained[i] << ' ';
    return 0;
}