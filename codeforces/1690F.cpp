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

const int N = 1e6 + 1;
//const ll MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
int n, m;
struct DSU
{
    vector<int>par;
    stack<ii>Back;
    void init(int n)
    {
        par.assign(n + 1, -1);
        while(!Back.empty())Back.pop();
    }
    int root(int u){
        return (par[u] < 0 ? u : root(par[u]));
    }
    void join(int u, int v)
    {
        if((u = root(u)) == (v = root(v)))
            return;
        if(par[u] > par[v])swap(u ,v);
         Back.push(ii(u, par[u]));
        Back.push(ii(v, par[v]));
        par[u] += par[v];
        par[v] = u;
    }
    int getSize(int u)
    {
        return -par[root(u)];
    }
    int getST()
    {
        return SZ(Back);
    }
    void rollback(int op)
    {
        while(Back.size() > op)
        {
            ii x = Back.top();
            par[x.fi] = x.se;
            Back.pop();
        }
    }
}tree;
vector<ii>st[4 * N];
int query[N];
bool Haveans = false, vis[3 * N];
ii e[N];
void ans(int id)
{
    if(Haveans)return;
    Haveans = 1;
    FOR(i,0,2 * n)vis[i] = false;
    if(id){
        vis[tree.root(e[id].fi)] = vis[tree.root(e[id].se)] = 1;
    }
   // cout << id << endl;
    cout << "YES" << endl;
    FOR(i,1,n)
    {
        int x = tree.root(i), y = tree.root(i + n);
        if(vis[x])cout << 1;
        else{
            if(vis[y])cout << 0;
            else{
                cout << 1;
                vis[x] = 1;
            }
        }
    }
    cout << endl;
}
void add(int u, int v, ii val, int id = 1, int l = 1, int r = m)
{
    if(l > r || u > v || l > v || r < u)return;
    if(l >= u && r <= v){
        st[id].pb(val);
        return;
    }
    int mid = (l+r) >> 1;
    add(u, v, val, id << 1, l, mid);
    add(u, v, val, id << 1|1, mid + 1, r);
}
void DnC(int id = 1, int l = 1, int r = m, bool ok = 1)
{
    int sz = tree.getST();
    for(ii i : st[id])
    {
        if(tree.root(i.fi) == tree.root(i.se))ok = false;
        tree.join(i.fi, i.se + n), tree.join(i.se, i.fi + n);
    }
    if(l == r)
    {
        if(ok){
            ans(l);
        }
    }
    int mid = (l+r) >> 1;
    if(l < r && !Haveans)DnC(id << 1, l, mid,ok);
    if(l < r && !Haveans)DnC(id << 1|1, mid + 1, r,ok);
    tree.rollback(sz);
}
void init(void)
{
    cin >> n >> m;
}
void process(void)
{
    tree.init(n * 2+ 10);
    REP(i,0,4 * m)st[i].clear();
    Haveans = false;
   // cout << n << " " << m << endl;
    FOR(i,1,m)
    {
        cin >> e[i].fi >> e[i].se;
        tree.join(e[i].fi, e[i].se + n);
        tree.join(e[i].fi + n, e[i].se);
        add(1,i-1,e[i]);
        add(i + 1,m,e[i]);
    }
    bool ok = true;
    FOR(i,1,m)
        if(tree.root(e[i].fi) == tree.root(e[i].se))ok = false;
    if(ok)ans(0);
    else{
        tree.init(n * 2 + 10);
        DnC();
    }
    if(!Haveans)cout << "NO" << endl;
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
    cin >> t;
    while(t--)
    {
        init();
        process();
    }

}

