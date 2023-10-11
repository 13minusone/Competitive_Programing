// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "akarui"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define endl '\n'
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

const int N = 1e5 + 5;
const ll mod =1e9+7;
//const ll base = 311;
//const int bl = 488;

int n, p[N], x, sta[N],fin[N], cnt = 0, root, ans[N];
vector<int>edge[N];
int st[4*N];
void dfs(int u)
{
    sta[u] = ++cnt;
    for(int v : edge[u])
        dfs(v);
    fin[u] = cnt;
}
void upd(int pos, int val, int id = 1, int l = 1, int r = n)
{
    if(l == r)
    {
        st[id] += val;
        if(st[id] >= mod)st[id] -= mod;
        return;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid)upd(pos, val, id << 1, l, mid);
    else upd(pos, val, id << 1|1, mid + 1, r);
    st[id] = st[id << 1] + st[id << 1|1];
    if(st[id] >= mod)st[id] -= mod;
}
int get(int u, int v, int id = 1, int l = 1, int r= n)
{
    if(l > v || r < u || l > r || u > v)return 0;
    if(l >= u && r <= v)return st[id];
    int mid = (l+r) >> 1, ans;
    ans = (get(u, v, id << 1, l, mid) + get(u ,v, id << 1|1, mid + 1, r));
    if(ans >= mod) ans-= mod;
    return ans;
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
    cin >> n;
    FOR(i,1,n){
        cin >> p[i];
        if(p[i] == 0)root =  i;
        else edge[p[i]].pb(i);
    }
    dfs(root);
    //build();
    FOR(i,1,n)
    {
        cin >> x;
        ll val =  1  + get(sta[x], fin[x]) ;
        ans[x] = val;
        if(x != root)upd(sta[p[x]], val);
    }
    FOR(i,1,n)cout << ans[i] << " " ;
}
