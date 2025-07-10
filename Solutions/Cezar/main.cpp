#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[300];
    cin.getline(s , 300);
    int n;
    cin >> n;
    int i = 0;
    while(s[i]!='\0') {
        if(s[i] >= 'a' && s[i] <= 'z') {
            if((int)s[i]+n > 122)
                cout << (char)((int)s[i]+n-26);
            else
                cout << (char)((int)s[i]+n);
        }
        else
            cout << s[i];
        i++;
    }
    return 0;
}
