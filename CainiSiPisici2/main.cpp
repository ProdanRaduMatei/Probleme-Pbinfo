#include <iostream>

using namespace std;

int n,st[25],p;

void afisare(){
    for (int i=1; i<=n; i++){
        if (st[i]==1) cout<<'C';
        else cout<<'P';
    }
    cout<<'\n';
}

int valid(int k){
    int Np=0;
    if (st[1]!=1) return 0;
    for (int i=2; i<k; i++){
        if (st[i-1]==1 && st[i]==2 && st[i+1]==1) return 0;
        if (st[i]==2) Np++;
    }
    if (k==n){
        if (st[k]!=2) return 0;
        else Np++;
        if (Np>p) return 0;
    }
    return 1;
}

void bkt(int k){
    for (int i=1; i<=2; i++){
        st[k]=i;
        if (valid(k)){
            if (k==n) afisare();
            else bkt(k+1);
        }
    }
}

int main()
{
    cin>>n>>p;
    bkt(1);
}