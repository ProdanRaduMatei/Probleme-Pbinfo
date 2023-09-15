#include <iostream>

using namespace std;
int n,i,j;
long a[1000];
bool ok;

int main() {
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        ok=false;
        for(int j=i+1;j<n;j++)
            if(!ok)
                if(a[j]>a[i]) {
                    cout<<a[j]<<" ";
                    ok=true;
                }
        if(!ok)
            cout<<-1;
    }
    return 0;
}
