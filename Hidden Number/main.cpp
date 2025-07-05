#include <bits/stdc++.h>

using namespace std;

ifstream f("hidden_number.in");
ofstream g("hidden_number.out");

int main()
{
    int x, nr = 0, s = 0;
    while(f >> x)
    {
        s = s + x;
        nr++;
    }
    if(s % nr == 0)
        g << s / nr;
    else
        g << -1;
    return 0;
}
