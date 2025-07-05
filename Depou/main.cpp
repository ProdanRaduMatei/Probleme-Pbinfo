#include <bits/stdc++.h>
using namespace std;
stack<int> a , b;
int main() {
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; ++i) {
        int x;
        cin >> x;
        a.push(x);
    }
    int cnt = 1;
    int rez[10001] , p=1;
    while(!a.empty() || !b.empty()) {
        if(!b.empty() && b.top()==cnt)
            b.pop() , cnt++ , rez[p]=2 , rez[p+1]=3 , p+=2;
        else {
            while(!a.empty() && a.top()!=cnt) {
                if(!b.empty() && a.top()>= b.top())
                    break;
                b.push(a.top()) , a.pop();
                rez[p]=1 , rez[p+1]=2 , p+=2;
            }
            if(a.top()!=cnt)
                break;
            else
                rez[p]=1 , rez[p+1]=3 , p+=2 , a.pop() , cnt++;
        }
    }
    if(cnt < n)
        cout << 0;
    else {
        cout << (p-1)/2 << endl;
        for(int i = 1 ; i < p ; ++i) {
            if(rez[i]==1)
                cout << "A ";
            if(rez[i]==2)
                cout << "B ";
            if(rez[i]==3)
                cout << "C ";
            if(i % 2 == 0)
                cout << '\n';
        }
    }
    return 0;
}
