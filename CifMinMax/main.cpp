#include <iostream>

using namespace std;

void cifminmax(int n, int &M, int &m) {
    M = 0;
    m = 9;
    if (n == 0)
        m = 0;
    while (n) {
        if (n % 10 < m)
            m = n % 10;
        if (n % 10 > M)
            M = n % 10;
        n = n / 10;
    }
}

int main()
{
    int n, M, m;
    cin >> n;
    cifminmax(n, M, m);
    cout << M << " " << m;
    return 0;
}
