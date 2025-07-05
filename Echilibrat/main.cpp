#include <iostream>

using namespace std;

int echilibrat(int n) {
    int s1 = 0, s2 = 0;
    while (n >= 10) {
        s1 = s1 + n % 10;
        n = n / 10;
        s2 = s2 + n % 10;
        n = n / 10;
    }
    if (n < 10 && n != 0)
        s1 = s1 + n % 10;
    if (s1 % 2 == 0 && s2 % 2 != 0)
        return 1;
    else
        return 0;

}

int main()
{
    int n;
    cin >> n;
    cout << echilibrat(n);
    return 0;
}
