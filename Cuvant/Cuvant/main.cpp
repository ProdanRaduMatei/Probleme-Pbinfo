#include <bits/stdc++.h>
using namespace std;
char ch[256];
int main()
{
    cin.getline(ch , 256);
    int i = 0;
    int cnt1=0;
    bool da = true;
    while(ch[i]!='\0')
    {
        if(ch[i]=='a' || ch[i]=='e' || ch[i]=='o' || ch[i]=='u')
            da=false;
        else if(ch[i]!='i')
            cnt1++;
        i++;
    }
    if(da && cnt1)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
