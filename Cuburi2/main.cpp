#include <iostream>

using namespace std;

int main()
{
    int n, v[1001], m[1001], cn = 0, x;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (i == 1) {
            ++cn;
            v[cn] = x;
            m[cn] = i;
        }
        else {
            while (x > v[cn] && cn > 0)
                --cn;
            ++cn;
            v[cn] = x;
            m[cn] = i;
        }
    }
    cout << cn << endl;
    for (int i = 1; i <= cn; ++i)
        cout << m[i] << " ";
    return 0;
}
