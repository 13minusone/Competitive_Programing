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

const int N = 5e5 + 5;
//const int MOD = 1e9+7;
//const int base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;

int par[N], n, m, q, a[N], mark[N], cnt = 0, sta[N], fin[N], ans[N];
ii edge[N], st[4 * N];
vector<ii>query;
vector<int>adj[N];
int root(int u)
{
    return (par[u] < 0 ? u : (par[u] = root(par[u])));
}
bool join(int u, int v)
{
    if( (u = root(u)) == (v = root(v)))return false;
    if(-par[u] < -par[v])swap(u, v);
    par[u] += par[v];
    par[v] = u;
    adj[u].pb(v);
    return true;
}
void dfs(int u, int pre)
{
    sta[u] = ++cnt;
    for(int v : adj[u])
        dfs(v,u);
    fin[u] = cnt;
}
void upd(int pos, int val, int id = 1, int l = 1, int r = cnt)
{
    if(l == r){
        st[id] = ii(val, l);
        return ;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid)upd(pos, val, id << 1, l, mid);
    else upd(pos, val, id << 1|1, mid + 1, r);
    st[id] = max(st[id << 1], st[id << 1|1]);
}
ii getmax(int u, int v, int id = 1, int l = 1, int r = cnt)
{
    if(l > v || r < u || l > r || u > v)return ii(0,0);
    if(l >= u && r <= v)return st[id];
    int mid = (l+r) >> 1;
    return max(getmax(u, v, id << 1, l, mid), getmax(u, v, id << 1|1, mid + 1, r));
}
void init(void)
{
     cin >> n >> m >> q;
        memset(par,-1,sizeof par);
        FOR(i,1,n)
            cin >> a[i];
        FOR(i,1,m)
            cin >> edge[i].fi >> edge[i].se;
        FOR(i,1,q)
        {
            register int t, x;
            cin >> t >> x;
            if(t == 2)mark[x] = 1;
            query.pb(ii(t,x));
        }
        FOR(i,1,m)
            if(!mark[i] )
                join(edge[i].fi, edge[i].se);
        reverse(all(query));
}
void process(void)
{
    int extra = n + 1, k = q;
        for(ii i : query)
        {
            if(i.fi == 2){
                int u = root(edge[i.se].fi);
                int v = root(edge[i.se].se);
                if(u != v){
                par[extra] += (par[u] + par[v]);
                par[u] = par[v] =extra;
                adj[extra].pb(u);
                adj[extra].pb(v);
                extra++;
            }
            }
            else
                ans[k] = root(i.se);
            k--;
        }
        FOR(i,1,extra)
            if(root(i) == i)dfs(i,-1);
        FOR(i,1,n)upd(sta[i], a[i]);
        FOR(i,1,q)
        {
            if(ans[i] != 0){
                ii que = getmax(sta[ans[i]], fin[ans[i]]);
                cout << que.fi << endl;
                if(que.fi != 0);
                    upd(que.se, 0);
            }
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
