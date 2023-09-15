#include <bits/stdc++.h>

using namespace std;

int testVoc(char ch)
{
    char voc[]="aeiou";
    return(strchr(voc,ch)!=NULL);
}

int main()
{
    char t[256]={},s[256]={};
    int k=0,lung,lv=0;
    cin.getline(s,256);
    lung=strlen(s);
    for(int i=0;i<lung;i++){
        lv=0;
        while(testVoc(s[i]) && i<lung){
            i++;
            lv++;
        }
        if(lv==0){
            t[k++]=s[i];
        }
        if(lv==1){
            t[k++]=s[i-1];
            t[k++]=s[i];
        }
        if(lv>1){
            i--;
        }
    }
    cout<<t;

    return 0;
}
