#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , x , cnt = 0 , a[1001];
    cin >> n >> x;
    for(int i = 0 ; i < n ; ++i)
        cin >> a[i];
    for(int i = n - 2 ; i >= 0 ; --i)
    {
        if(a[i+1]>a[i])
        {
            int d = a[i+1]-a[i];
            int c = d / x;
            if(c * x != d)
                c++;
            cnt += c;
            a[i] += c * x;
        }
    }
    cout << cnt;
    return 0;
}
