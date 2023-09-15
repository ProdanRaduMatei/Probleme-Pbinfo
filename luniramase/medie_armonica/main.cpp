#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n, a, p = 1, s = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        p = p * a;
        s = s + a;
    }
    float ma;
    ma = float(p * n) / s;
    cout << fixed << setprecision(2) << ma;
    return 0;
}
