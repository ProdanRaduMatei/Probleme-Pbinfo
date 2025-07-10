#include <iostream>

using namespace std;

int main()
{
    int n, a = 0, b = 0, c = 1, i;
    cin >> n;
    for (; c <= n;) {
        cout << c << " ";
        a = b;
        b = c;
        c = a + b;
    }
    return 0;
}
