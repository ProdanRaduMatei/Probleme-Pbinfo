#include <bits/stdc++.h>
using namespace std;
int n,m,x,maxx;
char v[10001];
int v1[10001];
int get(int vec[], int k){
    stack<int> s;
    int maxa = 0, tp, awt, i = 0;
    while (i < k){
        if (s.empty() || vec[s.top()] <= vec[i])
            s.push(i++);
        else {
            tp = s.top();
            s.pop();
            awt = vec[tp] * (s.empty() ? i : i - s.top() - 1);
            if (maxa < awt)
                maxa = awt;
        }
    }
    while (!s.empty()){
        tp = s.top();
        s.pop();
        awt = vec[tp] * (s.empty() ? i : i - s.top() - 1);
        if (maxa < awt)
            maxa = awt;
    }
    return maxa;
}

int main(){
    ifstream in("plaja.in");
    ofstream out("plaja.out");
    in>>n>>m;
    for(int j = 0; j <= n; ++j){
        in.getline(v, 10001);
        for(int i = 0; i < (int)strlen(v); ++i) {
            if((v[i] - '0') == 1)
                v1[i] = 0;
            else if((v[i] - '0') == 0)
                v1[i] += 1;
        }
        x = get(v1, m);
        if(x > maxx)
            maxx = x;
    }
    out<<maxx;
    return 0;
}
