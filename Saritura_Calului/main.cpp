#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>

const int INF = 2147483647;

typedef unsigned long long ull;
typedef std::pair<int,int>pi;
typedef long long ll;
typedef const int ci;

std::ifstream f("saritura_calului1.in");
std::ofstream g("saritura_calului1.out");

int startx,starty,n,m,matrix[105][105],path;
const int dx[] = { 1 , 2 , 2 , 1 , -1 , -2 , -2 , -1 };
const int dy[] = { 2 , 1 , -1 , -2 , -2 , -1 , 1 , 2 };

void Read(){
    f >> n >> m >> startx >> starty;
}

bool isValid(ci& i,ci& j){
    return i >= 1 && j >= 1 && i <= n && j <= m;
}

inline int getDirections(int line,int col){
    int cnt{};
    for(int dir = 0;dir < 8;++dir){
        ci next_line = line + dx[dir];
        ci next_col = col + dy[dir];
        if(isValid(next_line,next_col) && !matrix[next_line][next_col])
            cnt++;
    }
    return cnt;
}

void Solve(int line,int col){
    matrix[line][col] = path + 1;
    bool in{ false };
    int minn{ 9 };
    int sol_line{};
    int sol_col{};
    for(int dir = 0;dir < 8;++dir){
        ci next_line = line + dx[dir];
        ci next_col = col + dy[dir];
        if(!isValid(next_line,next_col) || matrix[next_line][next_col] != 0)
            continue;
        int directions = getDirections(next_line,next_col);
        if(directions < minn){
            minn = directions;
            sol_line = next_line;
            sol_col = next_col;
            in  = true;
        }
    }
    if(in){
        path++;
        Solve(sol_line,sol_col);
    }
}

void Print(){
    for(int i = 1;i <= n;++i,g << '\n')
        for(int j = 1;j <= m;++j)
            g << matrix[i][j] << ' ';
}

int main(){
    Read();
    Solve(startx,starty);
    Print();
    return 0;
}
