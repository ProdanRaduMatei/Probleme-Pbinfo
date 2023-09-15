#include <iostream>

using namespace std;

void triplete(int n) {
    for (int y = 1; y <= 101; ++y)
        if (n % y == 0)
            for (int x = 0; x < y; ++x)
                if (y < (n / y) - x)
                    cout << "(" << x << "," << y << "," << (n / y) - x << ")" << endl;
}

int main()
{
    int n;
    cin >> n;
    triplete(n);
    return 0;
}
