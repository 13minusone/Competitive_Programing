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
typedef pair<ll,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 5e5 + 5;
//const ll MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
int n, q, k, cnt = 1, pos[N];
struct Data
{
    int x, y, id, cur;
    Data(int _x = 0, int _y = 0, int _id = 0, int _cur = 0)
    {
        x = _x;
        y = _y;
        id = _id;
        cur = _cur;
    }
};
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
vector<Data>vec;
vector<ii>st[4 * N];
int query[N];
void add(int u, int v, ii val, int id = 1, int l = 1, int r = q)
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
void DnC(int id = 1, int l = 1, int r = q, int sz = 0)
{
    for(ii i : st[id])tree.join(i.fi, i.se);
    if(l == r)
    {
        if(query[l])
        cout << tree.getSize(query[l]) << endl;
    }
    int mid = (l+r) >> 1;
    if(l < r)DnC(id << 1, l, mid, tree.getST());
    if(l < r)DnC(id << 1|1, mid + 1, r, tree.getST());
    tree.rollback(sz);
}
void init(void)
{
    cin >> n >> q >> k;
}
void process(void)
{
    tree.init(n);
    FOR(i,1,q)
    {
        register int type, x, y;
        cin >> type;
        if(type == 1){
            cin >> x >> y;
            vec.pb(Data(x, y, i, cnt));
        }
        else if(type == 2){
            cin >> x;
            query[i] = x;
        }
        else pos[cnt++] = i;
    }
    pos[cnt] = q;
    for(Data i : vec){
        //cout << i.id << " " << pos[min(cnt, i.cur + k - 1)] << endl;
        add(i.id,pos[min(cnt, i.cur + k - 1)], ii(i.x, i.y));
    }
    DnC();
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
