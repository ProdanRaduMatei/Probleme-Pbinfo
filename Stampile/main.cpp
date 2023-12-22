#include <iostream>
#include <climits>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
vector<int> v;
unordered_map<int, int> f;
vector<int> sol;
int ans1 = INT_MAX, n, k, rez1;

inline bool cmp(int a, int b) {
    if (f[a] != f[b])
        return (f[a] > f[b]);
    else
        return (a > b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int x = 0 ; x < n ; x++) {
        cin >> k;
        a.push_back(k);
        while (k) {
            f[k % 10]++;
            k = k / 10;
        }
    }
    for (int x = 0 ; x <= 9 ; x++) {
        if (f[x] < ans1) {
            ans1 = f[x];
            rez1 = x;
        }
        v.push_back(x);
    }
    cout << rez1 << '\n';
    sort(v.begin(), v.end(), cmp);
    for (auto x : v)
        cout << x << ' ';
    cout << '\n';
    for (auto x : a) {
        int k = x;
        f.clear();
        int ctm = 0;
        while (k) {
            if(f[k % 10] == 0) {
                f[k % 10] = 1;
                ctm++;
            }
            k = k / 10;
        }
        if (ctm == 2)
            sol.push_back(x);
    }
    if (sol.size() == 0) {
        cout << -1;
        return 0;
    }
    sort(sol.begin(), sol.end());
    for (auto x : sol)
        cout << x << ' ';
}