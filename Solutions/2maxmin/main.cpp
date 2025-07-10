#include <iostream>

using namespace std;

int main()
{
    int n, m1 = 0, m2 = 0, i, a;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> a;
        if (a > m2) {
            if (a > m1) {
                m2 = m1;
                m1 = a;
            }
            else
                m2 = a;
        }
    }
    cout << m1 << " " << m2;
    return 0;
}
