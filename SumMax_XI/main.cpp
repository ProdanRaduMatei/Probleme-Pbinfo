#include <bits/stdc++.h>
using namespace std;

ifstream fin("summax_xi.in");
ofstream fout("summax_xi.out");

int a[101][101], n;
long long int sum;

int main()
{
    fin >> n;
    for(int i = 1; i <= n; ++i){
        int max = -100000000;
        for(int j = 1; j <= n; ++j){
            fin >> a[i][j];
            if(a[i][j] > max)
                max = a[i][j];
        }
        sum += max;
    }
    fout << sum;
    return 0;
}
