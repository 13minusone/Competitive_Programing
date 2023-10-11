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
//const ll MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
int n, m, k, c[N], u[N], v[N];
ll ans = 0;
bool bad[N];
struct DSU
{
    vector<int>par;
    stack<ii>Back;
    void init(int n)
    {
        par.assign(n + 1, -1);
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
    int Currentstack()
    {
        while(!Back.empty())Back.pop();
    }
    void rollback()
    {
        while(!Back.empty())
        {
            ii x = Back.top();
            par[x.fi] = x.se;
            Back.pop();
        }
    }
}tree;
map<ii,vector<int>>mp;
void init(void)
{
    cin >> n >> m >> k;
    FOR(i,1,n)
        cin >> c[i];
    tree.init(2  * n);
    FOR(i,1,m)
    {
        cin >> u[i] >> v[i];
        if(c[u[i]] == c[v[i]]){
            tree.join(u[i], v[i] + n);
            tree.join(v[i], u[i] + n);
        }
        else {
            if(c[u[i]] > c[v[i]])swap(u[i], v[i]);
            mp[ii(c[u[i]], c[v[i]])].pb(i);
        }
    }

    FOR(i,1,n)
        if(tree.root(i) == tree.root(i + n))bad[c[i]] = 1;
    int co = 0;
    FOR(i,1,k)
        co += 1 - bad[i];
    ans = 1LL * co * (co - 1)/2;
}
void process(void)
{
   // cout << ans << endl;
   tree.Currentstack();
    for(auto x : mp)
    {
        if(bad[x.fi.fi] || bad[x.fi.se])continue;
        vector<int>node;
        for(auto p : x.se)
        {
          //  cout << v[p] << " " << u[p] << endl;
//            cout << u[p] << " " << v[p] + n << endl;
            tree.join(v[p], u[p] + n);
            tree.join(u[p], v[p] + n);
            node.pb(u[p]);
            node.pb(v[p]);
        }
        bool ok = false;
        for(int i : node)if(tree.root(i) == tree.root(i + n)){
            //cout << i << " " << tree.root(i) << " " << tree.root(i + n) << endl;
            ok = 1;
            break;
        }
       // cout << x.fi.fi << " " << x.fi.se << " " << ok << endl;
        ans -= ok;
        tree.rollback();
    }
    cout << ans;
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

