#include <bits/stdc++.h>//DaryuF

using namespace std;
int n, k;
map <long long, long long> m;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        m[x]++;
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        long long x;
        cin >> x;
        cout << x * m[x] << " ";
    }
    return 0;
}