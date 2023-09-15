#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int SC(char s[]) {
    int suma = 0;
    for (int i = 0; i < strlen(s); ++i)
        if (s[i] >= '0' && s[i] <= '9')
            suma = suma + s[i] - 48;
    return suma;
}

int main()
{
    char s[205];
    istream& getline (char* s, streamsize 205);
    cout << SC(s);
    return 0;
}
