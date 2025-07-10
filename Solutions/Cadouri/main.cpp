#include <bits/stdc++.h>
using namespace std;
ifstream fin("cadouri.in");
ofstream fout("cadouri.out");
map <string, int> M;
char s[1001];
bool nr(char ch) {
    return ch >= '0' && ch <= '9';
}
bool lit(char ch) {
    return (ch >='a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int main() {
    int n;
    fin >> n;
    fin.get();
    for(int k = 1 ; k <= n ; ++k) {
        fin.getline(s , 1000);
        int i = 0;
        int num = 0;
        while(s[i]!='\0') {
            while(nr(s[i])) {
                num=num*10+(int)s[i]-48;
                i++;
            }
            if(num) {
                while(!lit(s[i]) && num)
                    i++;
                if(lit(s[i]) && num) {
                    int j = 0;
                    char ch[255];
                    while(lit(s[i]) && s[i]) {
                        ch[j]=s[i];
                        j++;
                        i++;
                    }
                    ch[j]='\0';
                    string p = ch;
                    M[p]+=num;
                    num=0;
                }
                i--;
            }
            i++;
        }
    }
    int cnt = 0;
    for(auto x:M)
        cnt++;
    fout << cnt << endl;
    int v[1001] , p = 0;
    for(auto x:M) {
        v[p] = x.second;
        p++;
    }
    sort(v , v+p);
    for(int i = p-1 ; i >= 0 ; --i) {
        for(auto x:M) {
            if(x.second == v[i]) {
                fout << x.first << ' ' << x.second << '\n';
                M[x.first]=-1;
                break;
            }
        }
    }
    return 0;
}
