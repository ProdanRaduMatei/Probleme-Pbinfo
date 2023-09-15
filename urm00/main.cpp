#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 100)
        cout << 100;
    else {
        if (n % 10 == 0 && (n / 10) % 10 == 0)
            cout << n;

        else {
            n = n / 100;
            n = n + 1;
            n = n * 100;
            cout << n;
        }
    }
    return 0;
}
