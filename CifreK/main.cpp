#include <iostream>

using namespace std;

int main()
{
    bool ok = 0;
    int k, c = 0;
    long long x;
    cin >> k;
    while (ok == 0) {
        cin >> x;
        if (x == 0)
            ok = 1;
        else if (x % 2 == 0) {
            while (x) {
                if (x % 10 == k)
                    ++c;
                x = x / 10;
            }
        }
    }
    cout << c;
    return 0;
}
