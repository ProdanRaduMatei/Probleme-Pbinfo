#include <bits/stdc++.h>

using namespace std;

int prim(int n) {
    int d=2 , cnt=1;
    while(n>1) {
        int p = 0;
        while(n%d==0) {
            n/=d;
            p++;
        }
        if(p!=0)
            cnt*=(p+1);
        d++;
        if(d*d>n)
            d=n;
    }
    if(cnt==2)
        return 1;
    else
        return 0;
}

int cmmdc(int a , int b) {
    while(b) {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    int y;
    cin >> y;
    int a[10000];
    int v[10000];
    int f[10]={0};
    int s=0 , cnt=0;
    int p = 0;
    for(int i = 0 ; i < n ; ++i) {
        cin >> a[i];
        if(prim(a[i]))
            s+=a[i];
        int x=a[i];
        while(x) {
            if(x%10==y)
                cnt++;
            x/=10;
        }
        if((a[i]%10)%2==1) {
            v[p]=a[i]%10;
            p++;
        }
    }
    for(int i = 0 ; i < p ; ++i)
        f[v[i]]++;
    int c , b=-1 , cmd=1 , i;
    for(i = 0 ; i <= 9 ; ++i) {
        while(f[i]==0 && b==-1) {
            i++;
            b=f[i];
        }
        while(f[i]==0)
            i++;
        c=f[i];
        cmd=cmmdc(c , b);
        b=cmd;
    }
    cout << s << endl << cnt << endl << p/cmd;
    return 0;
}
