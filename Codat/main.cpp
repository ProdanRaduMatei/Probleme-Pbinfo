#include <fstream>
#include <stack>

using namespace std;

ifstream cin("codat.in");
ofstream cout("codat.out");

const int k = 1e6;
int n, x, maxi;
int v[k + 1], st[k + 1], dr[k + 1];
stack <int> stiva;

void read() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        v[i] = x;
        if (maxi < x)
            maxi = x;
    }
}

void solve() {
    stiva.push(1);
    for (int i = 2; i <= n; i++) {
        while (!stiva.empty() && v[i] >= v[stiva.top()])
            stiva.pop();
        if (stiva.empty())
            st[i] = 1;
        else
            st[i] = stiva.top();
        if (st[i] == i)
            st[i]--;
        stiva.push(i);
    }
    while (!stiva.empty())
        stiva.pop();
    stiva.push(n);
    for (int i = n - 1; i >= 1; i--) {
        while (!stiva.empty() && v[i] >= v[stiva.top()])
            stiva.pop();
        if (stiva.empty())
            dr[i] = n;
        else dr[i] = stiva.top();
        if (dr[i] == i)
            dr[i]++;
        stiva.push(i);
    }
    for (int i = 1; i <= n; i++) {
        if (v[i] == maxi)
            cout << -1 << " ";
        else if (i == 1)
            cout << dr[i] << " ";
        else if (i == n)
            cout << st[i] << " ";
        else if(i > 1 && i < n){
            if (v[st[i]] == v[dr[i]]) {
                if (i - st[i] > dr[i] - i)
                    cout << dr[i] << " ";
                else if (i - st[i] < dr[i] - i)
                    cout << st[i] << " ";
                else cout << dr[i] << " ";
            }
            else {
                if (v[st[i]] > v[i] && v[dr[i]] > v[i]) {
                    if (i - st[i] > dr[i] - i)
                        cout << dr[i] << " ";
                    else if (i - st[i] < dr[i] - i)
                        cout << st[i] << " ";
                    else cout << dr[i] << " ";
                }
                else if (v[st[i]] > v[i] && v[dr[i]] <= v[i])
                    cout << st[i] << " ";
                else if (v[st[i]] <= v[i] && v[dr[i]] > v[i])
                    cout << dr[i] << " ";
            }
        }
    }
}

int main() {
    read();
    solve();
}