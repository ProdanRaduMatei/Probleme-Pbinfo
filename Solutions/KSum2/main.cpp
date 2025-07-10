#include <fstream>
#include <deque>

using namespace std;

ifstream cin("ksum2.in");
ofstream cout("ksum2.out");

const int NMAX = 1e5;
int sp[NMAX + 1], x , n, maxi = -int(1e9), st, dr;
deque <int> dq;

void read() {
    cin >> n >> st >> dr;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        sp[i] = sp[i - 1] + x;
    }
}

void solve() {
    for (int i = st; i <= n; i++) {
        while (!dq.empty() && sp[i] - sp[i - st] >= sp[i] - sp[dq.back()])
            dq.pop_back();
        dq.push_back(i - st);
        if (!dq.empty() && dq.front() < i - dr)
            dq.pop_front();
        maxi = max(maxi, sp[i] - sp[dq.front()]);
    }
    cout << maxi;
}   

int main(){    
    read();
    solve();
}