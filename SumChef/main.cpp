#include <iostream>

using namespace std;

int main()
{
    int n, a, u, i, s = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        while (a != 0) {
            u = a % 10;
            s = s + u * u * u;
            a = a / 10;
        }
    }
    cout << s;
    return 0;
}
