#include <iostream>

using namespace std;

int main() {
    long long n, x, v[1001], l = 0, ok = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        if (x % 10 == 0)
        {
            ok = 1;
            v[++l] = x;
        }
    }
    if (ok == 0)
        cout << "NU EXISTA";
    else
    {
        for (int i = 1; i < l; ++i)
            for (int j = i + 1; j <= l; ++j)
                if (v[i] < v[j])
                    swap(v[i], v[j]);
        for (int i = 1; i <= l; ++i)
            cout << v[i] << " ";
    }
    return 0;
}
