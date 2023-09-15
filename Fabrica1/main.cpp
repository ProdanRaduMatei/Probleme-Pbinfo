#include <iostream>

using namespace std;

int n, i, t, t1, pachete;

int main()
{
    cin >> t;
    t=t*60;
    cin >> n;
    for (i=1; i<=n; ++i)
    {
        cin >> t1;
        pachete=pachete+t/t1;
    }
    cout << pachete;
    return 0;
}
