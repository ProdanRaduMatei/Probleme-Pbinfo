#include <iostream>

using namespace std;

int main()
{
    int n, a = 0, b = 0, c = 1, i;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        if (i == 1)
            cout << c << " ";
        else {
            a = b;
            b = c;
            c = a + b;
            cout << c << " ";
        }
    }
    return 0;
}
