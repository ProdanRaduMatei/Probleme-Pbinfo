#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char ch, cM;
    int cod, mac, s = 0, c = 0;
    cin >> ch;
    if (ch == '.')
        cout << "sirul e vid";
    else {
        while (ch != '.') {
            ++c;
            cod = (int)ch;
            s = s + cod;
            cin >> ch;
        }
        mac = s / c;
        cM = mac;
        cout << cM;
    }
    return 0;
}
