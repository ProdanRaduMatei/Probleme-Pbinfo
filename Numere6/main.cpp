#include <bits/stdc++.h>
using namespace std;
ifstream fin("numere6.in");
ofstream fout("numere6.out");
int main() {
    int n , m;
    fin >> n >> m;
    int v[20];
    int p = 0;
    if(n==0)
        v[p]=0 , p++;
    if(m==0)
        v[p]=0 , p++;
    while(n) {
        v[p]=n%10;
        p++;
        n/=10;
    }
    while(m) {
        v[p]=m%10;
        p++; m/=10;
    }
    for(int i = 9 ; i >= 0 ; --i)
        for(int j = 0 ; j < p ; ++j)
            if(i==v[j])
                fout << i;
    return 0;
}
