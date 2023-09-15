#include <bits/stdc++.h>
using namespace std;
ifstream fin("cod.in");
ofstream fout("cod.out");
char s[1001];
bool valid(int n) {
    if(n == '.')
        return 1;
    if(n == ' ')
        return 1;
    if((n >= 'A' && n <= 'Z') || (n >= 'a' && n <= 'z'))
        return 1;
    return 0;
}

int ogl(int n) {
    int ogl=0;
    while(n)
        ogl=ogl*10+n%10 , n/=10;
    return ogl;
}

int main() {
    while(fin>>s) {
        int i = 0;
        int cnt = 0;
        int nr = 0 , p = 1;
        char v[200]="" ;
        int n = 0;
        while(s[i]!='\0') {
            nr+=(s[i]-48) * p;
            p*=10;
            cnt++;
            if(cnt%2==0)
                if(!valid(nr))
                    i++ , nr+=(s[i]-48) * p;
            if(cnt%2==0) {
                v[++n]=nr;
                nr=0;
                p=1;
            }
            i++;
        }
        for(int i = 1 ; i <= n+1 ; ++i) {
            if(v[i]=='.' || v[i]==' ' || v[i]=='\0') {
                int j = i-1;
                while(v[j]!='.' && v[j]!=' ' && j > 0) {
                    fout << (char)v[j];
                    j--;
                }
                if(v[i]!='\0')
                    fout << (char)v[i];
            }
        }
        fout << endl;
    }
    return 0;
}
