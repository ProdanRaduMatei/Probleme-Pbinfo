#include <bits/stdc++.h>
using namespace std;
bool palindrom(char s[]) {
    for(int i = 0 , j = strlen(s)-1; i < j ; ++i , --j)
        if(tolower(s[i])!=tolower(s[j]))
            return 0;
    return 1;
}
int main() {
    char s[256] , *p , pal[11]="";
    cin.getline(s , 256);
    p = strtok(s , " .,;:");
    bool gasit = false;
    while(p) {
        if(palindrom(p))
            if(strlen(p) > strlen(pal))
                strcpy(pal , p) , gasit = 1;
        p = strtok(NULL , " .;:,");
    }
    if(gasit)
        cout << pal;
    else
        cout << "IMPOSIBIL";
    return 0;
}
