#include <iostream>
#include <climits>
#include <deque>
#define ll long long

using namespace std;

const int NMAX = 1e6;
int n, st, dr, x;
long long sp[NMAX + 1], max_sum;
deque <int> dq;

void read() {
    cin >> n >> st >> dr;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        sp[i] = sp[i - 1] + x;
    }
}

void solve() {
    max_sum = LLONG_MIN;
    for (int i = st; i <= n; i++) {
        while (!dq.empty() && sp[i] - sp[i - st] >= sp[i] - sp[dq.back()])
            dq.pop_back();
        dq.push_back(i - st);
        while (!dq.empty() && dq.front() < i - dr)
            dq.pop_front();
        max_sum = max(max_sum, sp[i] - sp[dq.front()]);
    }
    cout << max_sum;
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    read();
    solve();
}