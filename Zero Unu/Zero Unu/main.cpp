#include <iostream>
#include <string>

using namespace std;

int main() {
    char x[11];
    int ok1 = 0, ok0 = 0;
    cin >> x;
    for (int i = 0; i < strlen(x); ++i) {
        if (x[i] != '0' && x[i] != '1') {
            cout << "nu";
              return 0;
        }
        else {
            if (x[i] == '0')
                ok0 = 1;
            if (x[i] == '1')
                ok1 = 1;
        }
    }
      if (ok1 == ok0 == 1)
        cout << "da";
    else
        cout << "nu";
    return 0;
}
