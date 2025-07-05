#include <iostream>
using namespace std;
bool prim(int m)
{
    int p=1;
    if (m<2)
        p=0;
    else {
        if (m==2)
            p=1;
        else {
            if (m%2==0)
                p=0;
            else {
                for (int j=3; j*j<=m; ++j)
                    if (m%j==0) {
                        p=0;
                        break;
                    }
            }
        }
    }
    return p;
}

int interval(int n)
{
    int x;
    if (prim(n))
        x=n+1;
    else {
        while (!prim(n))
            ++n;
        x=n+1;
    }
    return x;
}
int main()
{
    int n;
    cin >> n;
    cout << interval(n);
}
