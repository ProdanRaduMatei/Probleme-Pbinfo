#include <fstream>
#include <deque>

using namespace std;

ifstream cin("ksum.in");
ofstream cout("ksum.out");

const int NMAX = 1e5;
int sp[NMAX + 1], n, k, x, maxi = -int(1e9);
deque <int> dq;

void read() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        sp[i] = sp[i - 1] + x;
    }
}

void solve() {
    for (int i = k; i <= n; i++) {
        while (!dq.empty() && sp[i] - sp[i - k] >= sp[i] - sp[dq.front()])
            dq.pop_back();
        dq.push_back(i - k);
        if (!dq.empty() && dq.front() <= i - k)
            maxi = max(maxi, sp[i] - sp[dq.front()]);    
    }
    cout << maxi;
}

int main() {
    read();
    solve();
}