#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[151],*p,voc[]="aeiouAEIOU";
    cin.get(s,151);
    p=strtok(s," ");
    int nr=0;
    while(p)
    {
        if(strchr(voc,p[0])!=0 && strchr(voc,p[strlen(p)-1])!=0)
            nr++;
        p=strtok(NULL," ");
    }
    cout<<nr;
    return 0;
}
