#include <iostream>
#include <algorithm>

using namespace std;

int n, v[200], c;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (__gcd(v[i], v[j]) == 1)
                ++c;
        }
    }
    cout << c;
    return 0;
}
