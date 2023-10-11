// Author : Nyanpasuuuuu
#include<bits/stdc++.h>
using namespace std;
#define task "test"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define fi first
#define se second
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FD(i,l,r) for(int i = l ; i >= r ; i--)
#define REP(i,l,r) for(int i = l ; i <r ; i++)

typedef long long ll ;
typedef pair<ll,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 3e5 + 5;
//const ll MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
int n, k, l[N], r[N], pre[N];
int dp[101][N][2];
void init(voi;d)
{
    cin >> n >> k;
    FOR(i,1,k)
    {
        cin >> l[i] >> r[i];
    }
}
/*
    dp[i][j][x] = using period i and have passed j seconds in side x
    dp[i][j][x] = min(dp[i - 1][j - 1][x], dp[i - 1][i - j][1 - x] + 1 : INF);
*/
void process(void)
{
    FOR(i,1,k)
        FOR(i,1,n)
            FOR(x,0,1)
            {

            }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t = 1;
    //cin >> t;
    while(t--)
    {
        init();
        process();
    }

}
