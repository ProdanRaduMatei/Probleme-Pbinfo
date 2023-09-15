#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char pattern[256], modelul[256], nr[3], sir[50], text[100];
    int i, j, numar, paranteze=0, p1, p2, pnr, x;
    cin>>pattern;
    for(i=0;i<strlen(pattern);i++)
    if(pattern[i]=='[' || pattern[i]==']')
        paranteze++;
    while(paranteze){
        p1=0;
        p2=0;
        for(i=0;i<strlen(pattern);i++)
            if(pattern[i]=='['){
                p1++;
                if(p1==paranteze/2){
                    p1=i;
                    break;
                }
            }
        for(i=p1;i<=strlen(pattern);i++)
            if(pattern[i]==']'){
                p2=i;
                break;
            }
        i=p1-1;
        while(pattern[i]>='0' && pattern[i]<='9' && i>0)
            i--;
        if(i==0)
            pnr=0;
        else
            pnr=i+1;
        x=0;
        if(i==0)
            i=-1;
        for(j=i+1;j<p1;j++){
            nr[x]=pattern[j];
            x++;
        }
        nr[x]='\0';
        numar=int(nr - 32);
        x=0;
        for(i=p1+1;i<p2;i++){
            sir[x]=pattern[i];
            x++;
        }
        sir[x]='\0';
        numar--;
        strcpy(text,pattern+p2+1);
        while(numar){
            numar--;
            strcpy(pattern+p2,sir);
            p2=p2+strlen(sir);
        }
        strcpy(pattern+p2,text);
        strcpy(pattern+pnr,pattern+p1+1);
        paranteze=paranteze-2;
    }
    cout<<pattern;
    return 0;
}
