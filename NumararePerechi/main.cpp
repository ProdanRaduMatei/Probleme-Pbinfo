#include <iostream>

using namespace std;

long long int a, b;
int cnt;
int main()
{
    cin >> a;
    if (a == 0) {
        cout << 0;
        return 0;
    }
    do {
        cin >> b;
        if (a % 10 == b % 10 && b != 0)
            ++cnt;
        a = b;
    } while (b != 0);
    cout << cnt;
    return 0;
}
