#include <iostream>

using namespace std;

void afisare(int a, int b) {
    bool k = 0;
    if (a < b) {
        if (a == 2)
            cout << 2 << " ";
        if (a % 2 == 0)
            a = a + 1;
        if (b % 2 == 0)
            b = b - 1;
        for (int i = a; i <= b; i = i + 2) {
            k = 0;
            for (int d = 3; d * d <= i; d = d + 2)
                if (i % d == 0)
                    k = 1;
            if (k == 0)
                cout << i << " ";
        }
    }
    else {
        if (b == 2)
            cout << 2 << " ";
        if (b % 2 == 0)
            b = b + 1;
        if (a % 2 == 0)
            a = a - 1;
        for (int i = b; i <= a; i = i + 2) {
            k = 0;
            for (int d = 3; d * d <= a; d = d + 2)
                if (i % d == 0)
                    k = 1;
            if (k == 0)
                cout << i << " ";
        }
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    afisare(a, b);
    return 0;
}
