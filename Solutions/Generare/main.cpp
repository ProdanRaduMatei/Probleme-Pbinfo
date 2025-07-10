#include <iostream>

using namespace std;

int f(int n) {
    if (n == 1)
        return 1;
    if (n % 2)
        return 1 + 2*f(n - 2);
    return 1 + f(n - 1);
}
int main() {
    unsigned x, i = 1;
    long v[61];
    cin>>x;
    while(f(i)<=x){
        v[i] = f(i);
        i++;
    }
    while(i>1){
        cout<<v[--i]<<" ";
    }
    return 0;
}
