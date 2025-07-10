#include <bits/stdc++.h>
using namespace std;
ifstream fin("capslock.in");
ofstream fout("capslock.out");
char s[256];
int main()
{
    fin.getline(s,256);
    for(int i=0; i<strlen(s); i++)
        if(s[i] == '#')
    {
        int j = i+1;
        while(s[j] && s[j] != '#')
            {
                s[j] = toupper(s[j]);
                j++;
            }
        i = j;
    }
    for(int i=0; i<strlen(s); i++)
        if(s[i]!='#')
          fout << s[i];
    return 0;
}
