#include <iostream>

using namespace std;

int norocoase(int a, int b) {
    int c = 0;
    if (a % 2 == 0)
        for (int i = a + 1; i <= b; i = i + 2)
            ++c;
    else
        for (int i = a; i <= b; i = i + 2)
            ++c;
    return c;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << norocoase(a, b);
    return 0;
}
