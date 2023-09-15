#include <iostream>
#include <math.h>

using namespace std;

int n, s;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int d = 1; d * d <= i; ++d)
            if (d * d == i)
                s = s + i;
    cout << "Rezultatul este " << s;
    return 0;
}
