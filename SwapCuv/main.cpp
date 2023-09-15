#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[100];
    gets(s);
    bool flag = false;
    for (int i = 0; i < strlen(s); ++i)
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
            printf("%c", s[i]);
            flag = true;
        }
        else {
            if (flag == true)
                printf("\n");
            flag = false;
        }
    return 0;
}
