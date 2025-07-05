#include <iostream>

using namespace std;

int suma(int a, int b)
{
    int s = 1;
    for (int d = 2; d * d <= max(a, b); ++d)
        if (a % d == 0 && b % d == 0)
        {
            s = s + d;
            if (a / d == b / d)
                s = s + a / d;
        }
    return s;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << suma(a, b);
    return 0;
}
