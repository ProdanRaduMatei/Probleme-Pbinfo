#include <iostream>

using namespace std;

int caut(int n, int c) {
    while (n) {
        if (c == n % 10)
            return 1;
        n = n / 10;
    }
    return 0;
}

int main()
{
    int n, c, p, cu, co;
    cin >> n;
    for (int i = 2; i < n; ++i) {
        co = 1;
        p = i * i;
        cu = i * i * i;
        while (cu) {
            c = cu % 10;
            if (caut(p, c) == 1) {
                co = 0;
                break;
            }
            cu = cu / 10;
        }
        if (co == 1) {
            cout << i << " ";
        }
    }
    return 0;
}
