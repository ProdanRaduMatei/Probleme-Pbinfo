#include <iostream>
using namespace std;
int gen(int k,int l){
    int s = 0;
    for(int i = 1; i <= l; i++){
        s += ((k&1) == 1 ? 1 : -1)*i*i;
        k>>=1;
    }
    return s;
}
void writebin(int x, int l){
    for(int i = 1; i <= l; i++){
    cout << ((x&1) ? '+' : '-');
    x>>=1;
    }
}
int main(){
    int n;
    cin >> n;
    int s;
    bool f = false;
    for(int j = 1; j <= 15; j++){
        for(int k = 0; k < 1<<j; k++){
            s = gen(k, j);
            if(s==n){
                f = true;
                writebin(k,j);break;}
        }
        if(f)break;
    }
}
