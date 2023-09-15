#include<iostream>
int n,m,p,v[10001],s,u[10001];
int main(){
    std::cin>>n>>p;
    for(int i=1;i<=n;++i){
        int a;
        std::cin>>a;
        v[a]++;
    }
    std::cin>>m;
    for(int i=1;i<=m;++i){
        int a;
        std::cin>>a;
        u[a]++;
    }
    for(int i=0;i<10000;++i){
        if(v[i]!=0)
        for(int j=0;j<10000;++j){
            if(i*j>=p)
                break;
            s+=v[i]*u[j];
        }
    }
    std::cout<<s;
}
