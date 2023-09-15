#include <iostream>
#include <fstream>
using namespace std;
ifstream f("progresie3.in");
ofstream g("progresie3.out");
int main() {
int a,frecv[1001],i;
for (i = 0; i <= 1000; i++)
frecv[i] = 0;
while (f >> a) {
frecv[a] = 1;
}
int r = 0, ultim = -1, ok = 0;
for (i = 0; i <= 1000 && ok == 0; i++) {
if (frecv[i] != 0) {
if (ultim != -1) {
if (r == 0)
r = i - ultim;
else if (i - ultim != r)
ok = 1;
}
ultim = i;
}
}
if (ok == 0)
g<<r;
else
g<<"NU";
return 0;
}
