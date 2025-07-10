#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int n, v[100001], cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (v[j] % v[i] == 0 || v[i] % v[j] == 0)
                cnt++;
    cout << cnt << endl;
    return 0;
}