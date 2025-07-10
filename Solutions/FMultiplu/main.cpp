#include <iostream>

using namespace std;

int multipli(int a, int b, int c) {
    int cn = 0;
    cn = b / c - a / c;
    if (a % c == 0)
        ++cn;
    return cn;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << multipli(a, b, c);
    return 0;
}
