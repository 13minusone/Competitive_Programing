// Onegai no bug
// Author : 13minusone
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

const int N = 20 + 5;
const int INF =1e9+9;
//const ll base = 311;
//const int BLOCK = 488;

int n, k;
int c[N][N], d[(1 << 20) + 5];
int solve(int mask)
{
    if(__builtin_popcount(mask) == k)return 0;
    int ans = INF;
    if(d[mask] != -1)return d[mask];
    FOR(i,0,n-1)
        if(getbit(mask,i) == 1)
            FOR(j,0,n-1)
                if(i != j && getbit(mask, j) == 1)
                    minimize(ans, solve(mask ^ (1 << i)) + c[i + 1][j + 1]);
   // cout << mask << " " << ans << endl;
   d[mask] = ans;

    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t = 1;
    //cin >> t;
    while(t--)
    {
        cin >> n >> k;
        FOR(i,1,n)
            FOR(j,1,n)
                cin >> c[i][j];
//        cout <<(3 ^ 1) << endl;
        memset(d,-1,sizeof d);
        cout << solve((1 << n)-1);
        cerr  << "\n Time : " << clock()  << " ms" << endl;
    }

}

