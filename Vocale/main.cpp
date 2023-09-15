#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[21], v[] = "aeiou";
    cin >> a;
    for (int i = 0; i < strlen(a); ++i)
        if (strchr(v, a[i]) != 0)
            a[i] = a[i] - 32;
    cout << a;
    return 0;
}
