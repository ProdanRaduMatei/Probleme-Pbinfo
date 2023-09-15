#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char sir[100];
    cin >> sir;
    for (int i = 0; i < strlen(sir); ++i) {
        for (int j = 0; j < i; ++j)
            cout << sir[j];
        for (int j = i + 1; j < strlen(sir); ++j)
            cout << sir[j];
        cout << endl;
    }
    return 0;
}
