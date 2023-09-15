#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char s[256], v[] = "aeiou", c[] = "bcdfghjklmnpqrstvwxyz";
	cin.getline(s, 256);
	int i, nr = 0;
	for (i = 1; i < strlen(s) - 1; i++)
		if(strchr(v, s[i]) && strchr(c, s[i-1]) && strchr(c, s[i+1]))
			nr++;
	cout << nr;
	return 0;
}
