#include <iostream>

using namespace std;

void afisare(int a, int b) {
    if (a < b) {
        if (a % 2 != 0)
            a = a + 1;
        if (b % 2 != 0)
            b = b - 1;
        for (int i = a; i <= b; i = i + 2)
            cout << i << " ";
    }
    else {
        if (a % 2 != 0)
            a = a - 1;
        if (b % 2 != 0)
            b = b + 1;
        for (int i = b; i <= a; i = i + 2)
            cout << i << " ";
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    afisare(a, b);
    return 0;
}
