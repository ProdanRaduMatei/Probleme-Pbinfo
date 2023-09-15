#include <bits/stdc++.h>
using namespace std;

ifstream fin("summin_xi.in");
ofstream fout("summin_xi.out");

int n , a[101][101] , sum;

int main()
{
    fin >> n;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            fin >> a[i][j];
    for(int j = 1 ; j <= n ; j++)
    {
        int mini = 999999999;
        for(int i = 1 ; i <= n ; i++)
            if(a[i][j] < mini) mini = a[i][j];
        sum += mini;
    }
    fout << sum;

}
