#include <iostream>

using namespace std;

int main()
{
    long long a, b;
    int cn = 0;
    cin >> a >> b;
    while (a && b) {
        int u1 = a % 10, u2 = b % 10;
        if (u1 == u2)
            ++cn;
        a = a / 10;
        b = b / 10;
    }
    if (a == b)
        cout << "DA" << endl << cn;
    else {
        cout << "NU";
    }
    return 0;
}
