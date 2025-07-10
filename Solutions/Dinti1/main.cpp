#include <iostream>

using namespace std;

int s = 0;

void fer(int n) {
    if (n >= 1) {
        fer(n - 1);
        s = s + n;
        fer(n - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    fer(n);
    cout << s;
    return 0;
}
