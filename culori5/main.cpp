#include<bits/stdc++.h>

using namespace std;

ifstream in("culori.in");
ofstream out("culori.out");

int fr[1005];
short v[1000005];

int main() {
    int n, k, maxi = 0;
    in >> n >> k;
    for (int i = 1; i <= n; i++) {
        in >> v[i];
        if (i <= k) {
            fr[v[i]]++;
            maxi = max(maxi, fr[v[i]]);
        }
        else {
            fr[v[i]]++;
            fr[v[i - k]]--;
            maxi = max(maxi, fr[v[i]]);
        }
    }
    out << maxi;
    return 0;
}