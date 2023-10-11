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
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e6 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int block = 488;

int n, q, head[N], sz[N], chainid[N], nchain = 1, hi[N],par[N][22], sta[N], fin[N], cnt = 0, Log = 20;
vector<ii>adj[N];
struct tree
{
    struct node{
        vector<int>a;
        int nx[2], cnt;
        node(){
            cnt = nx[0] = nx[1]=  0;
        }
    };
    vector<node> trie;
    tree() { trie.pb(node()); }
    vector<int>a;
    void upd(int x,int id)
    {
        int cur = 0;
        FD(i,21,0)
        {
            int  k = getbit(x,i);
            if(!trie[cur].nx[k]){
                    trie[cur].nx[k] = SZ(trie);
                    trie.pb(node());
            }
            cur = trie[cur].nx[k];
            trie[cur].a.pb(id);
        }
    }
    int get(int d,int l,int r)
    {
        if(l > r)return 0;
        int cur = 0, ans =0;
        FD(i,21,0)
        {
            int cur1 = trie[cur].nx[1];
            int cur0 = trie[cur].nx[0];
            int k = 0;
            int bitd = getbit(d,i);
            if(bitd && cur0)k = upper_bound(all(trie[cur0].a),r)-lower_bound(all(trie[cur0].a),l);
            if(!bitd && cur1) k = upper_bound(all(trie[cur1].a),r)-lower_bound(all(trie[cur1].a),l);
            if(!bitd)
            {
                if(k){
                    ans += (1 << i);
                    cur = cur1;
                }
                else if(cur0)cur = cur0;
                else return ans;
            }
            else
            {
                if(k){
                    ans += (1 << i);
                    cur = cur0;
                }
                else if(cur1)cur = cur1;
                else return ans;
            }
        }
    return ans;
    }
};
void dfs(int u,int pre)
{
    sz[u] = 1;
    FOR(i,1,Log)
        par[u][i] = par[ par[u][i-1]][i-1];
    for(ii v : adj[u])if(v.fi != pre)
    {
        par[v.fi][0] = u;
        hi[v.fi] = hi[u] + 1;
        dfs(v.fi, u);
        sz[u] += sz[v.fi];
    }
    return;
}
int lca(int u,int v)
{
    if(hi[u]<hi[v])swap(u,v);
    for(int i = Log; i>=0; i--)
    {
        if(hi[par[u][i]]>=hi[v])
            u=par[u][i];
    }
    if(u==v)return u;
    for(int i = Log ; i >= 0 ; i--)
    {
        if(par[u][i]!=par[v][i]){
            v=par[v][i];
            u=par[u][i];
        }
    }
    return par[u][0];
}
tree trie[N];
void hld(int u,int pre,int w)
{
    if(!head[nchain]) head[nchain] = u;
    chainid[u] = nchain;
    trie[chainid[u]].upd(w,hi[u]);
    int Bigchild = -1;
    int weight = 0;
    for(ii v : adj[u]) if(v.fi != pre )
    {
        if(Bigchild == -1 || sz[v.fi] > sz[Bigchild])
        {
            Bigchild = v.fi;
            weight = v.se;
        }
    }
    if(Bigchild != -1)
    {
        hld(Bigchild,u,weight);
    }
    for(ii v : adj[u])if(v.fi != pre && v.fi != Bigchild)
    {
        nchain++;
        hld(v.fi,u,v.se);
    }
}
int getx(int u, int v, int x)
{
    if(u == v)return 0;
    int maxx = 0;
    while(chainid[u] != chainid[v])
    {
        maxx = max(maxx, trie[chainid[u]].get(x,hi[head[chainid[u]]],hi[u]));
        u = par[head[chainid[u]]][0];
    }
    maxx=max(maxx, trie[chainid[u]].get(x, hi[v]+1, hi[u]));
    return maxx;
}
int ans(int u,int v,int x)
{
    int k = lca(u,v);
    int maxx1 = getx(u, k,x);
    int maxx2 = getx(v, k,x);
    return max(maxx1, maxx2);
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
    cin >> n >> q;
    //FOR(i,1,n)trie[i] = tree();
    REP(i,1,n)
    {
        register int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb(ii(v,w));
        adj[v].pb(ii(u,w));
    }
    hi[1] = 1;
    dfs(1,-1);
    //hld(1,-1,0);
    while(q--)
    {
        register int u, v, x;
        cin >> u >> v >> x;
        //cout << ans(u, v, x) << endl;
    }
}
