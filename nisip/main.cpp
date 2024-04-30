// Autor: Patcas Csaba
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

#define LL long long
#define VI vector<int>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)

#define IN_FILE "nisip.in"
#define OUT_FILE "nisip.out"

int n, m, headRock;
VI rocks, prevRock, nextRock, sand, rockInd, firstRock, removeTime;

void read()
{
    cin >> n >> m;
    rockInd.resize(n + 1);
    int s = 0;
    FOR(i, 1, n)
    {
        char ch;
        cin >> ch;
        s += ch == '1';
        if (ch == '2')
        {
            rocks.push_back(i);
            sand.push_back(s);
            rockInd[i] = rocks.size() - 1;
            firstRock.push_back(rocks.size() - 1);
            s = 0;
        }
        else
            rockInd[i] = rocks.size();
    }
}

void initPointers()
{
    nextRock.resize(rocks.size());
    prevRock.resize(rocks.size());
    removeTime.resize(rocks.size());
    nextRock[0] = 1;
    prevRock[0] = -1;
    nextRock.back() = -1;
    prevRock.back() = rocks.size() - 2;
    FOR(i, 1, rocks.size() - 2)
    {
        nextRock[i] = i + 1;
        prevRock[i] = i - 1;
    }
    headRock = 0;
}

void removeRock(int ri, int t)
{
    if (nextRock[ri] != -1)
        prevRock[nextRock[ri]] = prevRock[ri];
    if (prevRock[ri] != -1)
        nextRock[prevRock[ri]] = nextRock[ri];
    else
        headRock = nextRock[ri];
    firstRock[ri] = firstRock[firstRock[nextRock[ri]]];
    removeTime[ri] = t;
}

void moveSand(int ri)
{
    sand[nextRock[ri]] += sand[ri];
    sand[ri] = 0;
}

int findFirstRock(int ind)
{
    int ri = rockInd[ind];
    while (removeTime[ri])
    {
        ri = firstRock[ri];
    }
    int i = rockInd[ind];
    while (i != ri)
    {
        int next = firstRock[i];
        firstRock[i] = ri;
        i = next;
    }
    return ri;
}

int getStable(int ind, int firstRockIndex)
{
    if (ind == rocks[firstRockIndex])
        return 2;
    else if (rocks[firstRockIndex] - ind <= sand[firstRockIndex])
        return 1;
    else
        return 0;
}

int getStart(int ind, int firstRockIndex, int removedIndex)
{
    if (ind == rocks[firstRockIndex] || ind == rocks[firstRockIndex])
        return 2;
    else if (ind > rocks[removedIndex] && rocks[firstRockIndex] - ind <= sand[firstRockIndex] || ind < rocks[removedIndex] && rocks[removedIndex] - ind <= sand[removedIndex])
        return 1;
    else
        return 0;
}

int getMovingBlock(int ind, int firstRockIndex, int removedIndex, int dt)
{
    if (dt == 0)
        return getStart(ind, firstRockIndex, removedIndex);
    if (dt == 1)
        if (ind == rocks[removedIndex])
            return 0;
        else
            return getStart(ind, firstRockIndex, removedIndex);
    if (ind == rocks[firstRockIndex])
        return 2;
    if (rocks[firstRockIndex] - ind <= sand[firstRockIndex])
        return 1;
    if (ind < rocks[removedIndex] - sand[removedIndex])
        return 0;
    int col = ind - (rocks[removedIndex] - sand[removedIndex]) + 1;
    int sandToMove = sand[removedIndex];
    int distanceToMove = rocks[firstRockIndex] - sand[firstRockIndex] - rocks[removedIndex];
    int openTime = sandToMove;
    int travelTime = distanceToMove - (sandToMove - 1);
    int closeTime = sandToMove - 1;
    if (travelTime > 0)
    {
        if (dt <= openTime)
        {
            if (col <= sandToMove - dt + 1)
                return 1;
            if (col > sandToMove + dt - 1)
                return 0;
            return (col + dt - sandToMove) & 1;
        }
        if (dt <= openTime + travelTime)
        {
            if (col < dt - openTime)
                return 0;
            if (col > dt - openTime + sandToMove * 2 - 1)
                return 0;
            return (col + dt - sandToMove) & 1;
        }
        if (col <= min(dt - openTime, distanceToMove))
            return 0;
        if (dt - openTime - travelTime >=
            sandToMove + distanceToMove - col)
            return 1;
        return (col + dt - sandToMove) & 1;
    }
    else
    {
        if (dt <= openTime)
        {
            if (col <= sandToMove - dt + 1)
                return 1;
            if (col > sandToMove + dt - 1)
                return 0;
        }
        if (dt >= sandToMove + distanceToMove - closeTime)
        {
            if (col <= min(dt - openTime, distanceToMove))
                return 0;
            if (dt - (sandToMove + distanceToMove - closeTime) >=
                sandToMove + distanceToMove - col)
                return 1;
        }
        return (col + dt - sandToMove) & 1;
    }
}

void solve()
{
    int lastRemoved = -1;
    int z = 0;
    FOR(q, 1, m)
    {
        int c, t, ind;
        cin >> c >> t >> ind;
        if (c == 1)
        {
            if (lastRemoved != -1)
                moveSand(lastRemoved);
            lastRemoved = rockInd[ind];
            removeRock(lastRemoved, t);
        }
        else
        {
            ++z;
            int ri = findFirstRock(ind);
            if (lastRemoved < prevRock[ri] || lastRemoved > ri)
            {
                cout << getStable(ind, ri) << "\n";
                continue;
            }
            int dt = t - removeTime[lastRemoved];
            cout << getMovingBlock(ind, ri, lastRemoved, dt) << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen(IN_FILE, "r", stdin);
    freopen(OUT_FILE, "w", stdout);
    read();
    initPointers();
    solve();
    return 0;
}