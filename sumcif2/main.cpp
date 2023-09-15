#include <iostream>
using namespace std;
int main()
{
    int n, nrcif=0, s1=0, s2=0, S, cif;
    cin >> n;
    while (n)
    {
        cif=n%10; ++nrcif; n/=10;
        if (nrcif%2) s1+=cif;
        else s2+=cif;
    }
    if (nrcif%2) S=s1;
    else S=s2;
    cout << S << endl;
    return 0;
}
