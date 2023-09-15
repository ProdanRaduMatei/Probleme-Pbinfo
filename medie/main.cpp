#include <iostream>

using namespace std;

int n, s, a, cnt;
double m;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        if (a % 2 == 0) {
            s = s + a;
            ++cnt;
        }
    }
    m = (double) s / cnt;
    cout << m;
    return 0;
}
