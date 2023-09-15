#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    int c = n / 10;
    int r = n % 10;
    switch(r) {
        case 0: cout << ((c * 3) % 10) % 10; break;
        case 1: cout << ((c * 3) % 10 + 1) % 10; break;
        case 2: cout << ((c * 3) % 10 + 7) % 10; break;
        case 3: cout << ((c * 3) % 10 + 8) % 10; break;
        case 4: cout << ((c * 3) % 10 + 14) % 10; break;
        case 5: cout << ((c * 3) % 10 + 19) % 10; break;
        case 6: cout << ((c * 3) % 10 + 25) % 10; break;
        case 7: cout << ((c * 3) % 10 + 26) % 10; break;
        case 8: cout << ((c * 3) % 10 + 32) % 10; break;
        case 9: cout << ((c * 3) % 10 + 33) % 10; break;
    }
    return 0;
}
