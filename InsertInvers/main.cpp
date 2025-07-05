#include <iostream>
#include <cstring>

using namespace std;

char s[256], *cuv, temp[50];
short m, i;

int main()
{
    cin.getline(s, 256);
    cuv = strtok(s, " ");
    while (cuv) {
        cout << cuv << " ";
        m = strlen(cuv);
        for (i = 0; i < m; ++i)
            temp[i] = cuv[m - i - 1];
        temp[m] = 0;
        cout << temp << " ";
        cuv = strtok(0, " ");
    }
    return 0;
}
