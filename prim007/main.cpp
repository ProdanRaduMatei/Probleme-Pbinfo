#include <iostream> 
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm> 
#include <cstring>

using namespace std;

string NumeFisier = "date";

ifstream fin(NumeFisier + ".in");
ofstream fout(NumeFisier + ".out");

typedef unsigned long long int ull;

const int len = 20002;
ull frecvNumere[len + 1];
bool ciur[len + 1] = { 0 };

void CIUR() {
	for (int i = 2; i <= len; i++)
		ciur[i] = 1;
	for (int i = 2; i * i <= len; i++)
		if (ciur[i])
			for (int j = i * i; j <= len; j += i)
				ciur[j] = 0;
}

int main() {
    std::ios::sync_with_stdio(false);
	CIUR();
	int n, var;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> var;
		frecvNumere[var]++;
	}
    ull contor = 0;
	contor += frecvNumere[1] * (frecvNumere[1] - 1) / 2;
	contor += frecvNumere[0] * frecvNumere[2];
	for (int i = 1; i <= len / 2; i += 2)
		if (frecvNumere[i])
			for (int j = 0; j <= len / 2; j += 2)
				if (frecvNumere[j])
					if (ciur[i + j])
						contor += frecvNumere[i] * frecvNumere[j];
	cout << contor;
}