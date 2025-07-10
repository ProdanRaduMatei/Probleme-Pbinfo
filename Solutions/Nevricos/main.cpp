#include <bits/stdc++.h>
using namespace std;
ifstream fin("nevricos.in");
ofstream fout("nevricos.out");

int main()
{
    long long int c = 0 , d = 0 , f1 = 0 , f2 = 0;
    char x , y;
    fin >> x;
    while(fin >> y)
    {
        if((x=='1' && y == '5') || (x=='2' && y=='4')) c++;
        if(x=='1') f1++;
        if(x=='2') f2++;
        if(y=='5') d +=f1;
        if(y=='4') d +=f2;
        x = y;
    }
    fout << c << '\n' << d;
    return 0;
}
