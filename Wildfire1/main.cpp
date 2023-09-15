#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x , y , n , m;
    cin >> x >> y >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
            cout << abs(i - x) + abs(j - y) + 1 << " ";
        cout << "\n";
    }
}
