#include <bits/stdc++.h>
using namespace std;
ifstream fin("anagrame2.in");
ofstream fout("anagrame2.out");
char s[100001] , cuv[25000];
int f1[200] , f2[200];
bool egale() {
    for(int i = 63; i <= 125; ++i)
        if(f1[i]!=f2[i])
            return 0;
    return 1;
}
int main() {
    int c;
    fin >> c;
    fin >> s;
    fin >> cuv;
    if(c==2) {
        for(int j = 0; j < strlen(cuv); ++j)
            f1[(int)cuv[j]]++;
        for(int i = 0 ; i < strlen(cuv) ; ++i)
            f2[(int)s[i]]++;
        int cnt=0;
        int i = strlen(cuv);
        if(egale())
            cnt++;
        while(s[i]!='\0') {
            f2[(int)s[i-strlen(cuv)]]--;
            f2[(int)s[i]]++;
            if(egale())
                cnt++;
            i++;
        }
        fout << cnt;
    }
    else {
        for(int j = 0 ; j < strlen(cuv) ; ++j)
            f1[(int)cuv[j]]++;
        for(int i = 0 ; i < strlen(cuv) ; ++i)
            f2[(int)s[i]]++;
        int cnt=0;
        int i = strlen(cuv);
        if(egale()) {
            for(int j = i - strlen(cuv)+1 ; j < i+1 ; ++j)
                fout << s[j];
        }
        else
            while(s[i]!='\0') {
                f2[(int)s[i-strlen(cuv)]]--;
                f2[(int)s[i]]++;
                if(egale()) {
                    for(int j = i - strlen(cuv)+1 ; j <= i ; ++j)
                        fout << s[j];
                    break;
                }
                i++;
            }
    }
    return 0;
}
