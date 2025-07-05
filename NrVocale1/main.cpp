#include <bits/stdc++.h>
using namespace std;
int apcar(char * s , char ch) {
    int i = 0;
    int cnt=0;
    while(s[i]!='\0') {
        if(s[i]==ch)
            cnt++;
        i++;
    }
    return cnt;
}
int main() {
    char s[300];
    cin.getline(s , 300);
    int cnt=0;
    char character = 'a';
    cnt+=apcar(s , character);
    character='e';
    cnt+=apcar(s , character);
    character='i';
    cnt+=apcar(s , character);
    character='o';
    cnt+=apcar(s , character);
    character='u';
    cnt+=apcar(s , character);
    character='A';
    cnt+=apcar(s , character);
    character='E';
    cnt+=apcar(s , character);
    character='I';
    cnt+=apcar(s , character);
    character='O';
    cnt+=apcar(s , character);
    character='U';
    cnt+=apcar(s , character);
    cout << cnt;
    return 0;
}
