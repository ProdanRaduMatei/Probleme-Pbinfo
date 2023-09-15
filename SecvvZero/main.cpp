#include <iostream>

using namespace std;

int main()
{
    int n, v[1000], c = 0, s = 0, m = 0, p;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        if (v[i] == 0) {
            ++c;
            if (s == 0)
                s = i;
        }
        else
            if (c > m) {
                m = c;
                p = s;
                s = 0;
                c = 0;
            }
    }
    cout << p << " " << p + m - 1;
    return 0;
}
