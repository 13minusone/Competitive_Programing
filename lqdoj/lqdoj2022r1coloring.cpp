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

const int N = 6e5 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

int n, cnt = 0, par[N], color[N], head, Index, Now[N];
bool ind[N];
ii minn[N];
vector<int>edge[N];
set <int>vec[N];;
int dfs(int u, int pre)
{
    minn[u] = ii(u, 2 * N);
    vec[u].insert(u);
    for(int v : edge[u])if(v != pre)
    {
        int ans = dfs(v,u);
        if(minn[u].fi > ans)
        {
            minn[u].se = minn[u].fi;
            minn[u].fi = ans;
        }
        else minimize(minn[u].se, ans);
        par[v] = u;
        vec[u].insert(minn[v].fi);
    }
    return minn[u].fi;
}
struct Data
{
    ii ans;
    int pos;
    Data(ii a = ii(0,0), int _pos = 0)
    {
        ans = a;
        pos = _pos;
    }
};
Data st[4 * N];
void upd(ii val, int pos, int id = 1, int l = 1, int r = n)
{
    if(l > pos || r < pos)return;
    if(l == r){
        st[id] = Data(val, pos);
        return;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid)upd(val, pos, id << 1, l, mid);
    else upd(val, pos, id << 1|1, mid + 1, r);
    if(st[id << 1].ans < st[id << 1|1].ans)st[id] = st[id << 1];
    else st[id] = st[id << 1|1];
}
void build(int id = 1, int l = 1, int r = n)
{
     if(l == r){
        st[id] = Data(minn[l], l);
        //cout << st[id].ans.fi << " " << st[id].ans.se << " " << l << endl;
        return;
    }
    int mid = (l+r) >> 1;
    build(id << 1, l, mid);
    build(id << 1|1, mid + 1, r);
    if(st[id << 1].ans < st[id << 1|1].ans)st[id] = st[id << 1];
    else st[id] = st[id << 1|1];
}
void change(int u)
{
    if(!ind[u] != 0)
    {
        auto it = vec[u].begin();
        int old = *it, val;
        vec[u].erase(old);
        it = vec[u].begin();
        int neww = *it;
        ++it;
        minn[u] = ii(neww,*it);
        upd(minn[u], u);
        u = par[u];
         while(!ind[u])
        {
            vec[u].erase(old);
            vec[u].insert(neww);
            it = vec[u].begin();
            val = *it;
            it++;
            minn[u] = ii(val,*it);
            upd(minn[u], u);
            u = par[u];
        }
    }
    else return;
}
void cut(int u)
{
    if(u == 2 * N)return;
    ii mx = ii(2 * N,2 * N);
    ii node = ii(2  * N,2*N);
    minn[u] = ii(2 * N, 2 * N);
    upd(minn[u], u);
    color[u] = cnt;
    ind[u] = 1;
    for(int v : edge[u]){
        if(v != par[u] && !ind[v])
            if(mx.fi > minn[v].fi)
            {
                mx.se = mx.fi;
                node.se = node.fi;
                mx.fi = minn[v].fi;
                node.fi = v;
            }
            else if(minimize(mx.se, minn[v].fi))node.se = v;
    }
    if(head != u)node.se = mx.se = 2 * N;
   // cout << u <<" " << head <<  " " << node.fi << " " << node.se << " " << cnt << endl;
    if(node.fi != 2 * N){
        ind[node.fi] = 1;
        cut(node.fi);
    }
    if(node.se != 2 * N){
        ind[node.se] = 1;
        cut(node.se);
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
        cin >> n;
        REP(i,1,n)
        {
            register int x, y;
            cin >> x >> y;
            edge[x].pb(y);
            edge[y].pb(x);
        }
        dfs(1,1);
        memset(ind,0,sizeof ind);
        build();
      // cout << st[1].pos << endl;
        cnt++;
        ind[1] = 1;
        head = 1;
        cut(1);
        FOR(i,1,n)
        {
            if(!ind[i])
            vec[i].insert(N + i);
            vec[i].insert(N + i);
        }
        while(st[1].ans != ii(2 * N, 2 * N)){
                Index = st[1].pos;
               // cout << Index << endl;
                //cout << i << endl;
                change(par[Index]);
                ++cnt;
                ind[Index] = 1;
                head = Index;
                cut(Index);
        }
        FOR(i,1,n)cout << color[i] << ' ';
    }
}
