#include <bits/stdc++.h>

using namespace std;
ifstream fin("culori.in");
ofstream fout("culori.out");
int main()
{
    int n , a[1001] ,v[1001] , l = 1 , cnt = 0 , ok = 0;
    fin >> n;
    for(int i = 0 ; i < n ; ++i)
        fin >> a[i] , v[i]=a[i];
    sort(a , a+n);
    for(int i = 0 ; i < n ; ++i)
    {
        if(a[i]==a[i+1]) l++;
        else
        {
            int c = 0;
            for(int j = 0 ; j < n ; ++j)
            {
                if(v[j]==a[i]) c++;
                else if(c!=0) break;
            }
            if(c != l) ok = 1;
            cnt++;
            l = 1;
        }
    }
    fout << cnt << endl;
    if(ok == 0)
        fout << "DA";
    else
        fout << "NU";
    return 0;
}
