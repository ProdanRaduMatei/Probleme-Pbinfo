#include <iostream>

using namespace std;

void perfect(int a, int b) {
    int c = 0, s = 0;
    if (b % 2 != 0)
        b = b - 1;
    if (a % 2 != 0)
        a = a + 1;
    for (int i = b; i >= a; i = i - 2) {
        s = 1;
        for (int d = 2; d * d <= i; d = d + 2)
            if (i % d == 0) {
                if (d * d == i)
                    s = s + d;
                else
                    s = s + d + i / d;
            }
        if (s == i && i != 1) {
            cout << i << " ";
            ++c;
        }
    }
    if (c == 0)
        cout << "nu exista";
}

int main()
{
    int a, b;
    cin >> a >> b;
    perfect(a, b);
    return 0;
}
