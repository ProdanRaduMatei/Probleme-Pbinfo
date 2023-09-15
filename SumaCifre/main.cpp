#include <iostream>

using namespace std;

void sumcif(int n, int &s, int &t) {
    s = 0;
    t = 0;
    while (n) {
        if ((n % 10) % 2 == 0)
            s = s + n % 10;
        else
            t = t + n % 10;
        n = n / 10;
    }
}

int main()
{
    int n, s, t;
    cin >> n;
    sumcif(n, s, t);
    cout << s << " " << t;
    return 0;
}
