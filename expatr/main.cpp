#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a;
    cin >> a;
    cout << (3 * a * a + 3 * a * a * a * a) / (a * a + a * a * a * a + (int)sqrt(a * a + a * a * a * a)) + (int)sqrt(a * a + a * a * a * a);
    return 0;
}
