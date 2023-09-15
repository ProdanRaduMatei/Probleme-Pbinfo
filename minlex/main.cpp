#include <iostream>
#include <cstring>
using namespace std;
char s[1000001];
int k , vf , elim , st[1000001];
int main()
{
    cin >> k;
    cin.get();
    cin.getline(s , 1000000);
    int n = strlen(s);
    int i = 0;
    while(i < n) {
        if(vf == 0) {
            vf ++;
            st[vf] = int(s[i] - 'a' + 1);
        }
        else {
            while(st[vf] > int(s[i] - 'a' + 1) && elim < k && vf) {
                elim ++;
                vf --;
            }
            vf ++;
            st[vf] = int(s[i] - 'a' + 1);
        }
        i++;
    }
    for(int i = 1 ; i <= n - k ; i ++)
        cout << char(st[i] - 1 + 'a');
    return 0;
}
