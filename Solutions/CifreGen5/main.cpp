#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
#define NR 20
int x[NR],p,k,nr;
char a[5000][20];
void init(int k){
    x[k]=0;
}
int succesor(int k){
    if(x[k]<10)
        return 1;
    else
        return 0;
}
int continuare(int k){
    if(k==1&&abs(x[k]-2)!=1)
        return 0;
    if(k==p&&abs(x[k]-2)!=1)
        return 0;
    for(int i=2;i<=k;++i)
        if(abs(x[i]-x[i-1])!=1)
        return 0;
    return 1;
}
int solutie(int k){
    if(k==p+1)
        return 1;
    else
        return 0;
}
void retin(){
    a[nr][0]='0',a[nr][1]='1';
    for(int i=1;i<=p;i++)
        a[nr][i+1]='0'+x[i]-1;
    a[nr][p+2]='1',a[nr][p+3]='0';
    a[nr][p+4]='\0';
    ++nr;
}
void backtracking(){
    int k;
    k=1;
    init(k);
    while(k>0)
        if(solutie(k)) {
            retin();
            k--;
        }
        else if(succesor(k)) {
            x[k]++;
            if(continuare(k))
                k++;
        }
        else {
            init(k);
            k--;
        }
}
int main(){
    cin>>p;
    if(p%2==0)
        return 0;
    if(p==3)
        cout<<"010\n";
    else {
        p-=4;
        backtracking();
        char aux[20];
        for(int i=0;i<nr-1;i++)
            for(int j=i+1;j<=nr-1;++j)
                if(strcmp(a[i],a[j])==1) {
                    strcpy(aux,a[i]);
                    strcpy(a[i],a[j]);
                    strcpy(a[j],aux);
                }
        for(int i=0;i<nr;++i)
            cout<<a[i]<<'\n';
    }
    return 0;
}
