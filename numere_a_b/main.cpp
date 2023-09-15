#include <iostream>

using namespace std;

int main()
{
    int a, b, c = 0, p = 1;
    cin >> a >> b;
    while (a) {
        c = c + p * ((a % 10 + b % 10) / 2);
        a = a / 10;
        b = b / 10;
        p = p * 10;
    }
    cout << c;
    return 0;
}
