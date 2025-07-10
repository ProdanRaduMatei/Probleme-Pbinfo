#include <iostream>

using namespace std;

int main()
{
    int n, v[10], i, a, b, c;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> v[i];
        a = 0;
        b = 0;
        c = 1;
        for (c = 1; c <= v[i];) {
            a = b;
            b = c;
            c = a + b;
        }
        if (c - b ==  v[i])
            cout << "DA" << endl;
        else
            cout << "NU" << endl;
    }
    return 0;
}
