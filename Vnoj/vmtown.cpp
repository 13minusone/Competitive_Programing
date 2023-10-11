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

const int N = 2e5 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

int n, m, chainHead[N], chainInd[N], posInBase[N], par[N], cnt = 0, hi[N], Child[N];
ii st[4 * N];
vector<int>edge[N];
set<ii>Normal;
void upd(int u, int v, int val, int id = 1, int l = 1, int r = n)
{
    if(l > v || r < u || u > v || l > r)return;
    if(l >= u && r <= v)
    {
        st[id].se+=val;
        if(val == 1)
            st[id].fi=r-l+1;
        else if(st[id].se == 0)
            st[id].fi=st[id << 1].fi+st[id << 1|1].fi;
        return;
    }
    int mid =(l+r) >> 1;
    upd(u, v, val, id << 1, l, mid);
    upd(u, v, val, id << 1|1, mid + 1, r);
    if(st[id].se == 0 )
        st[id].fi=st[id << 1].fi+st[id << 1|1].fi;
}
void dfs(int u, int pre)
{
    Child[u] = 1;
    for(int v : edge[u])if(v != pre)
    {
        dfs(v, u);
        Child[u] += Child[v];
        par[v] = u;
    }
}
void hld(int u) {
    posInBase[u] = ++cnt;
    int mx = -1;
    for (int v : edge[u]) if (v != par[u]&& (mx == -1 || Child[v] > Child[mx])) mx = v;
    if (mx == -1) return;
    chainHead[mx] = chainHead[u];
    hi[mx] = hi[u];
    hld(mx);

    for (int v : edge[u]) if (v != mx && v != par[u]){
        chainHead[v] = v;
        hi[v]= hi[u] + 1;
        hld(v);
    }
}
void update(int u, int a, int val) {
     while(chainHead[u] != chainHead[a])
     {
         if(hi[u] < hi[a])swap(u, a);
         upd(posInBase[chainHead[u]],posInBase[u],val);
         //cout << posInBase[chainHead[u]] << " " << posInBase[u] << " "<< u << endl;
         u = par[chainHead[u]];
     }
     if(posInBase[u] > posInBase[a])swap(u,a);
     upd(posInBase[u] + 1, posInBase[a],val);
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
        cin >> n >> m;
        FOR(i,1,m)
        {
            register int u, v, t;
            cin >> u >> v >> t;
            if(t == 0){
                edge[u].pb(v);
                edge[v].pb(u);
            }
            else {
                if(u > v)swap(u,v);
                Normal.insert(ii(u,v));
            }
        }
        dfs(1,1);
        hld(1);
        int q;
        cin >> q;
        //FOR(i,1,n)cout <<i << " " <<  posInBase[i] << endl;
        for(ii i : Normal){
            update(i.fi, i.se, 1);
        }
        cout << n - 1 - st[1].fi << endl;
        while(q--)
        {
            register int u, v, val;
            cin >> u >> v;
            if(u > v)swap(u,v);
            if(Normal.find(ii(u, v)) != Normal.end()){
                val = -1;
                Normal.erase(ii(u,v));
            }
            else{
                val = 1;
                Normal.insert(ii(u, v));
            }
            update(u, v, val);
            cout << n- 1 - st[1].fi<< endl;
        }
    }

}

