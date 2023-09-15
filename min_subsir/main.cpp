#include <iostream>
using namespace std;

int a[30];

int main()
{
    string s;
    cin >> s;
    unsigned int nrlitdif=0,i,j=0,Min=s.size(),k=0;
    for (i = 0; i<s.size(); i++)
        if (!a[s[i]-'a'])
        {
            a[s[i]-'a'] = -1;
            nrlitdif++;
        }
    for (i = 0; i<s.size();)
    {
        a[s[i]-'a']++;
        if (!a[s[i]-'a'])
            k++;
        if (k == nrlitdif)
        {
            while (a[s[j]-'a']!=0)
            {
                a[s[j]-'a']--;
                j++;
            }
            Min = min(Min,i-j+1);
        }
        i++;
    }
    cout << Min;
}
