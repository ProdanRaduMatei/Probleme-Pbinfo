#include <iostream>

using namespace std;

int main()
{
    int n, v[100001], c, f = 1;
    cin >> n >> v[1];
    c = v[1];
    for (int i = 2; i <= n; ++i) {
        cin >> v[i];
        if (v[i] == c)
            ++f;
        else {
            --f;
            if (f == 0) {
                c = v[i];
                f = 1;
            }
        }
    }
    f = 0;
    for (int i = 1; i <= n; ++i)
        if (v[i] == c)
            ++f;
    if (f > n / 2)
        cout << "DA" << " " << c;
    else
        cout << "NU";
    return 0;
}
