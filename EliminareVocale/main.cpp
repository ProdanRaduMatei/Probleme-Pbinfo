#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[21];
    cin >> a;
    for (int i = 0; a[i]; ++i)
        if(!strchr("aeiouAEIOU", a[i]))
            cout << a[i];
    return 0;
}
