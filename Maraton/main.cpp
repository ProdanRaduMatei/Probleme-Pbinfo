#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int x, y, t;
}maratonist;

maratonist v[100001];

int main(){
    int n, f[100001], s[100001];
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i].x >> v[i].y;
        v[i].t = v[i].x / v[i].y;
    }
    return 0;
}
