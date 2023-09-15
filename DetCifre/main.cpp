#include <iostream>

using namespace std;

void detcifre(int n, int &p, int &u) {
    p = -1;
    u = -1;
    if (n < 10) {
        p = n;
        u = n;
    }
    else
        while (n) {
            if (u == -1)
                u = n % 10;
            else
                p = n % 10;
            n = n / 10;
        }
}

int main()
{
    int n, p, u;
    cin >> n;
    detcifre(n, p, u);
    cout << p << " " << u;
    return 0;
}
