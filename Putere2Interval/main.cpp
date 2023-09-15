#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    unsigned long long n, a, b, k,p=1,i;
    cin >> n >> a >> b;
    k=log2(a);
    if (log2(a)!=(int)log2(a)) ++k;
    for (i=1; i<=k; ++i) p*=2;
    while (p<=b && n)
    {
        cout << p << " ";
        --n;
        p*=2;
    }
    return 0;
}
