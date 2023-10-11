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

const int N = 1e3 + 5;
const int INF =1e9+9;
//const ll base = 311;
//const int BLOCK = 488;

int par[N], n, m, q, minn[N][15], cha[N][15], LOG = 12,num[N], numComp = 0, hi[N];
struct Data
{
    int x, y, w;
    Data(int _x = 0, int _y = 0, int _w = 0)
    {
        x = _x;
        y = _y;
        w = _w;
    }
};
struct que
{
    char type;
    int u, v,w;
};
que query[1000005];
Data edge[100005];
vector<int>vec, mst_id;
vector<ii>adj[N];
int root(int u)
{
    return (par[u] < 0 ? u : par[u] = root(par[u]));
}
bool d[1000005];
bool join(int u, int v)
{
    if((u = root(u)) == ( v = root(v)))return false;
    if(-par[u] < - par[v])swap(u,v);
    par[u] += par[v];
    par[v] = u;
    return true;
}
void dfs(int u, int pre)
{
    num[u] = numComp;
    FOR(i,1,LOG){
        cha[u][i] = cha[cha[u][i-1]][i-1];
        minn[u][i] = min(minn[cha[u][i-1]][i-1], minn[u][i-1]);
    }
    for(ii v : adj[u])if(v.fi != pre)
    {
        hi[v.fi] = hi[u] + 1;
        cha[v.fi][0] = u;
        minn[v.fi][0] = v.se;
        dfs(v.fi, u);
    }
}
int getLca(int u, int v)
{
    int minl=INF;
    if(hi[u]<hi[v])swap(u,v);
    for(int i = LOG; i >= 0; i--)
    {
        if(hi[cha[u][i]]>=hi[v])
        {
            minl=min(minl,minn[u][i]);
            u=cha[u][i];

        }
    }
    if(u == v)
    {
        return minl;
    }
    for(int i = LOG; i >= 0 ; i--)
    {
        if(cha[u][i] != cha[v][i])
        {
            minl=min(minl,min(minn[u][i],minn[v][i]));
            u=cha[u][i];
            v=cha[v][i];
        }
    }
    minl=min(minl,min(minn[u][0],minn[v][0]));
    return minl;
}
void build()
{
    memset(par, -1, sizeof par);
    numComp = 0;
    FOR(i,1,n){
        adj[i].clear();
         FOR(j,0, LOG){
             minn[i][j] = INF;
             cha[i][j] = 0;
         }
        num[i] = 0;
        hi[i] = 0;
    }
    sort(all(mst_id),[&](int u, int v){return edge[u].w > edge[v].w;});
    for(int i : mst_id)
    {
        //cout << i << endl;
        if(join(edge[i].x, edge[i].y))
        {
           // cout << i << endl;
            adj[edge[i].x].pb(ii(edge[i].y, edge[i].w));
            adj[edge[i].y].pb(ii(edge[i].x, edge[i].w));
        }
    }
    FOR(i,1,n)
        if(!num[i])
        {
            hi[i] = 1;
            numComp++;
            dfs(i,i);
        }
}
bool check(int u, int v, int w)
{
    //cout << num[u] << " " << num[v]  << " " << getLca(u,v) << endl;
    if(num[u] != num[v] || getLca(u,v) < w)return false;
    else return true;
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
        cin >> n >> m >> q;
        FOR(i,1,m)
        {
            int x, y, w;
            cin >> x >> y >> w;
            edge[i] = Data(x,y,w);
        }
        memset(par,-1,sizeof par);
        FOR(i,1,q)
        {
            cin >> query[i].type;
            if(query[i].type == 'S'){
                cin >> query[i].u >> query[i].v >> query[i].w;
            }
            else {
                cin >> query[i].u >> query[i].w;
                d[query[i].u] = 1;
                mst_id.pb(query[i].u);
            }
        }
        memset(minn,-1,sizeof minn);
        FOR(i,1,m)
            if(!d[i])
                vec.pb(i);
        sort(all(vec),[&](int u, int v){return edge[u].w > edge[v].w;});
        for(int i : vec)
        {
            int u = edge[i].x;
            int v = edge[i].y;
            if((u = root(u)) == (v = root(v)))continue;
            mst_id.pb(i);
            if(-par[u] < -par[v])swap(u,v);
            par[u] += par[v];
            par[v] = u;
        }
        build();
        FOR(i,1,q)
        {
            if(query[i].type == 'S')
            {
                if(!check(query[i].u, query[i].v, query[i].w))
                    cout << "NO" << endl;
                else cout << "YES" << endl;
            }
            else {
                edge[query[i].u].w = query[i].w;
                build();
            }
        }
    }

}

