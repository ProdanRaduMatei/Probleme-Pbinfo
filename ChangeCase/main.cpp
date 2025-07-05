#include <bits/stdc++.h>
using namespace std;
ifstream fin("changecase.in");
ofstream fout("changecase.out");
void LC(char s[]) {
    int i = 0;
    while(s[i]) {
        if(isalpha(s[i]))
            s[i]=tolower(s[i]);
        i++;
    }
}
void UC(char s[]) {
    int i = 0;
    while(s[i]) {
        if(isalpha(s[i]))
            s[i] = toupper(s[i]);
        i++;
    }
}
void TC(char s[]) {
    LC(s);
    int i = 0;
    while(s[i]) {
        if((i == 0 && isalpha(s[i])) || (strchr(".,; " , s[i-1]) && !strchr(".,; " , s[i])))
            s[i] = toupper(s[i]);
        i++;
    }
}
void IC(char s[]) {
    UC(s);
    int i = 0;
    while(s[i]) {
        if((i == 0 && isalpha(s[i])) || (strchr(".,; " , s[i-1]) && !strchr(".,; " , s[i])))
            s[i] = tolower(s[i]);
        i++;
    }
}
void SC(char s[]) {
    LC(s);
    bool ok = true;
    int i = 0;
    while(s[i]) {
        if(isalpha(s[i]) && ok)
            s[i] = toupper(s[i]) , ok = false;
        if(s[i] == '.')
            ok = true;
        i++;
    }
}
char c[15];
char s[256];
int main() {
    fin >> c;
    fin.get();
    fin.getline(s , 255);
    if(strcmp("lowercase" , c) == 0)
        LC(s);
    if(strcmp("UPPERCASE" , c) == 0)
        UC(s);
    if(strcmp("TitleCase" , c) == 0)
        TC(s);
    if(strcmp("iNVERTcASE" , c) == 0)
        IC(s);
    if(strcmp("Sentencecase" , c) == 0)
        SC(s);
    fout << s;
    return 0;
}
