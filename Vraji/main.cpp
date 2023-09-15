#include <bits/stdc++.h>
using namespace std;
ifstream fin("vraji.in");
ofstream fout("vraji.out");
int n , v , c , cer , cnt , cate , maxi;
char vmax[51];
int put(int x , int y) {
    int p = 1;
    for(int i = 1 ; i <= y ; i++)
        p *= x;
    return p;
}
int vocala(char a) {
    return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'q' || a == 'w' || a == 'y';
}
int consoana(char a) {
    if(a >= 'a' && a <= 'z' && !vocala(a))
        return 1;
    else
        return 0;
}
int calcul(char s[]) {
    int i = 0;
    int catevoc = 0 , catecons = 0 , f[30] = {0} , suma = 0 , dist = 0;
    while(s[i] != '\0') {
        if(vocala(s[i]))
            catevoc++;
        if(consoana(s[i]))
            catecons++;
        f[s[i] - 'a']++;
        i++;
    }
    for(int j = 0 ; j <= 25 ; j++) {
        if(f[j])
            dist++;
    }
    //cout << dist <<'\n';
    suma = (catevoc * v + catecons * c) / dist + 1;
    i = 0;
    int l = 0;
    while(s[i] != '\0') {
        if(s[i] == s[i+1]) {
            l = 1;
            int j = i;
            while(s[i] == s[j])
                j++ , l++;
            if(l > 1 && vocala(s[i]))
                suma += put(v , l - 1);
            else if(l > 1 && consoana(s[i]))
                suma += put(c , l - 1);
            i = j - 1;
        }
        i++;
        //cout << s[i] << " ";
    }
    return suma;
}
int main() {
    char s[51];
    fin >> cer;
    fin >> n >> v >> c;
    for(int i = 1 ; i <= n ; i++) {
        fin >> s;
        int j = 0 , ok = 0;
        while(s[j] != '\0') {
            if(s[j] == s[j-1])
                ok = 1;
            j++;
        }
        if(ok == 1)
            cnt++;
        if(calcul(s) > maxi) {
            maxi = calcul(s);
            cate = 1;
            strcpy(vmax , s);
        }
        else if(calcul(s) == maxi)
            cate++;
    }
    if(cer == 1)
        fout << cnt;
    else
        fout << cate << " " << vmax;
}
