#include <iostream>

using namespace std;

int main() {
    long long n, a, b, s = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
        s = s + max(a, b);
    }
    cout << s;
    return 0;
}
