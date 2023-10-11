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

const int N = 2e5 + 5;
//const int MOD = 1e9+7;
//const int base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
struct Data
{
    int u, v, w;
    Data(int _u = 0, int _v = 0, int _w = 0)
    {
        u = _u;
        v = _v;
        w = _w;
    }
    bool operator <(const Data &other)const{
    return w < other.w; }
};
vector<Data>edge;
int n, m,Comp = 0, Xorsum = 0;
ll SumMst = 0;
map<int, int>Exist[N];
struct Dsu{
    vector<int>par;
    void init(int _n = 0){
        par.assign(n + 5,-1);
        return;
    }
    int root(int u){
        return (par[u] < 0 ? u : par[u] = root(par[u]));
    }
    bool join(int u, int v){
        if((u = root(u)) == (v = root(v)))return false;
        if(-par[u] < -par[v])swap(u, v);
        par[u] += par[v];
        par[v] = u;
        return true;
    }
}Not_Have, Have;
set<int>s;
void dfs(int u)
{
    if(s.count(u))s.erase(u);
    vector<int>New;
    for(auto i : s)
        if(!Exist[u].count(i) && s.count(i)){
            New.pb(i);
        }
    for(int v : New)s.erase(v), Not_Have.join(u,v);
    for(int v : New)dfs(v);
    return;
}
void init(void)
{
    cin >> n >> m;
    FOR(i,1,m){
        register int x, y, w;
        cin >> x >> y >> w;
        edge.pb(Data(x, y, w));
        Xorsum ^= w;
        Exist[x][y] = 1;
        Exist[y][x] = 1;
    }
}
void process(void)
{
    Have.init(n);
    Not_Have.init(n);
    FOR(i,1,n)s.insert(i);
    FOR(i,1,n)
        if(s.count(i)){
            ++Comp;
            dfs(i);
        }
    sort(all(edge));
    for(Data i : edge)
    {
        if(Not_Have.join(i.u, i.v)){
            SumMst += i.w;
            Have.join(i.u, i.v);
        }
    }
    ll remain = 1LL * n * (n - 1)/2 - m;
    int used = n - Comp;
    if(remain == used)
    {
        int add = Xorsum;
        for(Data i : edge){
            if(Have.join(i.v, i.u)){
                minimize(add,i.w);
                break;
            }
        }
        SumMst += add;
    }
    cout << SumMst << endl;
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
