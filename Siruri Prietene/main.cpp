#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    char a[101], b[101], pa[51], ia[51], pb[51], ib[51], cpa = 0, cia = 0, cpb = 0, cib = 0;
    cin >> a >> b;
    if (strlen(a) != strlen(b)) {
        cout << "NU SUNT PRIETENE";
    }
    for (int i = 0; a[i]; i = i + 2)
        pa[++cpa] = a[i];
    for (int i = 1; a[i]; i = i + 2)
        ia[++cia] = a[i];
    for (int i = 0; b[i]; i = i + 2)
        pb[++cpb] = b[i];
    for (int i = 1; b[i]; i = i + 2)
        ib[++cib] = b[i];
    sort(pa, pa + cpa);
    sort(pb, pb + cpb);
    if ()
    return 0;
}
