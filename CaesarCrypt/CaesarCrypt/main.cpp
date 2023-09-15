#include <bits/stdc++.h>
using namespace std;
ifstream fin("caesar.in");
ofstream fout("dbftbs.out");
char s[300], cer[20];
int n;
bool LM(char ch)
{
    return ch >= 'A' && ch <= 'Z';
}
bool lm(char ch)
{
    return ch >= 'a' && ch <= 'z';
}
int main()
{
    fin.getline(s, 260);
    fin >> n;
    fin >> cer;
    n=n%26;
    if(strcmp(cer, "encrypt") == 0)
    {
        int i = 0;
        while(s[i])
        {
            if(lm(s[i]) || LM(s[i]))
            {
                if(LM(s[i]))
                {
                    int nr = s[i] + n;
                    if(nr > 'Z')
                        s[i] = nr - 'Z' + 'A' - 1;
                    else
                        s[i] = nr;
                }
                else
                {
                    int nr = s[i] + n;
                    if(nr > 'z')
                        s[i] = nr - 'z' + 'a' - 1;
                    else
                        s[i] = nr;
                }
            }
            i++;
        }
        fout << s;
    }
    else
    {
        int i = 0;
        while(s[i])
        {
            if(LM(s[i]) || lm(s[i]))
            {
                if(LM(s[i]))
                {
                    s[i] = s[i] - n;
                    if(s[i] < 'A')
                        s[i] += 'Z' - 'A' + 1;
                }
                else
                {
                    s[i] = s[i] - n;
                    if(s[i] < 'a')
                        s[i] += 'z' - 'a' + 1;
                }
            }
            i++;
        }
        fout << s;
    }
    return 0;
}
