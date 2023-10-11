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

const int N = 1e6 + 5;
//const int MOD = 1e9+7;
//const int base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int q, hi[N], par[N][20], LOG = 19, ans1, ans2, ans;
void init(void)
{
    cin >> q;
}
int dist(int x, int y)
{
    int dist1 = hi[x] + hi[y];
    if(hi[x] < hi[y])swap(x, y);
    FD(i,LOG,0)
        if(hi[par[x][i]] >= hi[y]){
            x = par[x][i];
        }
    if(x == y)return ( dist1 - 2 * hi[x]);
    FD(i,LOG, 0)if(par[x][i] != par[y][i])
    {
        x = par[x][i];
        y = par[y][i];
    }
    return (dist1 - 2 * hi[par[x][0]]);
}
void addEdge(int u, int v)
{
    par[v][0] = u;
    hi[v] = hi[u] + 1;
    FOR(i,1,LOG)par[v][i] = par[ par[v][i - 1] ][i - 1];
    int res1 = dist(v, ans1), res2 = dist(v,ans2);
    if(res1 > ans && res1 > res2){
        ans2 = v;
        ans = res1;
    }
    else if(res2 > ans){
        ans1 = v;
        ans = res2;
    }
    return;
}
void process(void)
{
    ans1 = ans2 = 1;
    ans = 0;
    addEdge(1,2);
    addEdge(1,3);
    addEdge(1,4);
    int n = 5,x;
    while(q--)
    {
        scanf("%d",&x);
        LOG = log2(n);
        addEdge(x, n++);
        LOG = log2(n);
        addEdge(x, n++);
       // cout << ans1 << " " << ans2 << endl;
        printf("%d\n",ans);
    }
}
signed main()
{
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
