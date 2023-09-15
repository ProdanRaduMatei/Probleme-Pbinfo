#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n, x, v[1001], cn = 0;
    string p;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p;
        if (p == "push") {
            ++cn;
            cin >> v[cn];
        }
        else if (p == "top" && cn > 0)
            cout << v[cn] << endl;
        else if (p == "pop" && cn > 0)
            --cn;
    }
    return 0;
}
