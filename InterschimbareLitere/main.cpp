#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char s[25],aux;
    int i,PrimaVocala= -1, UltimaConsoana=-1;
    i = 0;
    cin.getline(s, 24);
    while(i<strlen(s)&&PrimaVocala==-1)
    {
        if(strchr("AEIOUaeiou",s[i])!= NULL)
            PrimaVocala = i;
        i++;
    }
    i=strlen(s)-1;
    while(i>0&&UltimaConsoana==-1)
    {
        if(strchr("AEIOUaeiou",s[i])== NULL)
            UltimaConsoana = i;
        i--;
    }
    aux = s[PrimaVocala];
    s[PrimaVocala] = s[UltimaConsoana];
    s[UltimaConsoana] = aux;
    cout<<s;
}
