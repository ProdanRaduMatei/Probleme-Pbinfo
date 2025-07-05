#include <bits/stdc++.h>
using namespace std;
ifstream fin("paritatesiruri.in");
ofstream fout("paritatesiruri.out");
int main()
{
    int n;
    fin >> n;
    for(int q = 1 ; q <= n ; ++q)
    {
        char s[1000];
        fin >> s;
        int i = 1;
        while(s[i]!='\0')
        {
            if(i % 2 == 1)
            fout << s[i];
            i++;
        }
        i = 0;
        fout << ' ';
        while(s[i]!='\0')
        {
            if(i % 2 == 0)
            fout << s[i];
            i++;
        }
        fout << '\n';
    }
    return 0;
}
