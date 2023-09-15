#include <iostream>

using namespace std;

struct persoane{
    int a;
    int l;
    int z;
}v[1100],maxim,minim;
int main()
{
    int i,n,j = 1,k = 1;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>v[i].a>>v[i].l>>v[i].z;
    }
    maxim = v[1];
    minim = v[1];
    for(i=2;i<=n;i++){
        if(v[i].a > maxim.a || (v[i].a == maxim.a && v[i].l > maxim.l) || (v[i].a == maxim.a  && v[i].l == maxim.l && v[i].z > maxim.z)){
            maxim = v[i];
            j = i;
        }

        if(v[i].a < minim.a || (v[i].a == minim.a && v[i].l < minim.l) || (v[i].a == minim.a  && v[i].l == minim.l && v[i].z < minim.z)){
            k = i;
            minim = v[i];
        }

    }
   // cout<<minim.a<<" "<<minim.l<<" "<<minim.z<<endl;
    //cout<<maxim.a<<" "<<maxim.l<<" "<<maxim.z<<endl;
    cout<<j<<" "<<k;
    return 0;
}
