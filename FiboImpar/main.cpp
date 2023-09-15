#include <iostream>

using namespace std;

int Fibo(int n) {
    int  a = 1, b = 1, c = 1;
    if (n <= 2)
        return 1;
    n = n - 2;
    while (n) {
        c = a + b;
        if (c % 2 != 0)
            --n;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int n;
    cin >> n;
    cout << Fibo(n);
    return 0;
}
