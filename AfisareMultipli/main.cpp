#include <iostream>

using namespace std;

void sub(int n, int k) {
    while (n >= 1) {
        cout << n * k << " ";
        --n;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    sub(n, k);
    return 0;
}
