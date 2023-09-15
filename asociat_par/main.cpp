#include <iostream>
using namespace std;
int asociat(int n, int &as)
{
    int p=1, ok=0;
    as = 0;
    if (n==0) ok=1;
    else
        while (n)
        {
            if (n%2==0)
            {
                as=n%10*p+as;
                p*=10;
                ok=1;
            }
        n/=10;
        }
    return ok;
}
int palindrom (int n)
{
    int y=0;
    while (n)
    {
        y = y*10+n%10;
        n/=10;
    }
    return y;
}
int estePalindrom(int n)
{
    if (n==palindrom(n))
        return 1;
    return 0;
}
int n, ans=0, ok;
int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int x, as;
        cin>>x;
        if (x==0)
            ans++;
        else
        {
            ok = asociat(x, as);
            if (ok && estePalindrom(as))
                ans++;
        }
    }
    cout<<ans;
}
