#include <iostream>

using namespace std;

void P(int n, int x[], int &s) {
    bool k = 0;
    s = 0;
    for (int i = 0; i < n; ++i) {
        if (x[i] == 2)
            s = s + 2;
        else if (x[i] % 2 == 1 && x[i] > 2) {
            k = 0;
            for (int d = 3; d * d <= x[i]; d = d + 2)
                if (x[i] % d == 0)
                    k = 1;
            if (k == 0)
                s = s + x[i];
        }
    }
}

int main()
{
    int x[100], n, s;
    cin >> n;
    for (int i = 0 ; i < n; ++i)
        cin >> x[100];
    P(n, x, s);
    cout << s;
    return 0;
}
