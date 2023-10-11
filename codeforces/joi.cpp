// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "akarui"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define endl '\n'
#define fi first
#define se second
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FD(i,l,r) for(int i = l ; i >= r ; i--)
#define REP(i,l,r) for(int i = l ; i <r ; i++)

typedef long long ll ;
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 3e6 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;
int n, l, a[N];
ll dp[101][101][1001][3];
/*
    dp[i][j][c][t]
     -- i : at a[i]
     -- j : have j components
     -- c : costs
     -- t : 2 sides
    EXAMPLE :
a[]= 1, 3, 4, 7, 9, 10, 11, 12, 15
    [x, x, x, x, x, x , x , x , x]
    [x, x, x, x, 1, x , x , x , x] = 4
    [3, x, x, x, 1, x , x , x , x] = 7
    [3, 4, x, x, 1, x , x , x , x] = 16
    [3, 4, x, x, 1, 7 , x , x , x] =
    Diff  = a[i+1] - a[i];
    Diffback = a[i] -  a[i-1]
    CASE 1 : create a new component
    1) add 2 side
        dp[i][j+1][c + (2 * j - t + 1) * diff][t+1] += dp[i][j][c][t]*(2-t)
    2) add  mid
        dp[i][j+1][c + (2 * j - t + 2) * diff][t] += (dp[i][j][c][t] + 1)
    CASE 2 : KEEP STABLE COMPONENT
    1) add 2 side
        dp[i][j][c + (2*j - t) * diff - diffback][t] += dp[i][j][[c][t] * t;
    2) add mid
        dp[i][j][c +


*/
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> l;
    FOR(i,1,n)
        FOR(j,1,i)
}

