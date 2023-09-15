#include <iostream>

using namespace std;

int main()
{
    int n, p1 = -1, p2 = -1, c;
    long long s = 0;
    do {
        cin >> n;
        c = n;
        if (c >= 10) {
            while (c) {
                p2 = p1;
                p1 = c % 10;
                c = c / 10;
            }
            s = s + p1 * 10 + p2;
        }
    } while (n != 0);
    cout << s;
    return 0;
}
