#include <iostream>

using namespace std;

int main()
{
    int n, v[1001], cn = 0, x;
    string c;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> c;
        if (c == "push") {
            cin >> x;
            ++cn;
            v[cn] = x;
        }
        else if (c == "front" && cn > 0)
            cout << v[1];
        else if (c == "pop" && cn > 0) {
            for (int j = 1; j < cn; ++j)
                v[j] = v[j + 1];
            --cn;
        }
    }
    return 0;
}
