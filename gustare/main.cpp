#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin ("gustare.in") ;
ofstream cout ("gustare.out") ;

int corn[500002], apples[500002] ;

int main()
{
    int n, m, q, idx1, idx2, x, meal ;
    bool found ;
    cin >> n ;
    for (int i = 1 ; i <= n ; i ++)
        cin >> corn[i] ;
    cin >> m ;
    for (int i = 1 ; i <= m ; i ++)
        cin >> apples[i] ;
    sort (corn + 1, corn + n + 1) ;
    sort (apples + 1, apples + m + 1) ;
    cin >> q ;
    idx2 = m ;
    for (int qq = 1 ; qq <= q ; qq ++)
    {
        cin >> x ;
        idx1 = 1 ;
        idx2 = m ;
        found = false ;
        while (!found && idx2 > 0 && idx1 <= n)
        {
            meal = corn[idx1] + apples[idx2] ;
            if (meal > x)
                idx2 -- ;
            if (meal < x)
                    idx1 ++ ;
            else if (meal == x)
                found = true ;
        }
        if (found)
            cout << "DA" << '\n' ;
        else
            cout << "NU" << '\n' ;
    }
    return 0 ;
}