#include <iostream>

using namespace std;

int sums[100001];

int main() {
    int n, x, i, total = 0, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        sums[i] = sums[i - 1] + x;
    }
    total = sums[n];
    for (i = total; i <= n; i++)
        s = max(s, sums[i] - sums[i - total]);
    cout << total - s << endl;
    return 0;
}