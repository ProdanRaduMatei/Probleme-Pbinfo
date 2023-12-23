#include <fstream>
#include <bits/stdc++.h>

using namespace std;

struct nr {
    int val, sumcif;
}v[100005];

bool  cmp (nr a, nr b) {
    return a.val < b.val;
}

int f[60];

int main() {
    ifstream cin("pseudocmp.in");
    ofstream cout("pseudocmp.out");
    long long cer, n, ca, sum, cnt;
    cin >> cer >> n;
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].val;
        ca = v[i].val;
        sum = 0;
        while (ca) {
            sum += (ca % 10);
            ca /= 10;
        }
        v[i].sumcif = sum;
    }
    sort(v + 1, v + n + 1, cmp);
    if (cer == 1) {
        for (int i = 2; i <= n; i++) {
            if (v[i].sumcif < v[i - 1].sumcif) {
                cout << v[i - 1].val << " " << v[i].val;
                return 0;
            }
        }
        cout << -1;
    } else {
        for (int i = 1; i <= n; i++) {
            sum = 0;
            for (int j = v[i].sumcif + 1; j <= 54; j++)
                sum += f[j];
            cnt += sum;
            f[v[i].sumcif]++;
        }
        cout << cnt;
    }
    return 0;
}