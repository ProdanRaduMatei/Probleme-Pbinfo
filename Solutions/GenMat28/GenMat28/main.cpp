#include <bits/stdc++.h>

using namespace std;

int n, di[]={0, 0, -2, 2, 1, -1}, dj[]={-2, 2, 0, 0, 1, -1}, a[101][101];

bool inmat(int i, int j) {
    return i <= n && j <= n && i >= 1 && j >= 1;
}

queue<pair<int, pair<int, int>>> Q;

void lee() {
    while (!Q.empty()) {
        int cost = Q.front().first;
        int i = Q.front().second.first;
        int j = Q.front().second.second;
        for (int d = 0; d <= 5; ++d) {
            int inou = i + di[d];
            int jnou = j + dj[d];
            if (inmat(inou, jnou) && a[inou][jnou] == 0) {
                a[inou][jnou] = cost + 1;
                Q.push({cost + 1, {inou, jnou}});
            }
        }
        Q.pop();
    }
}

void lee1() {
    while (!Q.empty()) {
        int cost = Q.front().first;
        int i = Q.front().second.first;
        int j = Q.front().second.second;
        for (int d = 0; d <= 5; ++d) {
            int inou = i + di[d];
            int jnou = j + dj[d];
            if (inmat(inou, jnou) && a[inou][jnou] == 0) {
                a[inou][jnou] = cost - 1;
                Q.push({cost - 1, {inou, jnou}});
            }
        }
        Q.pop();
    }
}
int main(){
    cin >> n;
    Q.push({1, {1, 1}});
    Q.push({1, {n,n}});
    a[1][1] = 1, a[n][n] = 1;
    a[2][1] = n, a[n][n - 1] = n;
    a[1][2] = n, a[n - 1][n] = n;
    lee();
    Q.push({n, {2, 1}});
    Q.push({n, {1, 2}});
    Q.push({n, {n, n - 1}});
    Q.push({n, {n - 1, n}});
    lee1();
    for (int i = 1; i <= n; ++i, cout << '\n')
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << ' ';
    return 0;
}
