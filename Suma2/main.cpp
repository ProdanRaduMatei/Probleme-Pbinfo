#include <iostream>

using namespace std;

int main()
{
    int n, v[1001], p = 0, P, s = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        if (v[i] % 2 == 0)
            if (p == 0)
                p = i;
            else
                P = i;
    }
    if (p == 0)
        cout << "NU EXISTA";
    else {
        for (int i = p; i <= P; ++i)
            s = s + v[i];
        cout << s;
    }
    return 0;
}
