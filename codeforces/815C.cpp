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
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 5e3 + 5;
//const int MOD = 1e9+7;
//const int base = 311;
//const int BLOCK = 488;
const int INF = 1e9 + 7;
int n, m, c[N], d[N], f[N][N][2],sz[N];
vector<int>edge[N];
void init(void)
{
    cin >> n >> m;
    FOR(i,1,n)
    {
        cin >> c[i] >> d[i];
        if(i >= 2)
        {
            register int x;
            cin >> x;
            edge[x].pb(i);
        }
    }
}
void process(void)
{
    FOR(i,1,n)
        FOR(j,0,n)
            f[i][j][0] = f[i][j][1] = INF;
    FD(i,n,1)
    {
        f[i][0][0] = 0;
        f[i][1][1] = c[i] - d[i];
        f[i][1][0] = c[i];
        sz[i] = 1;
        for(int v : edge[i])
        {
            FD(j,sz[i],0)
                FD(k,sz[v], 0)
                {
                    minimize(f[i][j + k][0], f[i][j][0] + f[v][k][0]);
                    minimize(f[i][j + k][1], f[i][j][1] + f[v][k][0]);
                    minimize(f[i][j + k][1], f[i][j][1] + f[v][k][1]);
                }
            sz[i] += sz[v];
        }
    }
    FD(i,n,0){
        //cout << i << " " << min(f[1][i][0], f[1][i][1]) << endl;
        if(min(f[1][i][0], f[1][i][1]) <= m)
        {
            cout << i;
            return;
        }
    }
    cout << 0;
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
