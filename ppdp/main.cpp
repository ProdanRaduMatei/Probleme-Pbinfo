#include <iostream>

using namespace std;

int prim(int x) {
    if (x <= 1)
        return x;
    if (x == 2)
        return 2;
    if (x % 2 == 0)
        return 2;
    for (int i = 3; i * i <= x; i = i + 2)
        if (x % i == 0)
            return i;
    return x;
}

int patrat(int x) {
    return x * x;
}

int main()
{
    long long n;
    cin >> n;
    cout << patrat(prim(n));
    return 0;
}
