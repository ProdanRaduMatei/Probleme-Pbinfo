#include <iostream>

using namespace std;

int main() {
    int n, r, cnt = 0, a[100001], b[100001];
    cin >> n >> r;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        for (int j = 1; j <= n; j++)
            if (a[j] % b[i] == r)
                cnt++;
    }
    cout << cnt;
    return 0;
}