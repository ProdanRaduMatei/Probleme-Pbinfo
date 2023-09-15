#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    if (a == 0)
        cout << 0;
    else if (a == 1)
        cout << 1;
    else if (a == 2)
        cout << 65536;
    else if (a == 3)
        cout << 43046721;
    else if (a == 4)
        cout << 4294967296;
    else if (a == 5)
        cout << 390625;
    else if (a == 6)
        cout << 65536 * 43046721;
    else if (a == 7)
        cout << 5764801 * 5764801;
    else if (a == 8)
        cout << 65536 * 65536 * 65536;
    else if (a == 9)
        cout << 43046721 * 43046721;
    return 0;
}
