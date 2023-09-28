#include <bits/stdc++.h>

using namespace std;

int i, v[10001], n, aux, mini = INT_MAX;

int main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> v[i];
        if (mini > v[i])
            mini = v[i];
    }
    for (i = 1; i <= n; i++) {
        if (v[i] == mini)
            mini = mini;
        else
            cout << v[i] << " ";
    }
    return 0;
}