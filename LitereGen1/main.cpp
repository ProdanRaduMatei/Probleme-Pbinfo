#include <iostream>

using namespace std;

int n;
int a[30];

void bkt(int k)
{
    if(k == n + 1)
    {
        for(int i=1;i<=n;i++)
            cout << (char)(a[i] + 'a' - 1);
        cout << '\n';
    }
    else
    {
        if(k >= n / 2 + 2)
        {
             if(a[k - 1] > 1)
                a[k] = a[k - 1] - 1 , bkt(k + 1);
            if(a[k - 1] <= n - k)
                a[k] = a[k - 1] + 1 , bkt(k + 1);
        }
        else
        {
            if(a[k - 1] > 1)
            a[k] = a[k - 1] - 1 , bkt(k + 1);
            a[k] = a[k - 1] + 1 , bkt(k + 1);
        }
    }
}

int main()
{
    cin >> n;
    bkt(1);
    return 0;
}
