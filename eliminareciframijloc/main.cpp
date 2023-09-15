#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char n[18];
    int l;
    cin >> n;
    l = strlen(n) - 1;
    l = l / 2;
    strcpy(n + l, n + l + 1);
    cout << n;
    return 0;
}
