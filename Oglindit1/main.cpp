#include <iostream>

using namespace std;

void oglindit(int n, int &m) {
    m = 0;
    while (n) {
        m = m * 10 + n % 10;
        n = n / 10;
    }
}

int main()
{
    int n, m;
    cin >> n;
    oglindit(n, m);
    cout << m;
    return 0;
}
