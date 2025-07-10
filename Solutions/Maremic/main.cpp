#include <bits/stdc++.h>
using namespace std;

int v[100005];
int main() {
    long long int n, x = 89;
    cin >> n;
    v[1] = 8;
    v[2] = 9;
    int k = 2;
    for (int i = 3; i <= n; i++) {
//regula se observa la fiecare pas generat
        if (i % 2 != 0) {
            k++;
            v[k] = 9;
        }
        else {
            k++;
            v[i / 2] = 8;
            v[i / 2 - 1] = 9;
            v[k] = 9;
        }
    }
    for (int i = 1; i <= k; i++)
        cout << v[i];
    return 0;
}