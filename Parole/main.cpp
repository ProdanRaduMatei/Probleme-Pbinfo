#include <bits/stdc++.h>
using namespace std;
ifstream fin("parole.in");
ofstream fout("parole.out");
bool lmi(char s[]) {
    bool ok=false;
    int i = 0;
    while(s[i]!='\0') {
        if(s[i]>='a' && s[i]<='z')
            ok=true;
    i++; } return ok; } bool lma(char s[]) { bool ok=false; int i = 0; while(s[i]!='\0') { if(s[i]>='A' && s[i]<='Z') ok=true; i++; } return ok; } bool cif(char s[]) { bool ok=false; int i = 0; while(s[i]!='\0') { if(s[i]>='0' && s[i]<='9') ok=true; i++; } return ok; } bool csp(char s[]) { bool ok=false; int i = 0; while(s[i]!='\0') { if(s[i]=='.' || s[i]==',' || s[i]=='?' || s[i]=='!' || s[i]==';' || s[i]==':' || s[i]=='_' || s[i]=='@' || s[i]=='#') ok=true; i++; } return ok; } int main() { int n; fin >> n; int cnt=0; for(int i = 0 ; i < n ; ++i) { char s[51]; fin >> s; bool ok = true; if(strlen(s) < 8) ok=false; if(!lmi(s)) ok=false; if(!lma(s)) ok=false; if(!cif(s)) ok=false; if(!csp(s)) ok=false; if(ok) cnt++; } fout << cnt; return 0; }
