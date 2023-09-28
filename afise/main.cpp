#include <fstream>
#include <algorithm>

std::ifstream fin("afise.in");
std::ofstream fout("afise.out");

int l, n ,k, val, nk, i, x, n1, n2, v[1010], v1[1010], v2[1010];

int main()
{
	for (fin >> l >> n >> k, i = 1; i <= n; ++i) {
		fin >> x;
        v[x] = 1;
    }
	i = 1;
	while (i <= l)
		if (!v[i] && !n1)
			++i;
		else
			if (!v[i]) {
				++n2;
				while (!v[i]) {
					++v2[n2];
                    ++i;
                }
			}
		else
			if (v[i] == 1) {
				++n1;
				while (v[i] == 1) {
					++v1[n1];
                    ++i;
                    ++val;
                }
			}
	if (!v[l])
		--n2;
	std::sort(v2 + 1, v2 + n2 + 1);
	if (n1 > k) {
		nk = k;
		for (i = 1; i <= n1 - k; ++i)
			val = val + v2[i];
	}
	else
		nk = n1;
	fout << val << ' ' << nk;
	fin.close();
	fout.close();
}